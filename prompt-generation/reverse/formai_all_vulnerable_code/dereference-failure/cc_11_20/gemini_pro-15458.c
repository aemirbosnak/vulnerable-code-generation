//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT "110"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and username from the command line arguments.
    char *hostname = argv[1];
    char *username = argv[2];

    // Create a socket for communicating with the POP3 server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the POP3 server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the POP3 server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(POP3_PORT));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the POP3 server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command to the POP3 server.
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the PASS command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "PASS ********\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the STAT command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the LIST command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the RETR command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "RETR 1\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the DELE command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "DELE 1\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Send the QUIT command to the POP3 server.
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the POP3 server.
    printf("%s", buffer);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}