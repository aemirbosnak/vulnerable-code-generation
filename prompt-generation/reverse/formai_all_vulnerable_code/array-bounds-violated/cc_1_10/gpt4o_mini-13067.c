//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_PACKETS 10

static int packet_loss_count = 0;
static int total_sent = 0;

void *ping_host(void *hostname) {
    char command[BUFFER_SIZE];
    sprintf(command, "ping -c 1 %s", (char *)hostname);
    
    FILE *fp;
    char result[BUFFER_SIZE];

    for (int i = 0; i < NUM_PACKETS; i++) {
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen failed");
            exit(EXIT_FAILURE);
        }

        // Read the output of the ping command
        fgets(result, sizeof(result), fp);
        printf("Ping result: %s", result);
        
        if (strstr(result, "0% packet loss") == NULL) {
            packet_loss_count++;
        }

        total_sent++;

        pclose(fp);
        sleep(1); // Wait before sending the next ping
    }
    
    return NULL;
}

void monitor_bandwidth() {
    struct sockaddr_in server_addr;
    int sockfd;
    char buffer[BUFFER_SIZE];

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Monitoring bandwidth on port %d...\n", PORT);
    while (1) {
        int n;
        socklen_t len = sizeof(server_addr);

        // Receive the UDP packet
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&server_addr, &len);
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);

        // Simulate sending a response
        sendto(sockfd, buffer, n, MSG_CONFIRM, (const struct sockaddr *)&server_addr, len);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t ping_thread;
    if (pthread_create(&ping_thread, NULL, ping_host, argv[1]) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    monitor_bandwidth();

    pthread_join(ping_thread, NULL);
    
    printf("\nTotal packets sent: %d\n", total_sent);
    printf("Packet loss count: %d\n", packet_loss_count);
    printf("Packet loss rate: %.2f%%\n", ((double)packet_loss_count / total_sent) * 100);

    return EXIT_SUCCESS;
}