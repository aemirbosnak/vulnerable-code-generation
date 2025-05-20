#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void echo_client(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t n;

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, payload_length, clilen;
    struct sockaddr_in server_addr, client_addr;
    char message[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: ./chat_tool <IP_ADDRESS>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    while (1) {
        printf("> ");
        gets(message);
        payload_length = strlen(message);
        write(sockfd, message, payload_length);
        echo_client(sockfd);
    }

    close(sockfd);
    return 0;
}
