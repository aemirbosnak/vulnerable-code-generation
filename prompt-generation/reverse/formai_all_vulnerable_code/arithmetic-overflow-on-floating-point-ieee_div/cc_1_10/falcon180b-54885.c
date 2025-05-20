//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double total_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));
    while (1) {
        if ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) <= 0) {
            break;
        }
    }
    end_time = difftime(time(NULL), time(NULL));
    total_time = end_time - start_time;
    speed = (double)bytes_received / total_time;

    printf("Speed: %.2lf bytes/second\n", speed);

    close(sock);
    return 0;
}