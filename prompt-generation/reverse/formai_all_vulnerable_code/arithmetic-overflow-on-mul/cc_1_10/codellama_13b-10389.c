//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: invasive
/*
 * Ping Test Program
 *
 * This program sends a ICMP echo request to a specified
 * IP address and waits for a response. If a response is
 * received within a specified time limit, the program
 * prints the round-trip time (RTT) and returns the exit
 * code 0. Otherwise, the program prints an error message
 * and returns the exit code 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>

#define PING_TIMEOUT 2
#define PING_PACKET_SIZE 64
#define PING_DATA "Hello, world!"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    // Create a socket for sending and receiving ICMP packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) < 0) {
        perror("setsockopt() failed");
        return 1;
    }

    // Create an ICMP header and fill it with the necessary information
    struct icmphdr icmp_header;
    icmp_header.type = ICMP_ECHO;
    icmp_header.code = 0;
    icmp_header.checksum = 0;
    icmp_header.un.echo.id = getpid();
    icmp_header.un.echo.sequence = 0;

    // Create an ICMP packet and fill it with the ICMP header and data
    char icmp_packet[PING_PACKET_SIZE];
    memcpy(icmp_packet, &icmp_header, sizeof(icmp_header));
    strcpy(icmp_packet + sizeof(icmp_header), PING_DATA);

    // Create a sockaddr_in structure for the destination IP address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Send the ICMP packet to the destination IP address
    if (sendto(sock, icmp_packet, sizeof(icmp_packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("sendto() failed");
        return 1;
    }

    // Set a timeout for the receive operation
    struct timeval tv;
    tv.tv_sec = PING_TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt() failed");
        return 1;
    }

    // Receive the ICMP response packet
    char response[PING_PACKET_SIZE];
    int response_len = recvfrom(sock, response, sizeof(response), 0, NULL, NULL);
    if (response_len < 0) {
        perror("recvfrom() failed");
        return 1;
    }

    // Print the round-trip time (RTT)
    printf("RTT: %d ms\n", response_len * 1000 / 2);

    // Close the socket
    close(sock);

    return 0;
}