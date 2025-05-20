//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: statistical
/*
 * A unique C Port Scanner example program in a statistical style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 10000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
        return 1;
    }

    // Parse the input arguments
    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port = atoi(strtok(port_range, "-"));
    int end_port = atoi(strtok(NULL, "-"));

    // Initialize variables
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

    // Attempt to connect to each port in the range
    for (int i = start_port; i <= end_port; i++) {
        printf("Scanning port %d\n", i);
        server_addr.sin_port = htons(i);
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("ERROR connecting");
            continue;
        }
        printf("Port %d is open\n", i);
        close(sockfd);
    }

    return 0;
}