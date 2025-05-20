//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to send HTTP request
void send_request(int sock, char *method, char *path) {
    char request[BUFFER_SIZE];
    sprintf(request, "%s %s HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", method, path);

    send(sock, request, strlen(request), 0);
}

// Function to receive HTTP response
void receive_response(int sock, char *response) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        strncat(response, buffer, bytes_received);
    }

    response[bytes_received] = '\0';
}

// Function to print HTTP response
void print_response(char *response) {
    printf("HTTP/1.1 %d %s\r\n", atoi(response), response + 9);

    char *content_length = strstr(response, "Content-Length:");
    if (content_length!= NULL) {
        printf("Content-Length: %s\r\n", content_length + 15);
    }

    printf("\r\n");
    printf("%s", response + (atoi(response) == 200? 13 : 45));
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char response[BUFFER_SIZE];

    send_request(sock, "GET", "/");
    receive_response(sock, response);
    print_response(response);

    close(sock);

    return 0;
}