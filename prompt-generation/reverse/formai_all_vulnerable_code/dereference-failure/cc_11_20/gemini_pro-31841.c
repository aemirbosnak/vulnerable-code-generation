//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    // Check if the user provided enough arguments
    if (argc < 4) {
        printf("Usage: %s <recipient> <sender> <message>\n", argv[0]);
        return 1;
    }

    // Get the recipient, sender, and message from the command line arguments
    char *recipient = argv[1];
    char *sender = argv[2];
    char *message = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 2;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 3;
    }

    // Send the HELO command
    char helo_command[100];
    sprintf(helo_command, "HELO %s\r\n", "example.com");
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        perror("send");
        return 4;
    }

    // Receive the server's response
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 5;
    }

    // Send the MAIL FROM command
    char mail_from_command[100];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("send");
        return 6;
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 7;
    }

    // Send the RCPT TO command
    char rcpt_to_command[100];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("send");
        return 8;
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 9;
    }

    // Send the DATA command
    char data_command[] = "DATA\r\n";
    if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
        perror("send");
        return 10;
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 11;
    }

    // Send the message
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return 12;
    }

    // Send the .\r\n to indicate the end of the message
    char dot_crlf[] = ".\r\n";
    if (send(sockfd, dot_crlf, strlen(dot_crlf), 0) == -1) {
        perror("send");
        return 13;
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 14;
    }

    // Send the QUIT command
    char quit_command[] = "QUIT\r\n";
    if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
        perror("send");
        return 15;
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 16;
    }

    // Close the socket
    close(sockfd);

    return 0;
}