//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    char buffer[1024];
    send(sock, "GET / HTTP/1.1\r\nHost: speedtest.net\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\n\r\n"), 0);

    int bytes_received = 0;
    int total_bytes_received = 0;
    double start_time = 0, end_time = 0;
    struct timeval start, end;

    while (1) {
        bytes_received = recv(sock, buffer + total_bytes_received, 1024 - total_bytes_received, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    close(sock);

    gettimeofday(&start, NULL);
    for (int i = 0; i < total_bytes_received; i++) {
        if (buffer[i] == '\n') {
            end_time = (double) (start.tv_sec + start.tv_usec / 1000000.0);
            break;
        }
    }

    printf("Internet speed: %.2lf bytes/second\n", ((double) total_bytes_received / (end_time - start_time)));

    return 0;
}