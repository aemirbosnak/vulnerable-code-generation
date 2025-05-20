//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 80
#define SERVER_IP "127.0.0.1"

static int g_conn_fd;

static void sigint_handler(int signum) {
    if (g_conn_fd > 0) {
        close(g_conn_fd);
        g_conn_fd = -1;
    }
    exit(0);
}

static void cleanup(void) {
    if (g_conn_fd > 0) {
        close(g_conn_fd);
        g_conn_fd = -1;
    }
}

static int create_socket(void) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(fd);
        return -1;
    }
    return fd;
}

static int send_request(int fd) {
    const char* request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n";
    int len = strlen(request);
    int ret = send(fd, request, len, 0);
    if (ret < 0) {
        perror("send");
        return -1;
    }
    return ret;
}

static int receive_response(int fd) {
    char buf[512];
    int total_len = 0;
    while (1) {
        int len = recv(fd, buf, sizeof(buf), 0);
        if (len < 0) {
            perror("recv");
            return -1;
        } else if (len == 0) {
            break;
        }
        total_len += len;
    }
    return total_len;
}

int main(void) {
    atexit(cleanup);
    signal(SIGINT, sigint_handler);

    g_conn_fd = create_socket();
    if (g_conn_fd < 0) {
        return 1;
    }

    int ret = send_request(g_conn_fd);
    if (ret < 0) {
        goto out;
    }

    ret = receive_response(g_conn_fd);
    if (ret < 0) {
        goto out;
    }

    printf("Received %d bytes from the server\n", ret);

    close(g_conn_fd);
    g_conn_fd = -1;

    return 0;

out:
    close(g_conn_fd);
    g_conn_fd = -1;
    return 1;
}