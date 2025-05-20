//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_len = 0;
    double start_time = 0, end_time = 0;
    double elapsed_time = 0;
    double speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    while (data_len < MAX_DATA_SIZE) {
        int bytes_received = recv(sock, data + data_len, MAX_DATA_SIZE - data_len, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        data_len += bytes_received;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)data_len / elapsed_time;

    printf("Download speed: %.2f kB/s\n", speed / 1024);

    close(sock);

    return 0;
}