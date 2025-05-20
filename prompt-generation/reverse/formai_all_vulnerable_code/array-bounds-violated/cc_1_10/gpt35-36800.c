//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int create_socket(const char *host, const char *port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_request(int sockfd, const char *path, const char *host, const char *port) {
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", path, host, port);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

void receive_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int recv_bytes;

    while ((recv_bytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        buffer[recv_bytes] = '\0';
        printf("%s", buffer);
    }

    if (recv_bytes < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char*argv[]) {
    if (argc != 4) {
        printf("Usage: %s HOST PORT PATH\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = create_socket(argv[1], argv[2]);
    send_request(sockfd, argv[3], argv[1], argv[2]);
    receive_response(sockfd);

    close(sockfd);
    exit(EXIT_SUCCESS);
}