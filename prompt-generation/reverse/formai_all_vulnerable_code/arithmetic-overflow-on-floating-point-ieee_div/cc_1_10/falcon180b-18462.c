//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "speedtest.net";
    char *server_port = "80";
    char buffer[BUF_SIZE];
    int bytes_received;
    clock_t start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(server_port));
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    start_time = clock();
    while ((bytes_received = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        if (fwrite(buffer, 1, bytes_received, stdout)!= bytes_received) {
            printf("Error: Failed to write to stdout\n");
            exit(1);
        }
    }
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    speed = (double)bytes_received / elapsed_time;

    printf("Internet speed: %.2f bytes/sec\n", speed);

    close(sockfd);
    return 0;
}