//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80

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
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        printf("Error converting server IP to network byte order\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char request[100] = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (1) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(sock);

    double download_speed = (double)bytes_received / (double)BUFFER_SIZE;
    printf("Download speed: %.2f kB/s\n", download_speed / 1024);

    return 0;
}