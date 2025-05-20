//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    struct hostent *host;
    int sockfd;
    char *hostname = "speedtest.net";
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    gettimeofday(&start_time, NULL);

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        elapsed_time = (double)difftime(end_time, start_time);
        speed = (double)bytes_received / elapsed_time;

        printf("Current speed: %.2lf KB/s\n", speed);
    }

    close(sockfd);

    return 0;
}