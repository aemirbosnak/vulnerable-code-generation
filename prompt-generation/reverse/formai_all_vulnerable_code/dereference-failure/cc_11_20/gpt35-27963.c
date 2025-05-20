//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    struct hostent *host;
    char buffer[1024];
    char *from_address = "sender@example.com";
    char *to_address = "recipient@example.com";
    char *message = "Subject: Hello World!\n\nThis is a test email.\n";
    int message_len = strlen(message);

    printf("Initializing SMTP client...\n");

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Resolve server hostname
    host = gethostbyname("mail.example.com");
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    // Set server information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read server greeting
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server greeting");
        exit(1);
    }
    printf("Server greeting: %s", buffer);

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", host->h_name);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending HELO command");
        exit(1);
    }
    printf("Sent HELO command: %s", buffer);

    // Read server response
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server response");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from_address);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    printf("Sent MAIL FROM command: %s", buffer);

    // Read server response
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server response");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to_address);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    printf("Sent RCPT TO command: %s", buffer);

    // Read server response
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server response");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }
    printf("Sent DATA command: %s", buffer);

    // Read server response
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server response");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send message body
    if (send(sock, message, message_len, 0) < 0) {
        perror("Error sending message body");
        exit(1);
    }
    printf("Sent message body: %s", message);

    // Send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }
    printf("Sent QUIT command: %s", buffer);

    // Read server response
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("Error reading server response");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Close socket
    close(sock);

    printf("Email sent successfully!\n");

    return 0;
}