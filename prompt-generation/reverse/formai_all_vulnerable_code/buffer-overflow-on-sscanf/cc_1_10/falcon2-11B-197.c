//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

void handle_request(int sockfd, struct sockaddr_in client_addr, char *request_line, char *host, int port, char *path) {
    // handle the request
    printf("Request line: %s\n", request_line);
    printf("Host: %s\n", host);
    printf("Port: %d\n", port);
    printf("Path: %s\n", path);
    // your code here
}

int main() {
    int sockfd, client_fd, chars_read;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFSIZ];
    char host[BUFSIZ], port[BUFSIZ], path[BUFSIZ];
    char request_line[BUFSIZ];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        client_fd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&chars_read);
        if (client_fd < 0) {
            printf("Error accepting client connection\n");
            exit(1);
        }

        bzero(buffer, BUFSIZ);
        chars_read = recv(client_fd, buffer, BUFSIZ, 0);
        if (chars_read < 0) {
            printf("Error reading from client\n");
            exit(1);
        }

        strcpy(request_line, buffer);
        sscanf(request_line, "%s %s %d %s", host, path, &port, request_line);
        handle_request(client_fd, client_addr, request_line, host, port, path);

        printf("Closing client connection\n");
        close(client_fd);
    }

    return 0;
}