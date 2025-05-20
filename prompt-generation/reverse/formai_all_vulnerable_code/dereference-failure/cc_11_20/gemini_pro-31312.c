//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

#define SERVER_PORT 143
#define USER "myusername"
#define PASS "mypassword"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int bytes_received;
    char *host = "imap.example.com";
    struct hostent *host_info;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the host information
    host_info = gethostbyname(host);
    if (!host_info) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the greeting
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the login command
    sprintf(buffer, "LOGIN %s %s\r\n", USER, PASS);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the login response
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the login was successful
    if (strncmp(buffer, "OK", 2) != 0) {
        printf("Login failed: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the list command
    sprintf(buffer, "LIST \"\" *\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the list response
    while (true) {
        bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        if (strncmp(buffer, "*", 1) == 0) {
            break;
        }

        printf("%s", buffer);
    }

    // Send the logout command
    sprintf(buffer, "LOGOUT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}