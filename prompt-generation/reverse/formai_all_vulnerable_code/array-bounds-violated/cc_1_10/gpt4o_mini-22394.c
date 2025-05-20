//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com" // Replace with your SMTP server
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    printf("🎉 Welcome to the Cheery SMTP Client! 🎉\n");
    
    // Step 1: Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Step 2: Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, "YOUR_SMTP_SERVER_IP", &server_addr.sin_addr);

    // Step 3: Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }
    printf("🌟 Connected to SMTP server! 🌟\n");

    // Step 4: Read server response
    read_response(sockfd);

    // Step 5: Send HELO command
    send_command(sockfd, "HELO localhost\r\n");
    read_response(sockfd);

    // Step 6: Start TLS
    send_command(sockfd, "STARTTLS\r\n");
    read_response(sockfd);

    // Normally, you'd handle the TLS handshake here
    // For simplicity, we're skipping actual TLS implementation

    // Step 7: Send MAIL FROM command
    send_command(sockfd, "MAIL FROM:<your_email@example.com>\r\n");
    read_response(sockfd);

    // Step 8: Send RCPT TO command
    send_command(sockfd, "RCPT TO:<recipient@example.com>\r\n");
    read_response(sockfd);

    // Step 9: Send DATA command
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);

    // Step 10: Send email content
    const char *email_body = 
        "Subject: Hello from Cheery SMTP Client!\r\n"
        "From: your_email@example.com\r\n"
        "To: recipient@example.com\r\n"
        "\r\n"
        "🎊 Hello! This is a test email sent with love from a cheerful SMTP client! 🎊\r\n"
        ".\r\n"; // End of the data

    send_command(sockfd, email_body);
    read_response(sockfd);

    // Step 11: Send QUIT command
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);

    // Clean up
    close(sockfd);
    printf("🎈 Email sent successfully! Have a wonderful day! 🎈\n");

    return EXIT_SUCCESS;
}