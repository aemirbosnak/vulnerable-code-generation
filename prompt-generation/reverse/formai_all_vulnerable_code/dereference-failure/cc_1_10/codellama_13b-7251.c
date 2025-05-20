//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
// Building a SMTP Client in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Function to connect to the SMTP server
int connect_smtp(char *host, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = inet_addr(host)
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    return sock;
}

// Function to send a message using the SMTP server
int send_message(int sock, char *from, char *to, char *subject, char *message) {
    char buffer[1024];
    sprintf(buffer, "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: %s\r\n\r\n", subject);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "%s\r\n", message);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, ".\r\n");
    send(sock, buffer, strlen(buffer), 0);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s host port from to subject message\n", argv[0]);
        return 1;
    }

    int sock = connect_smtp(argv[1], atoi(argv[2]));
    if (sock < 0) {
        return 1;
    }

    send_message(sock, argv[3], argv[4], argv[5], argv[6]);

    close(sock);
    return 0;
}