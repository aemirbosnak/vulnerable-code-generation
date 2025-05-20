//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
/* This is a brave style C program to test internet speed */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"
#define BUFFER_SIZE 1024
#define PACKET_SIZE 1024
#define NUM_PACKETS 10
#define TIME_INTERVAL 1

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;
    long int total_bytes = 0;
    long int bytes_received = 0;
    double speed = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    start_time = time(NULL);
    for (int i = 0; i < NUM_PACKETS; i++) {
        memset(buffer, 'A', PACKET_SIZE);
        n = send(sockfd, buffer, PACKET_SIZE, 0);
        if (n == -1) {
            printf("Error sending packet\n");
            exit(1);
        }
        total_bytes += PACKET_SIZE;
    }
    end_time = time(NULL);

    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes / elapsed_time;

    printf("Internet speed: %.2f kbps\n", speed);

    close(sockfd);

    return 0;
}