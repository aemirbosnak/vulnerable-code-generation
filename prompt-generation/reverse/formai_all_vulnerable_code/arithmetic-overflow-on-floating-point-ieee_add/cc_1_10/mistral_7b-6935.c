//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_ADDRESS "8.8.8.8"
#define SERVER_PORT 53
#define BUFFER_SIZE 1024
#define TEST_COUNT 3
#define TIMEOUT 1000

void print_connection_insights(double download_speed, double upload_speed) {
    if (download_speed > 10) {
        printf("Your connection is faster than a cheetah!\n");
    } else if (download_speed > 5) {
        printf("Your connection is as fast as a gazelle!\n");
    } else {
        printf("Your connection is slower than a snail.\n");
    }

    if (upload_speed > 5) {
        printf("Your upload speed is decent.\n");
    } else {
        printf("Your upload speed is slower than a dial-up connection.\n");
    }
}

double measure_speed(int sockfd, char *server_address, int server_port) {
    struct sockaddr_in server_addr;
    struct timeval start, end;
    double elapsed, send_size, receive_size;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(server_port);

    socklen_t len = sizeof(struct sockaddr_in);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);

    sendto(sockfd, "abcdefghijklmnopqrstuvwxyz", 17, 0, (struct sockaddr *) &server_addr, len);

    recvfrom(sockfd, &receive_size, sizeof(receive_size), 0, NULL, NULL);

    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    close(sockfd);

    send_size = 17;

    return (receive_size / elapsed) / TEST_COUNT;
}

int main() {
    int sockfd;
    double download_speed, upload_speed;
    int i;

    for (i = 0; i < TEST_COUNT; ++i) {
        download_speed += measure_speed(sockfd, SERVER_ADDRESS, SERVER_PORT);
    }

    download_speed /= TEST_COUNT;

    for (i = 0; i < TEST_COUNT; ++i) {
        upload_speed += measure_speed(sockfd, SERVER_ADDRESS, SERVER_PORT);
    }

    upload_speed /= TEST_COUNT;

    printf("Downloading: %.2f Kbps\n", download_speed * 1024);
    printf("Uploading: %.2f Kbps\n", upload_speed * 1024);

    print_connection_insights(download_speed, upload_speed);

    return 0;
}