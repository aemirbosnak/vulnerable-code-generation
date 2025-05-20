//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <smtp_server_address> <smtp_server_port> <from_email_address> [to_email_address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);
    char *from_address = argv[3];
    char *to_address = (argc >= 5) ? argv[4] : from_address;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Error: failed to connect to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server greeting");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send HELO command
    char helo_command[BUFFER_SIZE];
    sprintf(helo_command, "HELO %s\r\n", server_address);
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        perror("Error: failed to send HELO command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response to HELO command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server response to HELO command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", from_address);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("Error: failed to send MAIL FROM command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response to MAIL FROM command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server response to MAIL FROM command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send RCPT TO command
    char rcpt_to_command[BUFFER_SIZE];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", to_address);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("Error: failed to send RCPT TO command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response to RCPT TO command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server response to RCPT TO command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send DATA command
    char data_command[BUFFER_SIZE];
    sprintf(data_command, "DATA\r\n");
    if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
        perror("Error: failed to send DATA command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response to DATA command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server response to DATA command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send email content
    char email[BUFFER_SIZE];
    printf("Enter email content. Press Ctrl-D to finish:\n");
    fgets(email, BUFFER_SIZE, stdin);
    if (send(sockfd, email, strlen(email), 0) == -1) {
        perror("Error: failed to send email content");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Send QUIT command
    char quit_command[BUFFER_SIZE];
    sprintf(quit_command, "QUIT\r\n");
    if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
        perror("Error: failed to send QUIT command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response to QUIT command
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: failed to receive server response to QUIT command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}