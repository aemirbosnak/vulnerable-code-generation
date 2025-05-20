//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("send_command: Error sending command");
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("read_response: Error reading response");
    }
    buffer[n] = '\0'; // null-terminate the string
    printf("%s", buffer);
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    // Convert domain name to IP address
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        error("Invalid address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection Failed");
    }

    // Read server response
    read_response(sockfd);
    send_command(sockfd, "EHLO localhost\r\n");
    read_response(sockfd);
    
    // Auth
    send_command(sockfd, "AUTH LOGIN\r\n");
    read_response(sockfd);
    
    // Base64 encode username and password
    send_command(sockfd, "dXNlcm5hbWU=\r\n"); // replace with base64 encoded username
    read_response(sockfd);
    send_command(sockfd, "cGFzc3dvcmQ=\r\n"); // replace with base64 encoded password
    read_response(sockfd);
    
    send_command(sockfd, "MAIL FROM:<");
    send_command(sockfd, from);
    send_command(sockfd, ">\r\n");
    read_response(sockfd);

    send_command(sockfd, "RCPT TO:<");
    send_command(sockfd, to);
    send_command(sockfd, ">\r\n");
    read_response(sockfd);

    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);

    // Send email headers and body
    char email_data[BUFFER_SIZE];
    snprintf(email_data, sizeof(email_data),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send_command(sockfd, email_data);
    read_response(sockfd);
    
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <SMTP Server> <From Email> <To Email> <Subject> <Body>\n", argv[0]);
        return 1;
    }

    const char *smtp_server = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];
    const char *body = argv[5];

    send_email(smtp_server, from, to, subject, body);
    return 0;
}