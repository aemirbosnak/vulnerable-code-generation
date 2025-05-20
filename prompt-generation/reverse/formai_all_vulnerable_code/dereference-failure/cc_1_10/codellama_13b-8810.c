//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTS 100
#define MAX_PORTS 10

typedef struct {
    char host[16];
    int port;
} host_port_t;

void print_hosts(host_port_t hosts[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s:%d\n", hosts[i].host, hosts[i].port);
    }
}

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buffer[1024];
    host_port_t hosts[MAX_HOSTS];
    int host_count = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(12345);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        len = sizeof(cliaddr);
        int new_sockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (new_sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive data from the client
        n = recv(new_sockfd, buffer, 1024, 0);
        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // Add the client to the host list
        strcpy(hosts[host_count].host, inet_ntoa(cliaddr.sin_addr));
        hosts[host_count].port = ntohs(cliaddr.sin_port);
        host_count++;

        // Send ack to the client
        if (send(new_sockfd, "ACK", 3, 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // Close the socket
        close(new_sockfd);
    }

    // Print the host list
    print_hosts(hosts, host_count);

    return 0;
}