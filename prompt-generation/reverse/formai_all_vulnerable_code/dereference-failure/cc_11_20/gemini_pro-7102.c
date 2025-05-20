//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SMTP_PORT "25"
#define MAX_LINE_LENGTH 512

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *sender = argv[1];
    char *recipient = argv[2];
    char *message = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the server address
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(SMTP_PORT));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Get the greeting from the server
    char buffer[MAX_LINE_LENGTH];
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    sprintf(buffer, "HELO localhost\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the server response
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the server response
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the server response
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the server response
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the message
    sprintf(buffer, "%s\r\n.\r\n", message);
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the server response
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}