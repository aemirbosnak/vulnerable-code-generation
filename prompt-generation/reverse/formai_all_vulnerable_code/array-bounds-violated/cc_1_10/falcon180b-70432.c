//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void send_request(int sock) {
    char request[MAX_SIZE];
    sprintf(request, "GET /speedtest.php HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    send(sock, request, strlen(request), 0);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char response[MAX_SIZE];
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(2);
    }

    send_request(sock);

    bytes_received = recv(sock, response, MAX_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response from server\n");
        exit(3);
    }

    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}