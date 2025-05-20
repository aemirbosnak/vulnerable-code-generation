//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 25
#define MAX_MESSAGE_LENGTH 1024

int main() {
    char server_name[] = "smtp.example.com";
    char message[MAX_MESSAGE_LENGTH];
    char from_address[] = "sender@example.com";
    char to_address[] = "recipient@example.com";
    char subject[] = "Test Email";
    char body[] = "This is a test email sent using the SMTP protocol.";
    
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // Get server info
    struct hostent* server = gethostbyname(server_name);
    if (server == NULL) {
        perror("Error getting server info");
        exit(1);
    }
    
    // Set server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    
    // Connect to server
    if (connect(sock, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // Receive server banner
    char buffer[MAX_MESSAGE_LENGTH];
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server banner");
        exit(1);
    }
    
    // Send EHLO command
    sprintf(message, "EHLO %s\r\n", server_name);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error sending EHLO command");
        exit(1);
    }
    
    // Receive server response
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server response to EHLO command");
        exit(1);
    }
    
    // Send MAIL FROM command
    sprintf(message, "MAIL FROM: <%s>\r\n", from_address);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    
    // Receive server response
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server response to MAIL FROM command");
        exit(1);
    }
    
    // Send RCPT TO command
    sprintf(message, "RCPT TO: <%s>\r\n", to_address);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    
    // Receive server response
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server response to RCPT TO command");
        exit(1);
    }
    
    // Send DATA command
    sprintf(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }
    
    // Receive server response
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server response to DATA command");
        exit(1);
    }
    
    // Send message headers and body
    sprintf(message, "From: <%s>\r\n", from_address);
    send(sock, message, strlen(message), 0);
    sprintf(message, "To: <%s>\r\n", to_address);
    send(sock, message, strlen(message), 0);
    sprintf(message, "Subject: %s\r\n", subject);
    send(sock, message, strlen(message), 0);
    sprintf(message, "\r\n%s\r\n.\r\n", body);
    send(sock, message, strlen(message), 0);
    
    // Receive server response
    if (recv(sock, buffer, MAX_MESSAGE_LENGTH, 0) < 0) {
        perror("Error receiving server response to message");
        exit(1);
    }
    
    // Send QUIT command
    sprintf(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }
    
    // Close connection
    close(sock);
    
    return 0;
}