//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

void send_request(int sock) {
    char request[] = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
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
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send_request(sock);

    int bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (bytes_received >= 0)) {
        bytes_received += recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }

    close(sock);

    double speed = (double)bytes_received / ((double)BUFFER_SIZE / 1024);

    printf("Download speed: %.2f kB/s\n", speed);

    return 0;
}