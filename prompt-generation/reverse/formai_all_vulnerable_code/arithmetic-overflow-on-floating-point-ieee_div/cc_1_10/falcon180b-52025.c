//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
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

void send_request(int sock) {
    char request[100] = "GET /speedtest HTTP/1.1\r\nHost: ";
    strcat(request, SERVER);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    send(sock, request, strlen(request), 0);
}

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    double start_time = get_time();

    for (int i = 0; i < NUM_REQUESTS; i++) {
        send_request(sock);
    }

    double end_time = get_time();

    double total_time = end_time - start_time;
    double speed = NUM_REQUESTS / total_time;

    printf("Internet speed: %.2f requests/second\n", speed);

    close(sock);

    return 0;
}