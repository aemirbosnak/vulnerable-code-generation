//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 25
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <from> <to> [message]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char *message = argc > 4 ? argv[4] : "Hello, World!";

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, "smtp", &hints, &res) != 0) {
        printf("Error: Unable to resolve host %s\n", host);
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) != 0) {
        printf("Error: Unable to connect to %s\n", host);
        return 1;
    }

    char buffer[MAX_BUFFER];
    sprintf(buffer, "HELO %s\r\n", host);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "%s\r\n", message);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, ".\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("Server: %s\n", buffer);

    close(sock);
    return 0;
}