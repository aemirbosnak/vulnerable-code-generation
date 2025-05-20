//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void send_request(int sock) {
    char request[100] = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    send_request(sock);

    char buffer[1024];
    int bytes_received = 0;

    while (bytes_received < 1024) {
        int result = recv(sock, buffer + bytes_received, 1024 - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(sock);

    long response_time = time(NULL) - (long)buffer;

    printf("Internet Speed Test\n");
    printf("Server: %s\n", SERVER_IP);
    printf("Response Time: %ld ms\n", response_time);
    printf("Download Speed: %ld bytes/s\n", bytes_received / response_time);

    return 0;
}