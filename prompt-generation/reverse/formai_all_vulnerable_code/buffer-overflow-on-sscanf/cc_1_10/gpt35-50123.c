//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

// function to send HTTP request and retrieve response
void http_get(const char *url) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    // parse URL into hostname and path
    char hostname[1000], path[1000];
    sscanf(url, "http://%[^/]/%s", hostname, path);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr*) host->h_addr_list[0]);

    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // send HTTP GET request
    char request[1000];
    sprintf(request, "GET /%s HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: close\r\n\r\n",
                      path, hostname);

    if (send(sock_fd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // retrieve HTTP response
    char buffer[1000];
    int num_bytes = 0;
    while ((num_bytes = recv(sock_fd, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }

    if (num_bytes < 0) {
        perror("recv");
        exit(1);
    }

    close(sock_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    http_get(argv[1]);

    return 0;
}