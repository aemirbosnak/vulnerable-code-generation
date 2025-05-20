//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = clock();
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    end_time = clock();

    elapsed_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    speed = bytes_received / elapsed_time;

    printf("\nSpeed test complete!\n");
    printf("Elapsed time: %lf seconds\n", elapsed_time);
    printf("Speed: %lf bytes/second\n", speed);

    close(sockfd);
    return 0;
}