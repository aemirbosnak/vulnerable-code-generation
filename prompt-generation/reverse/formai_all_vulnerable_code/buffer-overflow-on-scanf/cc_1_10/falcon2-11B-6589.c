//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to send ICMP echo request
int send_icmp_request(const char* hostname, int port) {
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    memcpy(&address.sin_addr.s_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    int result = sendto(sockfd, "E", 1, 0, (struct sockaddr*)&address, sizeof(address));
    if (result < 0) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return 0;
}

// Function to receive ICMP echo reply
int receive_icmp_reply(const char* hostname, int port) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(hostname);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    int result = recvfrom(sockfd, NULL, 0, 0, (struct sockaddr*)&address, sizeof(address));
    if (result < 0) {
        perror("recvfrom");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return 0;
}

int main() {
    char hostname[256];
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Check if the hostname is valid
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Invalid hostname\n");
        return -1;
    }

    // Set up the ICMP parameters
    int port = 7; // ICMP echo port
    char buffer[1024];

    // Send ICMP echo request
    int result = send_icmp_request(hostname, port);
    if (result < 0) {
        printf("Failed to send ICMP echo request\n");
        return -1;
    }

    // Receive ICMP echo reply
    result = receive_icmp_reply(hostname, port);
    if (result < 0) {
        printf("Failed to receive ICMP echo reply\n");
        return -1;
    }

    // Check the received buffer for the ICMP reply
    if (strncmp(buffer, "icmp_seq=1 ttl=64 time=10ms", 35) == 0) {
        printf("Ping successful!\n");
    } else {
        printf("Ping failed\n");
    }

    return 0;
}