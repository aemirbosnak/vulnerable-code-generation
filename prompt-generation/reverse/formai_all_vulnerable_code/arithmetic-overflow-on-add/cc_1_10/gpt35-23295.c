//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define HTTP_PORT 80

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char request[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(HTTP_PORT);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Send failed\n");
        return -1;
    }

    int bytes_read = 0, total_bytes_read = 0;
    memset(response, 0, sizeof(response));

    while ((bytes_read = recv(sock, response + total_bytes_read, MAX_BUFFER_SIZE - total_bytes_read, 0)) > 0) {
        total_bytes_read += bytes_read;
    }

    printf("%s\n", response);

    return 0;
}