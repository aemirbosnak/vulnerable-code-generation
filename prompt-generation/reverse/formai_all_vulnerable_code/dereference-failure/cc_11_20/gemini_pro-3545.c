//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *server_address = "pop.example.com";
    int server_port = 110;
    char *username = "username";
    char *password = "password";

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server address
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the USER command
    char buffer[1024];
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the USER response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Check the USER response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the PASS response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Check the PASS response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the LIST command
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the LIST response
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s\n", buffer);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}