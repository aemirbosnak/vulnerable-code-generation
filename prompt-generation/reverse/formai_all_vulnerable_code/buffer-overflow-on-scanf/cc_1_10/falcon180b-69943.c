//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX 100
#define PORT 8080
#define TIMEOUT 5

void ping(int sock, struct sockaddr_in server) {
    char buffer[MAX];
    int bytes_received;
    double start_time, end_time;

    start_time = clock();
    bytes_received = sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr *)&server, sizeof(server));
    if (bytes_received <= 0) {
        printf("Error sending data\n");
        exit(1);
    }

    bytes_received = recvfrom(sock, buffer, MAX, 0, NULL, NULL);
    if (bytes_received <= 0) {
        printf("No response from server\n");
        exit(1);
    }

    end_time = clock();
    printf("Round trip time: %lf ms\n", (end_time - start_time) / (double)CLOCKS_PER_SEC * 1000);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char host[MAX];

    printf("Enter hostname or IP address: ");
    scanf("%s", host);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server.sin_addr);

    ping(sock, server);

    close(sock);
    return 0;
}