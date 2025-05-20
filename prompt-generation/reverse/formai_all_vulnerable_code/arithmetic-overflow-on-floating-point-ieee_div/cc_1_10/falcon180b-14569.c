//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 10
#define TIMEOUT 5

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double total_time;
    double download_speed;
    int attempts = 0;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(2);
    }

    while (attempts < MAX_ATTEMPTS) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            attempts++;
            continue;
        }

        total_time = (double)bytes_received / (double)BUFFER_SIZE;
        download_speed = total_time / ((double)BUFFER_SIZE / (double)attempts);

        printf("Download speed: %.2f kbps\n", download_speed);
        attempts++;

        if (download_speed >= 1000) {
            break;
        }
    }

    close(sockfd);

    return 0;
}