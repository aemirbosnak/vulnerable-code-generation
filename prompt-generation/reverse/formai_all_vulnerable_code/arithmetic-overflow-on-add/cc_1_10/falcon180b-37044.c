//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 8080

void send_request(int sock) {
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    send(sock, request, strlen(request), 0);
}

void receive_response(int sock, char* buffer, int max_size) {
    memset(buffer, 0, max_size);
    int bytes_received = 0;
    while (bytes_received < max_size) {
        int result = recv(sock, buffer + bytes_received, max_size - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }
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
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 2;
    }

    char buffer[1024];
    send_request(sock);
    receive_response(sock, buffer, sizeof(buffer));

    close(sock);

    printf("Response:\n%s", buffer);

    return 0;
}