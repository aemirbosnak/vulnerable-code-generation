//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, bytes_sent, bytes_received = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, elapsed_time;
    int max_speed = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    start_time = clock();
    while (bytes_received < BUFFER_SIZE) {
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE - bytes_received, 0);
        if (bytes_sent == -1) {
            printf("Error sending data.\n");
            exit(1);
        }
        bytes_received += bytes_sent;
    }

    close(sockfd);

    end_time = clock();
    elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Maximum speed: %.2f Mbps\n", (BUFFER_SIZE * 8) / elapsed_time);

    return 0;
}