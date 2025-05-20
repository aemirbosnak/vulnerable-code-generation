//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void send_request(int sock) {
    char request[100] = "GET /speedtest HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    send_request(sock);

    char buffer[1024];
    int bytes_received = 0;
    time_t start_time = time(NULL);

    while (bytes_received < 100) {
        int result = recv(sock, buffer + bytes_received, 1024 - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(sock);

    double speed = (double)bytes_received / (time(NULL) - start_time);
    printf("Internet speed: %.2f KB/s\n", speed);

    return 0;
}