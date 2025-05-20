//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

// Function to send email
int send_email(int sock, char *to, char *subject, char *body) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: %s\r\n", subject);
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "Content-Type: text/plain\r\n\r\n");
    send(sock, buffer, strlen(buffer), 0);
    send(sock, body, strlen(body), 0);
    sprintf(buffer, ".\r\n");
    send(sock, buffer, strlen(buffer), 0);
    return 0;
}

// Function to receive response from server
int receive_response(int sock) {
    char buffer[BUF_SIZE];
    int len = 0;
    while ((len = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        buffer[len] = '\0';
        printf("%s", buffer);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email sent using SMTP client.";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.example.com", &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send email
    send_email(sock, to, subject, body);

    // Receive response
    receive_response(sock);

    // Close socket
    close(sock);

    return 0;
}