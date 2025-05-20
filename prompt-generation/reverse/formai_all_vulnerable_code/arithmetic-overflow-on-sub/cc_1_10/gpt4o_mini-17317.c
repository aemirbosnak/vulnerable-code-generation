//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void start_server() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;
    ssize_t bytes_received;
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d\n", PORT);

    addr_len = sizeof(client_addr);
    while (1) {
        // Receive a request from the client
        bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            continue;
        }

        printf("Bytes received: %zd\n", bytes_received);
        buffer[0] = 's';  // Send start command to client
        sendto(sockfd, buffer, 1, 0, (const struct sockaddr *)&client_addr, addr_len);
        
        start_time = time(NULL);
        size_t total_bytes = 0;
        
        // Send data to the client
        while (time(NULL) - start_time < 10) { // Send for 10 seconds
            sendto(sockfd, buffer, BUFFER_SIZE, 0, (const struct sockaddr *)&client_addr, addr_len);
            total_bytes += BUFFER_SIZE;
        }

        end_time = time(NULL);
        double speed_mbps = (total_bytes * 8.0) / (end_time - start_time) / 1e6; // Mbps
        printf("Download speed: %.2f Mbps\n", speed_mbps);
    }

    close(sockfd);
}

int main() {
    start_server();
    return 0;
}