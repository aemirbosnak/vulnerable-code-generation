//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX 1000000 // 1 MB
#define SERVER "speedtest.net"
#define PORT 80

int main(void) {
    int sock = 0;
    struct sockaddr_in server;
    char *host = SERVER;
    char buffer[MAX];
    long bytes_received = 0;
    clock_t start, end;
    double cpu_time_used;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket failed\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    start = clock();

    while (bytes_received < MAX) {
        int len = recv(sock, buffer + bytes_received, MAX - bytes_received, 0);
        if (len <= 0) {
            break;
        }
        bytes_received += len;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Received %ld bytes in %lf seconds\n", bytes_received, cpu_time_used);

    close(sock);
    return 0;
}