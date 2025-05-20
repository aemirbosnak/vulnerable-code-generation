//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
// SMTP client example program in a ultraprecise style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Look up the IP address of the server
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Initialize the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr_list[0]))->s_addr;

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the EHLO command
    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <user@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the email message
    sprintf(buffer, "From: user@example.com\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: recipient@example.com\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: SMTP Client Example\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "This is a test email message.\r\n");
    send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}