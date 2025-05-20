//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    int bytes;

    // Send the command
    send(sockfd, command, strlen(command), 0);
    
    // Receive response
    bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes < 0) {
        error_handling("recv() error");
    }
    
    buffer[bytes] = '\0';
    printf("%s", buffer);
}

void connect_smtp_server(int sockfd, const char *server) {
    char command[BUFFER_SIZE];

    sprintf(command, "HELO %s\r\n", server);
    send_command(sockfd, command);
}

void send_email(int sockfd, const char *from, const char *to, const char *message) {
    char command[BUFFER_SIZE];

    sprintf(command, "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);

    sprintf(command, "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);

    send_command(sockfd, "DATA\r\n");
    
    sprintf(command, "%s\r\n.\r\n", message);
    send_command(sockfd, command);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <smtp-server> <from-email> <to-email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("socket() error");
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("connect() error");
    }

    // Receive server greeting
    int bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes < 0) {
        error_handling("recv() error");
    }

    buffer[bytes] = '\0';
    printf("Server: %s", buffer);

    // Send HELO command
    connect_smtp_server(sockfd, "localhost");

    // Send email
    char *email_message = "Subject: Test Email\r\n\r\nThis is a test email sent from SMTP Client.";
    send_email(sockfd, from_email, to_email, email_message);
    
    // Send QUIT command
    send_command(sockfd, "QUIT\r\n");

    // Close socket
    close(sockfd);

    return 0;
}