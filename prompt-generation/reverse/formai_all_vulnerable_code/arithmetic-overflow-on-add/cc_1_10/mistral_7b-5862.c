//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_IP "192.168.1.1" // Replace with the server IP address
#define SERVER_PORT 4321
#define BUFFER_SIZE 1024
#define TIMEOUT 5

typedef struct {
    char name[32];
    int size;
} FileFragment;

void print_progress(int received, int total) {
    float progress = (float)received / total * 100.0;
    printf("\r[------------------------------------------------>] %2.2f%%", progress);
    fflush(stdout);
}

int main(void) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    int total_size = 10 * 1024 * 1024; // 10 MB
    int received = 0;
    int i;
    FileFragment fragments[10];

    // Initialize fragments with random names and sizes
    for (i = 0; i < 10; i++) {
        snprintf(fragments[i].name, sizeof(fragments[i].name), "Fragment %d", i + 1);
        fragments[i].size = rand() % (total_size / 10 + 1) * 10;
        received += fragments[i].size;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < 10; i++) {
        send(sockfd, fragments[i].name, strlen(fragments[i].name), 0);

        if (send(sockfd, &fragments[i].size, sizeof(int), 0) < 0) {
            perror("send");
            close(sockfd);
            return 1;
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n < 0) {
            perror("recv");
            close(sockfd);
            return 1;
        }

        print_progress(received, total_size);
    }

    gettimeofday(&end, NULL);
    long long elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    float mb_per_sec = (float)received / elapsed_ms / (1024 * 1024);

    printf("\nYour internet speed is %.2f MB/s\n", mb_per_sec);

    close(sockfd);
    return 0;
}