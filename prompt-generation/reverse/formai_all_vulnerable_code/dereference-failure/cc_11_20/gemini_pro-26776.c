//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 587

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the server's address
    struct hostent *host = gethostbyname("mail.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    char buffer[1024];
    sprintf(buffer, "HELO %s\r\n", getenv("HOSTNAME"));
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[2]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the message
    if (send(sockfd, argv[3], strlen(argv[3]), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the CR/LF
    if (send(sockfd, "\r\n", strlen("\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}