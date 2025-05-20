//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <math.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 8080

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    time_t start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    start_time = time(NULL);

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes_received / elapsed_time;

    printf("Internet speed: %.2f bytes/second\n", speed);

    close(sockfd);
    return 0;
}