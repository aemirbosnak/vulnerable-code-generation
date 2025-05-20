//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>

// Function to handle Ctrl+C signal
void handle_sigint(int sig) {
    printf("\nExiting...\n");
    exit(0);
}

int main() {
    // Register Ctrl+C signal handler
    signal(SIGINT, handle_sigint);

    // Get IP address from user
    char ip_address[16];
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set socket options
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Failed to set socket options");
        exit(1);
    }

    // Send ping request
    char ping_request[] = "PING";
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi("80"));
    addr.sin_addr.s_addr = inet_addr(ip_address);
    if (sendto(sock, ping_request, strlen(ping_request), 0, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("Failed to send ping request");
        exit(1);
    }

    // Receive ping response
    char ping_response[1024];
    struct sockaddr_in r_addr;
    socklen_t r_addr_len = sizeof(r_addr);
    if (recvfrom(sock, ping_response, sizeof(ping_response), 0, (struct sockaddr *) &r_addr, &r_addr_len) < 0) {
        perror("Failed to receive ping response");
        close(sock);
        return 1;
    }

    close(sock);

    printf("Ping response: %s\n", ping_response);
    return 0;
}