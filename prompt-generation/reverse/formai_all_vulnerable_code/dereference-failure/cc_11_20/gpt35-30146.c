//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char** argv) {

    // Check argument count
    if (argc < 3) {
        printf("Usage: %s <server_ip_addr> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Socket file descriptor
    int sockfd;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Server socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Read greeting message
    char buffer[MAX_BUFFER];
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive greeting message");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send HELO command
    char helo_command[MAX_BUFFER];
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
        perror("Failed to send HELO command");
        exit(EXIT_FAILURE);
    }

    // Read response
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    char mail_from_command[MAX_BUFFER];
    printf("From: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", buffer);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        exit(EXIT_FAILURE);
    }

    // Read response
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send RCPT TO command
    char rcpt_to_command[MAX_BUFFER];
    printf("To: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", buffer);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("Failed to send RCPT TO command");
        exit(EXIT_FAILURE);
    }

    // Read response
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send DATA command
    char data_command[MAX_BUFFER] = "DATA\r\n";
    if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
        perror("Failed to send DATA command");
        exit(EXIT_FAILURE);
    }

    // Read response
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send message content
    printf("Enter message content. End with '.' on a new line\n");
    while (fgets(buffer, MAX_BUFFER, stdin)) {
        if (strcmp(buffer, ".\n") == 0) break;
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send message content");
            exit(EXIT_FAILURE);
        }
    }

    // Send QUIT command
    char quit_command[MAX_BUFFER] = "QUIT\r\n";
    if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
        perror("Failed to send QUIT command");
        exit(EXIT_FAILURE);
    }

    // Read response
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}