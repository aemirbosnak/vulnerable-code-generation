#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        close(sockfd);
        return 1;
    }

    const char *request = "GET / HTTP/1.1\r\nHost: ";
    send(sockfd, request, strlen(request), 0);
    send(sockfd, argv[1], strlen(argv[1]), 0);
    send(sockfd, "\r\nConnection: close\r\n\r\n", 23, 0);

    char buffer[BUFFER_SIZE];
    while ((read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[BUFFER_SIZE - 1] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
