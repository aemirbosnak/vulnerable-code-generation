//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <from_email_address> <to_email_address>\n", argv[0]);
        return 1;
    }
    char *from_email_address = argv[1];
    char *to_email_address = argv[2];
    char message[BUFFER_SIZE];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname() failed");
        exit(1);
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "HELO example.com\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "MAIL FROM:<%s>\r\n", from_email_address);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "RCPT TO:<%s>\r\n", to_email_address);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "Date: Fri, 07 Sep 2021 10:00:00 GMT\r\n");
    sprintf(message, "From: %s\r\n", from_email_address);
    sprintf(message, "To: %s\r\n", to_email_address);
    sprintf(message, "Subject: SMTP Client Test\r\n");
    sprintf(message, "\r\n");
    sprintf(message, "Hello World!\r\n");
    sprintf(message, ".\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    sprintf(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", message);
    close(sock);
    return 0;
}