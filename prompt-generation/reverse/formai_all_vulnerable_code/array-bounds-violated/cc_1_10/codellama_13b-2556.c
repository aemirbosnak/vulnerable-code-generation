//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: careful
// smtp_client.c

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // fill in server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // connect to server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // send HELO command
    send(sock, "HELO localhost\r\n", strlen("HELO localhost\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send MAIL FROM command
    send(sock, "MAIL FROM:<user@example.com>\r\n", strlen("MAIL FROM:<user@example.com>\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send RCPT TO command
    send(sock, "RCPT TO:<user@example.com>\r\n", strlen("RCPT TO:<user@example.com>\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send DATA command
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send email message
    send(sock, "From: user@example.com\r\n", strlen("From: user@example.com\r\n"), 0);
    send(sock, "To: user@example.com\r\n", strlen("To: user@example.com\r\n"), 0);
    send(sock, "Subject: Hello from C\r\n", strlen("Subject: Hello from C\r\n"), 0);
    send(sock, "Hello, this is a test message from C\r\n", strlen("Hello, this is a test message from C\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // receive and print server response
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // close socket
    close(sock);

    return 0;
}