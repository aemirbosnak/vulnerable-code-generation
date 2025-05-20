//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>

#define HTTP_PORT 80
#define MAX_RESPONSE_SIZE 8192

typedef struct {
    char *data;
    size_t size;
} http_response_t;

int create_socket(const char *host) {
    struct addrinfo hints, *addr_list, *addr;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, "http", &hints, &addr_list) != 0) {
        fprintf(stderr, "Error: Could not resolve hostname %s.\n", host);
        return -1;
    }

    sockfd = -1;
    for (addr = addr_list; addr != NULL; addr = addr->ai_next) {
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, addr->ai_addr, addr->ai_addrlen) == -1) {
            close(sockfd);
            sockfd = -1;
            continue;
        }

        break;
    }

    freeaddrinfo(addr_list);

    return sockfd;
}

void parse_url(const char *url, char *host, char *path, uint16_t *port) {
    const char *start;
    bool has_port, has_path;
    size_t host_len = 0, path_len = 0;

    memset(host, 0, sizeof host);
    memset(path, 0, sizeof path);
    *port = HTTP_PORT;

    if (strncmp(url, "http://", strlen("http://")) == 0) {
        start = url + strlen("http://");
    } else {
        start = url;
    }

    has_port = strchr(start, ':') != NULL;
    has_path = strchr(start, '/') != NULL;

    if (has_port && has_path) {
        host_len = strcspn(start, ":");
        path_len = strcspn(start + host_len, "/");
        strncpy(host, start, host_len);
        strncpy(path, start + host_len + 1, path_len);
        *port = atoi(start + host_len + 1 + path_len + 1);
    } else if (has_port) {
        host_len = strcspn(start, ":");
        strncpy(host, start, host_len);
        *port = atoi(start + host_len + 1);
    } else if (has_path) {
        host_len = strcspn(start, "/");
        strncpy(host, start, host_len);
        strcpy(path, start + host_len);
    } else {
        strcpy(host, start);
    }

    if (path_len == 0) {
        strcpy(path, "/");
    }
}

void http_request(const char *url, const char *method, http_response_t *response) {
    char host[512], path[1024];
    uint16_t port = HTTP_PORT;
    int sockfd;
    struct sockaddr_in sa;
    char request[1024];
    ssize_t sent_len, read_len, response_len;
    char *p;
    fd_set read_set;
    struct timeval tv;
    int rv, maxfd;

    parse_url(url, host, path, &port);

    sockfd = create_socket(host);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket.\n");
        return;
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, host, &sa.sin_addr);

    sprintf(request, "%s %s HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: close\r\n"
                      "\r\n",
            method, path, host);

    sent_len = send(sockfd, request, strlen(request), 0);
    if (sent_len == -1) {
        fprintf(stderr, "Failed to send request.\n");
        close(sockfd);
        return;
    }

    response->data = malloc(MAX_RESPONSE_SIZE);
    response->size = 0;

    maxfd = sockfd + 1;
    FD_ZERO(&read_set);
    FD_SET(sockfd, &read_set);

    while (true) {
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        rv = select(maxfd, &read_set, NULL, NULL, &tv);
        if (rv == -1 && errno != EINTR) {
            fprintf(stderr, "Error: select(): %s.\n", strerror(errno));
            break;
        } else if (rv == 0) {
            fprintf(stderr, "Timed out waiting for response.\n");
            break;
        }

        if (FD_ISSET(sockfd, &read_set)) {
            response_len = recv(sockfd, response->data + response->size, MAX_RESPONSE_SIZE - response->size - 1, 0);
            if (response_len == -1) {
                fprintf(stderr, "Error: recv(): %s.\n", strerror(errno));
                break;
            }

            if (response_len == 0) {
                break;
            }

            response->size += response_len;
            response->data[response->size] = '\0';

            p = strstr(response->data, "\r\n\r\n");
            if (p != NULL) {
                break;
            }
        }
    }

    close(sockfd);
}

void print_response(const http_response_t *response) {
    printf("%s\n", response->data);
}

int main(int argc, char **argv) {
    char *url = "http://example.com";
    http_response_t response;

    http_request(url, "GET", &response);
    print_response(&response);

    free(response.data);

    return 0;
}