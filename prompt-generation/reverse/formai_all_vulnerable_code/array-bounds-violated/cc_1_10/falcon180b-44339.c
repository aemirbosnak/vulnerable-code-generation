//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void send_request(int sock) {
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n");
    send(sock, request, strlen(request), 0);
}

void receive_response(int sock) {
    char response[10000];
    memset(response, 0, sizeof(response));
    int bytes_received = 0;
    while ((bytes_received = recv(sock, response + bytes_received, sizeof(response) - bytes_received, 0)) > 0) {
        response[bytes_received] = '\0';
    }
    printf("Response: %s\n", response);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, "www.google.com", &server_addr.sin_addr) <= 0) {
        printf("Error resolving hostname\n");
        return 2;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 3;
    }

    send_request(sock);
    receive_response(sock);

    close(sock);
    return 0;
}