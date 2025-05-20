//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 1048576 // 1 MB buffer
#define SERVER_IP "127.0.0.1" // replace with the server IP
#define SERVER_PORT 8080 // replace with the server port

void colorful_print(const char *msg, const char *color) {
    printf("%s%s\033[0m\n", color, msg);
}

double download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    long bytes_received = 0;
    time_t start_time = time(NULL);

    while (1) {
        ssize_t bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;
        bytes_received += bytes;
    }

    time_t end_time = time(NULL);
    double seconds = difftime(end_time, start_time);
    return (bytes_received * 8.0) / (seconds * 1024 * 1024); // speed in Mbps
}

double upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE); // fill buffer with dummy data
    long bytes_sent = 0;
    time_t start_time = time(NULL);

    while (bytes_sent < BUFFER_SIZE) {
        ssize_t bytes = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;
        bytes_sent += bytes;
    }

    time_t end_time = time(NULL);
    double seconds = difftime(end_time, start_time);
    return (bytes_sent * 8.0) / (seconds * 1024 * 1024); // speed in Mbps
}

int main() {
    colorful_print("Welcome to the Mind-Bending Internet Speed Test!", "\033[1;35m");
    colorful_print("Your connection is about to be measured 🌀", "\033[1;32m");

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        colorful_print("Error creating socket!", "\033[1;31m");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        colorful_print("Error connecting to the server!", "\033[1;31m");
        close(sockfd);
        return 1;
    }

    colorful_print("Testing download speed... 🌐", "\033[1;34m");
    double download_mbps = download_speed(sockfd);
    printf("Download Speed: %.2f Mbps\n", download_mbps);

    colorful_print("Testing upload speed... 📤", "\033[1;34m");
    double upload_mbps = upload_speed(sockfd);
    printf("Upload Speed: %.2f Mbps\n", upload_mbps);

    close(sockfd);

    colorful_print("Test Complete! 🎉", "\033[1;35m");
    colorful_print("Results may vary based on cosmic alignment. Enjoy your day!", "\033[1;32m");

    return 0;
}