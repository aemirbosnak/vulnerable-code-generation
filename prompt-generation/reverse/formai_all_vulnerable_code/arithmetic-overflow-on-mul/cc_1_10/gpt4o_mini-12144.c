//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define TEST_DURATION 10

void print_progress_bar(int progress, int total) {
    int bars = (progress * 50) / total; // Scale progress to 50 character bar
    printf("\r[");
    for(int i = 0; i < 50; i++) {
        if(i < bars)
            printf("=");
        else
            printf(" ");
    }
    printf("] %.2f%%", (float)progress / total * 100);
    fflush(stdout);
}

void speed_test(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_sent, bytes_received;
    long total_bytes_received = 0;
    time_t start_time, end_time;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        return;
    }

    printf("Starting speed test...\n");
    start_time = time(NULL);

    while (1) {
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            perror("Send failed");
            close(sockfd);
            return;
        }

        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            close(sockfd);
            return;
        }
        total_bytes_received += bytes_received;

        end_time = time(NULL);
        if (difftime(end_time, start_time) >= TEST_DURATION) {
            break;
        }
        print_progress_bar(total_bytes_received, 10 * BUFFER_SIZE); // Scale for the progress bar
    }

    close(sockfd);
    printf("\nSpeed Test Complete.\n");
    double speed_mbps = (total_bytes_received * 8.0) / (1024.0 * 1024.0) / TEST_DURATION;
    printf("Received %ld bytes in %d seconds.\n", total_bytes_received, TEST_DURATION);
    printf("Your internet speed: %.2f Mbps\n", speed_mbps);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    speed_test(argv[1]);
    return 0;
}