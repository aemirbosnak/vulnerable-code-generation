//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10

void send_request(int sock);
double get_speed(struct timeval start, struct timeval end);

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < NUM_REQUESTS; i++) {
        send_request(sock);
    }

    gettimeofday(&end_time, NULL);

    double speed = get_speed(start_time, end_time);
    printf("Internet Speed: %.2f Mbps\n", speed);

    close(sock);
    return 0;
}

void send_request(int sock) {
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);

    send(sock, request, strlen(request), 0);
}

double get_speed(struct timeval start, struct timeval end) {
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = NUM_REQUESTS * BUFFER_SIZE / elapsed_time;
    return speed;
}