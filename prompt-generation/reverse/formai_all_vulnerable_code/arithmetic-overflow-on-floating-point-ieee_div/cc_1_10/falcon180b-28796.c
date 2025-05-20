//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time;
    long int bytes_received;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    bytes_received = 0;

    while (1) {
        int bytes_read;

        bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            break;
        }

        bytes_received += bytes_read;
    }

    end_time = time(NULL);

    double speed = (double)bytes_received / (end_time - start_time);

    printf("Internet speed: %.2f KB/s\n", speed);

    close(sockfd);

    return 0;
}