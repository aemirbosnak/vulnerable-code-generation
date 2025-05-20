//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>

#define PORT 8080
#define MAXLINE 1024
#define SAMPLES 5

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int packets_sent;
    int packets_received;
    float latency; // in milliseconds
} QoSData;

void printQoSData(QoSData *data, int count) {
    printf("\n--- Quality of Service Statistics ---\n");
    printf("IP Address\tPackets Sent\tPackets Received\tAverage Latency (ms)\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%d\t\t%.2f\n", data[i].ip, 
               data[i].packets_sent, 
               data[i].packets_received, 
               (data[i].packets_received > 0) ? (data[i].latency / data[i].packets_received) : 0.0);
    }
}

float calculateLatency(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_nsec - start.tv_nsec) / 1000000.0f;
}

void simulatePing(QoSData *data, int index) {
    struct sockaddr_in server_address;
    int sockfd;
    char sendline[MAXLINE], recvline[MAXLINE];
    struct timespec start, end;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, data[index].ip, &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    data[index].packets_sent = SAMPLES;
    for (int i = 0; i < SAMPLES; i++) {
        sprintf(sendline, "Ping %d", i + 1);
        clock_gettime(CLOCK_MONOTONIC, &start);
        sendto(sockfd, sendline, strlen(sendline), MSG_CONFIRM, 
               (const struct sockaddr *)&server_address, sizeof(server_address));
        
        recvfrom(sockfd, recvline, MAXLINE, MSG_WAITALL, 
                 (struct sockaddr *)&server_address, (socklen_t*)&server_address);
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        data[index].latency += calculateLatency(start, end);
        data[index].packets_received++;
        sleep(1); // simulate time between pings
    }

    close(sockfd);
}

int main() {
    QoSData qosData[2];
    
    strcpy(qosData[0].ip, "8.8.8.8"); // Google DNS
    strcpy(qosData[1].ip, "1.1.1.1"); // Cloudflare DNS

    for (int i = 0; i < 2; i++) {
        simulatePing(qosData, i);
    }

    printQoSData(qosData, 2);
    
    return 0;
}