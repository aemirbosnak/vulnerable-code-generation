//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host = url;
    char *path = strchr(url, '/');
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: Could not resolve host '%s'\n", host);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    char *request = malloc(BUFFER_SIZE);
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request\n");
        return 1;
    }

    char *response = malloc(BUFFER_SIZE);
    ssize_t total = 0;
    size_t buflen = BUFFER_SIZE;
    ssize_t recvd;
    while ((recvd = recv(sockfd, response + total, BUFFER_SIZE, 0)) > 0) {
        total += recvd;
        if (total >= buflen - BUFFER_SIZE) {
            buflen *= 2;
            response = realloc(response, buflen);
            if (response == NULL) {
                printf("Error: Out of memory\n");
                return 1;
            }
        }
    }

    if (recvd < 0) {
        printf("Error: Could not receive response\n");
        return 1;
    }

    printf("%.*s\n", (int) total, response);

    free(request);
    free(response);
    close(sockfd);

    return 0;
}