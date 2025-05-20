//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT "110"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address of the POP3 server.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *result;
    if (getaddrinfo(argv[1], POP3_PORT, &hints, &result) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    // Create a socket and connect to the POP3 server.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) != 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(result);

    // Send the USER command.
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
    if (send(sockfd, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the USER command.
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Send the PASS command.
    snprintf(buffer, sizeof(buffer), "PASS password\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the PASS command.
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Send the LIST command.
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the LIST command.
    int num_messages;
    if (sscanf(buffer, "+OK %d messages\r\n", &num_messages) != 1) {
        fprintf(stderr, "Invalid response to LIST command.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= num_messages; i++) {
        // Receive the size of the message.
        if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        int size;
        if (sscanf(buffer, "%d\r\n", &size) != 1) {
            fprintf(stderr, "Invalid response to LIST command.\n");
            exit(EXIT_FAILURE);
        }

        // Receive the message.
        char *message = malloc(size + 1);
        if (recv(sockfd, message, size, 0) <= 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        message[size] = '\0';

        // Print the message.
        printf("Message %d:\n%s\n", i, message);

        // Free the memory allocated for the message.
        free(message);
    }

    // Send the QUIT command.
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}