//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract server and port information
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address structure
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(server);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command
    char *user = "USER username\r\n";
    if (send(sockfd, user, strlen(user), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server response
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the server response is OK
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    char *pass = "PASS password\r\n";
    if (send(sockfd, pass, strlen(pass), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the server response is OK
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the STAT command
    char *stat = "STAT\r\n";
    if (send(sockfd, stat, strlen(stat), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the server response is OK
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Extract the number of messages and the total size of the messages
    int num_messages, total_size;
    sscanf(buffer, "+OK %d %d\r\n", &num_messages, &total_size);

    // Print the number of messages and the total size of the messages
    printf("Number of messages: %d\n", num_messages);
    printf("Total size of messages: %d bytes\n", total_size);

    // Send the QUIT command
    char *quit = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    if (close(sockfd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}