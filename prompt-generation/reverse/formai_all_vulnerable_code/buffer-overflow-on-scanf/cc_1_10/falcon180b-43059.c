//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

// Function to check if a port is open or not
int is_port_open(int sockfd, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sockfd);
        return TRUE;
    } else {
        close(sockfd);
        return FALSE;
    }
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    int sockfd, port;
    struct sockaddr_in server;
    int opt = TRUE;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (port = start_port; port <= end_port; port++) {
        if (is_port_open(sockfd, port)) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sockfd);
}

int main() {
    int start_port, end_port;

    printf("Enter the starting port number: ");
    scanf("%d", &start_port);

    printf("Enter the ending port number: ");
    scanf("%d", &end_port);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 0;
    }

    scan_ports(start_port, end_port);

    return 0;
}