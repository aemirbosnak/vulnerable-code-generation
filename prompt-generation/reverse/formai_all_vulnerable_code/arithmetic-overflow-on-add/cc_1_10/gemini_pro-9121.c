//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define URL "www.google.com"
#define PORT 80
#define BUFSIZE 1024

// Calculate elapsed time in milliseconds
long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

// Perform a HTTP GET request and measure the response time
long test_speed(const char *host) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    long start, end;
    char buf[BUFSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }

    start = get_time_ms();
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    write(sockfd, buf, strlen(buf));
    while ((n = read(sockfd, buf, BUFSIZE)) > 0) {
        ;
    }
    end = get_time_ms();

    close(sockfd);
    return end - start;
}

int main() {
    long speed;

    printf("Testing internet speed to %s...\n", URL);
    speed = test_speed(URL);
    if (speed < 0) {
        printf("Error: Unable to measure internet speed.\n");
    } else {
        printf("Speed: %ld ms\n", speed);
    }

    return 0;
}