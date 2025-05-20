//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char* cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf(">> %s", cmd);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int read_size = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[read_size] = '\0';
    printf("<< %s", buffer);
}

void smtp_client(const char* server, const char* from_email, const char* to_email, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Defining server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    read_response(sockfd); // Read server response

    // Hello command
    send_command(sockfd, "EHLO localhost\r\n");
    read_response(sockfd);

    // Authenticate using plaintext login
    send_command(sockfd, "AUTH LOGIN\r\n");
    read_response(sockfd);
    
    // Encode username and password in Base64
    char* user_base64 = "dXNlcm5hbWU="; // Just an example Base64 encoded string for "username"
    char* pass_base64 = "cGFzc3dvcmQ="; // Just an example Base64 encoded string for "password"
    
    send_command(sockfd, user_base64);
    send_command(sockfd, "\r\n");
    read_response(sockfd);
    
    send_command(sockfd, pass_base64);
    send_command(sockfd, "\r\n");
    read_response(sockfd);

    // Mail from
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM: <%s>\r\n", from_email);
    send_command(sockfd, mail_from_cmd);
    read_response(sockfd);

    // Rcpt to
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO: <%s>\r\n", to_email);
    send_command(sockfd, rcpt_to_cmd);
    read_response(sockfd);

    // Data command
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);

    // Email headers and body
    char data[BUFFER_SIZE];
    snprintf(data, sizeof(data),
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", subject, from_email, to_email, body);
    
    send_command(sockfd, data);
    read_response(sockfd);

    // Quit
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);

    // Closing socket
    close(sockfd);
}

int main() {
    const char* smtp_server = "smtp.example.com"; // Example SMTP server
    const char* from_email = "your_email@example.com";
    const char* to_email = "recipient@example.com";
    const char* email_subject = "Hello from SMTP Client";
    const char* email_body = "This is a test email sent from a C SMTP client.";

    smtp_client(smtp_server, from_email, to_email, email_subject, email_body);

    return 0;
}