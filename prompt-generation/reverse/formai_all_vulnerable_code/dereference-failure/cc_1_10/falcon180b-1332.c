//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT "80"
#define SERVER_NAME "www.google.com"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int numbytes;
    int total_bytes = 0;
    int max_speed = 0;
    int curr_speed = 0;
    double speed = 0.0;
    struct timeval start, end;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(EAI_SYSTEM));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket failed");
            exit(1);
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect failed");
            exit(1);
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "No address associated with hostname\n");
        exit(1);
    }

    printf("Connected to %s:%s\n", SERVER_NAME, SERVER_PORT);

    gettimeofday(&start, NULL);

    while ((numbytes = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        total_bytes += numbytes;
        if (total_bytes > max_speed) {
            max_speed = total_bytes;
        }
    }

    gettimeofday(&end, NULL);

    speed = (double)total_bytes / (double)(end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0);
    curr_speed = (int)speed;

    printf("Total bytes received: %d\n", total_bytes);
    printf("Maximum speed: %d bytes/second\n", max_speed);
    printf("Current speed: %d bytes/second\n", curr_speed);

    close(sockfd);
    return 0;
}