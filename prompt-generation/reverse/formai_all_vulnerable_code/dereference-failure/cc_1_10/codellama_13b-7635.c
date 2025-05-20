//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
// smtp_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define SMTP_SERVER "smtp.example.com"
#define SMTP_HELO "example.com"
#define SMTP_FROM "user@example.com"
#define SMTP_TO "recipient@example.com"
#define SMTP_SUBJECT "Test Email"
#define SMTP_BODY "This is a test email."

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Setup address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SMTP_SERVER);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send the HELO command
    char helo_cmd[256];
    sprintf(helo_cmd, "HELO %s\r\n", SMTP_HELO);
    send(sock, helo_cmd, strlen(helo_cmd), 0);

    // Send the MAIL FROM command
    char from_cmd[256];
    sprintf(from_cmd, "MAIL FROM: <%s>\r\n", SMTP_FROM);
    send(sock, from_cmd, strlen(from_cmd), 0);

    // Send the RCPT TO command
    char to_cmd[256];
    sprintf(to_cmd, "RCPT TO: <%s>\r\n", SMTP_TO);
    send(sock, to_cmd, strlen(to_cmd), 0);

    // Send the DATA command
    char data_cmd[256];
    sprintf(data_cmd, "DATA\r\n");
    send(sock, data_cmd, strlen(data_cmd), 0);

    // Send the email body
    char body[256];
    sprintf(body, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", SMTP_FROM, SMTP_TO, SMTP_SUBJECT, SMTP_BODY);
    send(sock, body, strlen(body), 0);

    // Send the QUIT command
    char quit_cmd[256];
    sprintf(quit_cmd, "QUIT\r\n");
    send(sock, quit_cmd, strlen(quit_cmd), 0);

    // Close the socket
    close(sock);

    return 0;
}