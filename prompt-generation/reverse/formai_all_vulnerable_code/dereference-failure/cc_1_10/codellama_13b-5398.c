//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
/*
 * SMTP Client example program
 * Build using C
 * By Ken Thompson
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_MSG_SIZE 10240

void build_smtp_request(char *msg, char *recipient, char *sender) {
    char *request = "HELO localhost\r\n";
    request = strcat(request, "MAIL FROM: <");
    request = strcat(request, sender);
    request = strcat(request, ">\r\n");
    request = strcat(request, "RCPT TO: <");
    request = strcat(request, recipient);
    request = strcat(request, ">\r\n");
    request = strcat(request, "DATA\r\n");
    request = strcat(request, msg);
    request = strcat(request, "\r\n.\r\n");
    request = strcat(request, "QUIT\r\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <sender> <recipient>\n", argv[0]);
        return 1;
    }

    char *sender = argv[1];
    char *recipient = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char *msg = "This is a test message";
    char request[MAX_MSG_SIZE];
    build_smtp_request(msg, recipient, sender);

    if (write(sock, request, strlen(request)) < 0) {
        perror("Error sending request");
        return 1;
    }

    char response[BUF_SIZE];
    if (read(sock, response, BUF_SIZE) < 0) {
        perror("Error reading response");
        return 1;
    }

    printf("Response: %s\n", response);

    close(sock);
    return 0;
}