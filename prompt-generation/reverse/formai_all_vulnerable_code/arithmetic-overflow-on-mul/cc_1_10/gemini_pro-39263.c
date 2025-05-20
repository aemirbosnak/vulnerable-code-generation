//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <time.h>

// Set up constants
#define ETH_HDR_LEN 14
#define IP_HDR_LEN 20
#define UDP_HDR_LEN 8

// Define the QoS monitor structure
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char buf[1500];
    struct timeval start_time;
    struct timeval end_time;
    double rtt;
} qos_monitor;

// Initialize the QoS monitor
void init_qos_monitor(qos_monitor *m, char *ip_addr, int port) {
    // Create a raw socket
    m->sockfd = socket(AF_INET, SOCK_RAW, htons(ETH_P_IP));
    if (m->sockfd == -1) {
        perror("Error creating raw socket");
        exit(1);
    }

    // Set up the socket address
    m->addr.sin_family = AF_INET;
    m->addr.sin_port = htons(port);
    m->addr.sin_addr.s_addr = inet_addr(ip_addr);

    // Bind the socket to the address
    if (bind(m->sockfd, (struct sockaddr *)&m->addr, sizeof(m->addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Initialize the start and end time
    gettimeofday(&m->start_time, NULL);
    gettimeofday(&m->end_time, NULL);
}

// Start the QoS monitor
void start_qos_monitor(qos_monitor *m) {
    // Start listening for packets
    while (1) {
        // Receive a packet
        int len = recvfrom(m->sockfd, m->buf, sizeof(m->buf), 0, (struct sockaddr *)&m->addr, sizeof(m->addr));
        if (len == -1) {
            perror("Error receiving packet");
            continue;
        }

        // Parse the packet
        struct ethhdr *ethhdr = (struct ethhdr *)m->buf;
        struct iphdr *iphdr = (struct iphdr *)(m->buf + ETH_HDR_LEN);
        struct udphdr *udphdr = (struct udphdr *)(m->buf + ETH_HDR_LEN + IP_HDR_LEN);

        // Check if the packet is a UDP packet from the specified IP address and port
        if (ethhdr->h_proto == htons(ETH_P_IP) && iphdr->protocol == IPPROTO_UDP && udphdr->source == htons(m->addr.sin_port) && udphdr->dest == htons(m->addr.sin_port)) {
            // Calculate the RTT
            gettimeofday(&m->end_time, NULL);
            m->rtt = (m->end_time.tv_sec - m->start_time.tv_sec) * 1000000 + (m->end_time.tv_usec - m->start_time.tv_usec);

            // Print the RTT
            printf("RTT: %f ms\n", m->rtt);

            // Reset the start time
            gettimeofday(&m->start_time, NULL);
        }
    }
}

// Main function
int main() {
    // Initialize the QoS monitor
    qos_monitor m;
    init_qos_monitor(&m, "192.168.1.1", 5000);

    // Start the QoS monitor
    start_qos_monitor(&m);

    return 0;
}