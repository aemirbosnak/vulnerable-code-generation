//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define PACKET_SIZE 1024
#define TIME_INTERVAL 5

volatile sig_atomic_t stop;

void handle_sigint(int signum) {
    stop = 1;
}

void print_summary(int total_packets, int lost_packets, double latency) {
    printf("\n---- Network QoS Summary ----\n");
    printf("Total Packets Sent: %d\n", total_packets);
    printf("Total Packets Lost: %d\n", lost_packets);
    printf("Average Latency: %.2f ms\n", latency / (total_packets - lost_packets));
    printf("------------------------------\n");
}

int main() {
    struct sockaddr_in server_addr;
    char packet[PACKET_SIZE];
    int total_packets = 0, lost_packets = 0;
    struct timeval start, end;
    double latency_sum = 0.0;

    signal(SIGINT, handle_sigint); // Capture SIGINT to clean up before exit

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listening on all available interfaces
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening for QoS packets on port %d...\n", PORT);

    while (!stop) {
        int n;
        socklen_t len = sizeof(server_addr);

        n = recvfrom(sockfd, packet, PACKET_SIZE, MSG_WAITALL, (struct sockaddr *)&server_addr, &len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        
        gettimeofday(&end, NULL);
        gettimeofday(&start, NULL);
        
        total_packets++;
        latency_sum += (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; 

        // Simulated lost packet condition
        if (rand() % 10 < 2) {
            lost_packets++;
            printf("Packet lost! Total packets: %d, Lost packets: %d\n", total_packets, lost_packets);
            continue;
        }
        
        printf("Received packet of size %d bytes.\n", n);
        usleep(TIME_INTERVAL * 1000000); // Sleep for TIME_INTERVAL
    }

    print_summary(total_packets, lost_packets, latency_sum);

    close(sockfd);
    return 0;
}