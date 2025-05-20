//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>

#define TIMEOUT 5
#define PACKET_SIZE 64
#define NUM_PACKETS 10

// Define a structure to hold the QoS metrics
typedef struct {
    int packet_number;
    struct timeval send_time;
    struct timeval recv_time;
    long round_trip_time; // In microseconds
} QoSMonitor;

// Function to send a packet and measure round trip time
void send_packet(int sockfd, struct sockaddr_in *server_addr, QoSMonitor *metrics, int packet_number) {
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    
    gettimeofday(&metrics[packet_number].send_time, NULL);
    
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Sendto failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a packet
void receive_packet(int sockfd, QoSMonitor *metrics, int packet_number) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    
    if (recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&from, &fromlen) < 0) {
        perror("Recvfrom failed");
        exit(EXIT_FAILURE);
    }
    
    gettimeofday(&metrics[packet_number].recv_time, NULL);
    metrics[packet_number].round_trip_time = (metrics[packet_number].recv_time.tv_sec - metrics[packet_number].send_time.tv_sec) * 1000000 + 
                                             (metrics[packet_number].recv_time.tv_usec - metrics[packet_number].send_time.tv_usec);
}

void print_statistics(QoSMonitor *metrics) {
    long total_rtt = 0;
    
    printf("Packet Number\tRound Trip Time (ms)\n");
    for (int i = 0; i < NUM_PACKETS; i++) {
        total_rtt += metrics[i].round_trip_time;
        printf("%d\t\t%ld\n", i, metrics[i].round_trip_time / 1000);
    }
    
    printf("Average RTT: %ld ms\n", total_rtt / NUM_PACKETS / 1000);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <destination_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    QoSMonitor metrics[NUM_PACKETS];

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    // Send and receive packets
    for (int i = 0; i < NUM_PACKETS; i++) {
        send_packet(sockfd, &server_addr, metrics, i);
        usleep(100000); // Sleep for 100 ms before receiving
        receive_packet(sockfd, metrics, i);
    }

    // Print statistics
    print_statistics(metrics);

    close(sockfd);
    return 0;
}