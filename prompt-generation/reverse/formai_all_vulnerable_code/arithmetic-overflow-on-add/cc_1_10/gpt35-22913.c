//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 2048
#define TEST_REPEAT 5

int test_speed(struct sockaddr_in *addr) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed.");
        exit(1);
    }

    struct timeval start, end;
    int start_ms, end_ms;

    gettimeofday(&start, NULL);
    start_ms = start.tv_sec * 1000 + start.tv_usec / 1000;

    if (connect(sock, (struct sockaddr *) addr, sizeof(*addr)) < 0) {
        perror("Connection failed.");
        exit(1);
    }

    char buffer[BUFFER_SIZE] = "GET / HTTP/1.1\r\n\r\n";
    send(sock, buffer, BUFFER_SIZE, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    gettimeofday(&end, NULL);
    end_ms = end.tv_sec * 1000 + end.tv_usec / 1000;

    int speed = BUFFER_SIZE / (end_ms - start_ms);
    close(sock);
    return speed;
}

int main(int argc, char **argv) {
    char *hostname = "www.google.com";
    if (argc > 1) {
        hostname = argv[1];
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(hostname);

    printf("Testing speed for %s...\n", hostname);

    int total_speed = 0;
    for (int i = 0; i < TEST_REPEAT; ++i) {
        int speed = test_speed(&addr);
        printf("Speed #%d: %d bytes/ms\n", i + 1, speed);
        total_speed += speed;
        sleep(1);
    }
    printf("Average speed: %d bytes/ms\n", total_speed / TEST_REPEAT);
    return 0;
}