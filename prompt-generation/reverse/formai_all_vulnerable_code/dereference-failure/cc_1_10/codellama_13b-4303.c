//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 25
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *hostname = "smtp.example.com";
    char *message = "Hello, World!";
    char buffer[BUFSIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Fill in server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    host = gethostbyname(hostname);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send EHLO command
    send(sock, "EHLO example.com\r\n", strlen("EHLO example.com\r\n"), 0);

    // Send MAIL FROM command
    send(sock, "MAIL FROM:<user@example.com>\r\n", strlen("MAIL FROM:<user@example.com>\r\n"), 0);

    // Send RCPT TO command
    send(sock, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0);

    // Send DATA command
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send message
    send(sock, message, strlen(message), 0);

    // Send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Close socket
    close(sock);

    return 0;
}