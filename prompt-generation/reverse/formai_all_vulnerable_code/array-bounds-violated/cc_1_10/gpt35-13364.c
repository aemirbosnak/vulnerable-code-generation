//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;
    char *message;
    char buffer[MAX_BUFFER_SIZE] = {0};

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter message to send: ");

    if (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
        size_t message_len = strlen(buffer);

        if (buffer[message_len - 1] == '\n') {
            buffer[message_len - 1] = '\0';
        }

        if (send(sockfd, buffer, message_len, 0) == -1) {
            perror("Failed to send message");
            exit(EXIT_FAILURE);
        }

        printf("Message sent successfully!\n");

        if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
            perror("Failed to receive message");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}