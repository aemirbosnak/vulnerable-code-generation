//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
// POP3 Client Example Program in a Curious Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>

#define POP3_PORT 110
#define POP3_MAX_LINE 512
#define POP3_MAX_MSG 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buf[POP3_MAX_LINE];
    char msg[POP3_MAX_MSG];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the username
    printf("Username: %s\n", argv[2]);
    n = snprintf(buf, POP3_MAX_LINE, "USER %s\r\n", argv[2]);
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, POP3_MAX_LINE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("Server: %s\n", buf);

    // Send the password
    printf("Password: ");
    fgets(buf, POP3_MAX_LINE, stdin);
    n = snprintf(buf, POP3_MAX_LINE, "PASS %s\r\n", buf);
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, POP3_MAX_LINE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("Server: %s\n", buf);

    // Send the RETR command
    n = snprintf(buf, POP3_MAX_LINE, "RETR 1\r\n");
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, POP3_MAX_LINE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("Server: %s\n", buf);

    // Receive the message
    n = recv(sock, msg, POP3_MAX_MSG, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    msg[n] = '\0';
    printf("Message: %s\n", msg);

    // Send the DELE command
    n = snprintf(buf, POP3_MAX_LINE, "DELE 1\r\n");
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, POP3_MAX_LINE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("Server: %s\n", buf);

    // Send the QUIT command
    n = snprintf(buf, POP3_MAX_LINE, "QUIT\r\n");
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}