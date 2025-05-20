//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Custom firewall rules
struct firewall_rule {
    char* description;
    int protocol; // 0 for TCP, 1 for UDP
    int port; // 0 for all ports
    char* source_ip; // 0.0.0.0 for all IPs
};

// Initialize the firewall with a set of rules
struct firewall_rule rules[] = {
    { "Allow SSH", 0, 22, "0.0.0.0" },
    { "Allow HTTP", 0, 80, "0.0.0.0" },
    { "Allow HTTPS", 0, 443, "0.0.0.0" },
    { "Deny everything else", 0, 0, "0.0.0.0" }
};

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the firewall port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Main loop
    while (1) {
        // Receive a packet
        char buf[1024];
        struct sockaddr_in cliaddr;
        socklen_t len = sizeof(cliaddr);
        int n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &cliaddr, &len);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        // Check the firewall rules
        int allowed = 0;
        for (int i = 0; i < sizeof(rules) / sizeof(struct firewall_rule); i++) {
            if (rules[i].protocol == 0 && rules[i].port == 0 && strcmp(rules[i].source_ip, "0.0.0.0") == 0) {
                allowed = 1;
                break;
            } else if (rules[i].protocol == 0 && rules[i].port == ntohs(cliaddr.sin_port) && strcmp(rules[i].source_ip, inet_ntoa(cliaddr.sin_addr)) == 0) {
                allowed = 1;
                break;
            }
        }

        // Send a response
        if (allowed) {
            sendto(sockfd, "Packet allowed", 15, 0, (struct sockaddr *) &cliaddr, len);
        } else {
            sendto(sockfd, "Packet denied", 13, 0, (struct sockaddr *) &cliaddr, len);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}