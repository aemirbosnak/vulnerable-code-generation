//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("Unable to parse address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Unable to connect to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    // Receive banner
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive banner");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send HELO
    char *helo = "HELO example.com\r\n";
    if (send(sockfd, helo, strlen(helo), 0) < 0) {
        perror("Unable to send HELO");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send MAIL FROM
    char *mail_from = "MAIL FROM:<example@example.com>\r\n";
    if (send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        perror("Unable to send MAIL FROM");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send RCPT TO
    char *rcpt_to = "RCPT TO:<example@example.com>\r\n";
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("Unable to send RCPT TO");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send DATA
    char *data = "DATA\r\n";
    if (send(sockfd, data, strlen(data), 0) < 0) {
        perror("Unable to send DATA");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send message
    char *message = "From: example@example.com\r\nTo: example@example.com\r\nSubject: Test\r\n\r\nThis is a test email message.\r\n.\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send QUIT
    char *quit = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("Unable to send QUIT");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive reply
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Unable to receive reply");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}