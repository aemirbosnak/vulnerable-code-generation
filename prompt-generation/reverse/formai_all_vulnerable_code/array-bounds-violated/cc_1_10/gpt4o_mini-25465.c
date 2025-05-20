//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
    printf("Sent: %s", cmd);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error reading response");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("Received: %s", buffer);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sockfd;

    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        error("Could not resolve hostname");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to SMTP server");
    }
    
    return sockfd;
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    // SMTP conversation
    read_response(sockfd);
    send_command(sockfd, "EHLO localhost\r\n");
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
    
    // Construct email data
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, email);
    read_response(sockfd);

    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *from_address = "sender@example.com";
    const char *to_address = "recipient@example.com";
    const char *email_subject = "Test Email from C SMTP Client";
    const char *email_body = "This is a test email sent from a simple C SMTP client.";

    int sockfd = create_socket(smtp_server);

    send_email(sockfd, from_address, to_address, email_subject, email_body);

    close(sockfd);
    return 0;
}