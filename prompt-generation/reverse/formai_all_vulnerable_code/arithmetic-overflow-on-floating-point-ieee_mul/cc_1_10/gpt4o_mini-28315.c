//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_COUNT 3
#define TEST_DURATION 5

typedef struct {
    char* address;
    int port;
} ServerInfo;

ServerInfo servers[SERVER_COUNT] = {
    {"127.0.0.1", PORT},
    {"127.0.0.1", PORT + 1},
    {"127.0.0.1", PORT + 2}
};

float measure_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    time_t start_time, end_time;

    time(&start_time);
    while (1) {
        int n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) break;
        bytes_received += n;
    }
    time(&end_time);

    float duration = difftime(end_time, start_time);
    return (bytes_received * 8) / (duration * 1000); // Speed in kbps
}

float measure_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with data to send
    time_t start_time, end_time;
    int bytes_sent = 0;

    time(&start_time);
    for (int i = 0; i < TEST_DURATION * 100; i++) { // Send dummy data
        bytes_sent += send(sockfd, buffer, BUFFER_SIZE, 0);
    }
    time(&end_time);

    float duration = difftime(end_time, start_time);
    return (bytes_sent * 8) / (duration * 1000); // Speed in kbps
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    for (int i = 0; i < SERVER_COUNT; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            return -1;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(servers[i].port);
        inet_pton(AF_INET, servers[i].address, &server_addr.sin_addr);

        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection to the server failed");
            close(sockfd);
            continue;
        }

        printf("Connected to server: %s:%d\n", servers[i].address, servers[i].port);

        float download_speed = measure_download_speed(sockfd);
        printf("Download Speed: %.2f kbps\n", download_speed);

        float upload_speed = measure_upload_speed(sockfd);
        printf("Upload Speed: %.2f kbps\n", upload_speed);

        close(sockfd);
    }

    return 0;
}