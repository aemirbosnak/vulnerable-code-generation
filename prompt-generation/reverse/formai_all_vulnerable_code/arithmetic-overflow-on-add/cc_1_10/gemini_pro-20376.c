//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <arpa/inet.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <poll.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

struct client_connection {
    int fd;
    bool is_connected;
    struct sockaddr_in addr;
};

struct server_connection {
    int fd;
    bool is_connected;
    struct sockaddr_in addr;
};

struct proxy_connection {
    struct client_connection client;
    struct server_connection server;
    bool is_tunneled;
};

static int create_socket(int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        err(1, "socket");
    }

    int optval = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) ==
        -1) {
        err(1, "setsockopt(SO_REUSEADDR)");
    }
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval)) ==
        -1) {
        err(1, "setsockopt(SO_REUSEPORT)");
    }
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval)) ==
        -1) {
        err(1, "setsockopt(TCP_NODELAY)");
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = INADDR_ANY,
        },
    };

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        err(1, "bind");
    }

    if (listen(fd, 1024) == -1) {
        err(1, "listen");
    }

    return fd;
}

static void accept_client(int fd, struct proxy_connection *proxy) {
    socklen_t addrlen = sizeof(proxy->client.addr);
    proxy->client.fd = accept(fd, (struct sockaddr *)&proxy->client.addr,
                               &addrlen);
    if (proxy->client.fd == -1) {
        err(1, "accept");
    }
    printf("Accepted client connection from %s:%d\n",
           inet_ntoa(proxy->client.addr.sin_addr),
           ntohs(proxy->client.addr.sin_port));
    proxy->client.is_connected = true;
}

static void connect_server(struct proxy_connection *proxy) {
    proxy->server.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy->server.fd == -1) {
        err(1, "socket");
    }

    if (connect(proxy->server.fd, (struct sockaddr *)&proxy->server.addr,
                sizeof(proxy->server.addr)) == -1) {
        err(1, "connect");
    }
    proxy->server.is_connected = true;
}

static void close_client(struct proxy_connection *proxy) {
    if (proxy->client.fd != -1) {
        close(proxy->client.fd);
        proxy->client.fd = -1;
    }
    proxy->client.is_connected = false;
}

static void close_server(struct proxy_connection *proxy) {
    if (proxy->server.fd != -1) {
        close(proxy->server.fd);
        proxy->server.fd = -1;
    }
    proxy->server.is_connected = false;
}

static void close_proxy(struct proxy_connection *proxy) {
    close_client(proxy);
    close_server(proxy);
}

static void forward_data(struct proxy_connection *proxy) {
    char buf[4096];
    int n;

    n = read(proxy->client.fd, buf, sizeof(buf));
    if (n < 0) {
        if (n == EINTR) {
            return;
        }
        err(1, "read");
    } else if (n == 0) {
        close_client(proxy);
        return;
    }

    if (proxy->is_tunneled) {
        write(proxy->server.fd, buf, n);
    } else if (strstr(buf, "\r\n\r\n")) {
        char *host, *port, *path;

        host = strstr(buf, "Host: ");
        if (host != NULL) {
            host += 6;
            port = strchr(host, ':');
            if (port != NULL) {
                *port++ = '\0';
                path = strchr(port, '/');
                if (path != NULL) {
                    *path++ = '\0';
                }
            }
        }

        struct addrinfo hints = {
            .ai_family = AF_INET,
            .ai_socktype = SOCK_STREAM,
        };
        struct addrinfo *result;

        if (getaddrinfo(host, port, &hints, &result) != 0) {
            errx(1, "getaddrinfo");
        }

        proxy->server.addr = *(struct sockaddr_in *)result->ai_addr;
        connect_server(proxy);

        write(proxy->server.fd, buf, n);
        proxy->is_tunneled = true;
    }
}

int main(int argc, char **argv) {
    int listen_fd = create_socket(5555);

    struct proxy_connection proxy = {
        .client.fd = -1,
        .client.is_connected = false,
        .server.fd = -1,
        .server.is_connected = false,
        .is_tunneled = false,
    };

    while (1) {
        int nfds = listen_fd + 1;
        struct pollfd fds[2] = {
            {
                .fd = listen_fd,
                .events = POLLIN,
            },
            {
                .fd = proxy.client.fd,
                .events = proxy.client.is_connected ? POLLIN : 0,
            },
        };

        if (poll(fds, nfds, -1) == -1) {
            err(1, "poll");
        }

        if (fds[0].revents & POLLIN) {
            accept_client(listen_fd, &proxy);
        }
        if (fds[1].revents & POLLIN) {
            forward_data(&proxy);
        }
    }

    return 0;
}