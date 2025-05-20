//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    close(sockfd);
    return 0;
}