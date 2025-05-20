//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    // Parse URL into host, path, and port
    char *host, *path;
    int port = DEFAULT_PORT;

    char *proto = strtok(url, ":");
    if (proto == NULL) {
        printf("Invalid URL\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(proto, "http") != 0) {
        printf("Only HTTP is supported\n");
        exit(EXIT_FAILURE);
    }

    char *host_and_path = strtok(NULL, "");
    if (host_and_path == NULL) {
        printf("Invalid URL\n");
        exit(EXIT_FAILURE);
    }

    char *colon_pos = strchr(host_and_path, ':');
    char *slash_pos = strchr(host_and_path, '/');

    if (colon_pos && (!slash_pos || colon_pos < slash_pos)) {
        *colon_pos = '\0';
        host = host_and_path;
        char *port_str = colon_pos + 1;
        if (!sscanf(port_str, "%d", &port) || port <= 0 || port > 65535) {
            printf("Invalid port number\n");
            exit(EXIT_FAILURE);
        }
    } else {
        host = host_and_path;
    }

    if (slash_pos) {
        path = slash_pos;
    } else {
        path = "/";
    }

    struct hostent *hp = gethostbyname(host);
    if (hp == NULL) {
        printf("Unknown host %s\n", host);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(struct sockaddr_in));
    sin.sin_family = AF_INET;
    sin.sin_addr = *((struct in_addr *) hp->h_addr);
    sin.sin_port = htons(port);

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(s, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

    if (send(s, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t n;
    while ((n = recv(s, buffer, sizeof(buffer), 0)) > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    close(s);

    return EXIT_SUCCESS;
}