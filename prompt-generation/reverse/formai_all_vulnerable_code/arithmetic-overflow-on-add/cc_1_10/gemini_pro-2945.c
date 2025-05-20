//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>

// Define the maximum number of packets to send
#define MAX_PACKETS 10000

// Define the size of each packet
#define PACKET_SIZE 1024

// Define the interval between packets in milliseconds
#define INTERVAL 1000

// Define the port to send packets to
#define PORT 5001

// Define the IP address to send packets to
#define IP_ADDRESS "127.0.0.1"

// Create a socket
int create_socket(void) {
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    return sockfd;
}

// Bind the socket to the specified port
void bind_socket(int sockfd, int port) {
    struct sockaddr_in addr;

    // Set the address and port of the socket
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the address and port
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }
}

// Send a packet to the specified IP address and port
void send_packet(int sockfd, char *ip_address, int port, char *data, int size) {
    struct sockaddr_in addr;

    // Set the address and port of the destination
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Send the packet
    if (sendto(sockfd, data, size, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("sendto");
        exit(1);
    }
}

// Calculate the average round-trip time
double calculate_average_rtt(int sockfd, char *ip_address, int port, int num_packets) {
    int i;
    struct timeval start, end;
    double total_rtt = 0;

    // Send the packets
    for (i = 0; i < num_packets; i++) {
        // Get the current time
        gettimeofday(&start, NULL);

        // Send the packet
        send_packet(sockfd, ip_address, port, "ping", PACKET_SIZE);

        // Receive the packet
        if (recvfrom(sockfd, "pong", PACKET_SIZE, 0, NULL, NULL) == -1) {
            perror("recvfrom");
            exit(1);
        }

        // Get the current time
        gettimeofday(&end, NULL);

        // Calculate the round-trip time
        total_rtt += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    }

    // Calculate the average round-trip time
    return total_rtt / num_packets;
}

// Calculate the packet loss rate
double calculate_packet_loss_rate(int sockfd, char *ip_address, int port, int num_packets) {
    int i;
    int num_lost = 0;

    // Send the packets
    for (i = 0; i < num_packets; i++) {
        // Send the packet
        send_packet(sockfd, ip_address, port, "ping", PACKET_SIZE);

        // Receive the packet
        if (recvfrom(sockfd, "pong", PACKET_SIZE, 0, NULL, NULL) == -1) {
            num_lost++;
        }
    }

    // Calculate the packet loss rate
    return (double)num_lost / num_packets;
}

// Print the results
void print_results(double average_rtt, double packet_loss_rate) {
    printf("Average RTT: %.2f ms\n", average_rtt);
    printf("Packet loss rate: %.2f%%\n", packet_loss_rate * 100);
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd;
    double average_rtt;
    double packet_loss_rate;

    // Create a socket
    sockfd = create_socket();

    // Bind the socket to the specified port
    bind_socket(sockfd, PORT);

    // Calculate the average round-trip time
    average_rtt = calculate_average_rtt(sockfd, IP_ADDRESS, PORT, MAX_PACKETS);

    // Calculate the packet loss rate
    packet_loss_rate = calculate_packet_loss_rate(sockfd, IP_ADDRESS, PORT, MAX_PACKETS);

    // Print the results
    print_results(average_rtt, packet_loss_rate);

    // Close the socket
    close(sockfd);

    return 0;
}