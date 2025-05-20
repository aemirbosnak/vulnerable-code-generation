//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sock = 0;
    struct sockaddr_in server;
    char data[MAX_DATA_SIZE];
    char response[MAX_DATA_SIZE];
    int bytes_sent = 0;
    int bytes_received = 0;
    double start_time = 0, end_time = 0;
    double total_time = 0;
    double speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    start_time = clock();

    while (bytes_sent < MAX_DATA_SIZE) {
        send(sock, data, MAX_DATA_SIZE, 0);
        bytes_sent += MAX_DATA_SIZE;
    }

    close(sock);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    while (bytes_received < MAX_DATA_SIZE) {
        bzero(response, MAX_DATA_SIZE);
        bytes_received = recv(sock, response, MAX_DATA_SIZE, 0);
        if (bytes_received <= 0)
            break;
    }

    end_time = clock();
    total_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    speed = (double)bytes_received / total_time;

    printf("Speedtest result:\n");
    printf("Download speed: %.2f kbps\n", speed);

    close(sock);

    return 0;
}