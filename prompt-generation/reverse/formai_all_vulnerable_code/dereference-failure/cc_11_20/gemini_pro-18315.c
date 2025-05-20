//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    // Check for proper usage
    if (argc != 4) {
        printf("Usage: %s <server address> <port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    char *server_address = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buffer[1024];
    int n;
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", username);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the USER response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", "password");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the PASS response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the LIST command
    sprintf(buffer, "LIST\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LIST response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the RETR command
    sprintf(buffer, "RETR 1\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the RETR response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the QUIT response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}