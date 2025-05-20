//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char sendBuff[BUFFER_SIZE], recvBuff[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;
    int total_bytes_sent = 0, total_bytes_received = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);

    while (total_bytes_sent < BUFFER_SIZE) {
        send(sockfd, sendBuff, strlen(sendBuff), 0);
        total_bytes_sent += strlen(sendBuff);
        usleep(100000); // sleep for 100 microseconds
    }

    while (total_bytes_received < BUFFER_SIZE) {
        n = recv(sockfd, recvBuff, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        total_bytes_received += n;
        usleep(100000); // sleep for 100 microseconds
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Bytes sent: %d\n", total_bytes_sent);
    printf("Bytes received: %d\n", total_bytes_received);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    close(sockfd);
    return 0;
}