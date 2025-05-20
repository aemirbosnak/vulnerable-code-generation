//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *host;
    int port;
    char buffer[MAX_LINE];

    // Parse command line arguments
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <message>\n", argv[0]);
        return 1;
    }
    host = argv[1];
    port = atoi(argv[2]);
    char *message = argv[3];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    // Send HELO command
    send(sock, "HELO client\r\n", strlen("HELO client\r\n"), 0);

    // Send MAIL FROM command
    send(sock, "MAIL FROM:<client@example.com>\r\n", strlen("MAIL FROM:<client@example.com>\r\n"), 0);

    // Send RCPT TO command
    send(sock, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0);

    // Send DATA command
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send message
    send(sock, message, strlen(message), 0);

    // Send a dot to signal end of message
    send(sock, ".\r\n", strlen(".\r\n"), 0);

    // Receive response from server
    memset(buffer, 0, MAX_LINE);
    recv(sock, buffer, MAX_LINE, 0);
    printf("Response from server:\n%s", buffer);

    // Close socket
    close(sock);

    return 0;
}