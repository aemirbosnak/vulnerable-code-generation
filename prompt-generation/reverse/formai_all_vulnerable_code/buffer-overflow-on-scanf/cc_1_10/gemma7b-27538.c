//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTS 1000

int main() {
    int i, host_count = 0, sockfd, ping_status;
    char hostname[MAX_HOSTS][256];
    struct sockaddr_in servaddr;

    // Allocates memory for hostnames
    malloc(MAX_HOSTS * sizeof(hostname));

    // Gets hostnames from the user
    printf("Enter the hostnames, separated by commas: ");
    scanf("%s", hostname);

    // Splits the hostname list into individual hosts
    char *host_list = strtok(hostname, ",");

    // Iterates over the hosts
    while (host_list) {
        // Creates a socket
        sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

        // Connects to the host
        servaddr.sin_port = htons(80);
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(host_list);
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
            perror("Error connecting to host");
            host_count++;
        } else {
            // Sends a ping message
            write(sockfd, "PING", 5);

            // Receives the ping response
            char reply[256];
            read(sockfd, reply, 256);

            // Prints the hostname and the ping status
            printf("%s: %s\n", host_list, reply);

            close(sockfd);
        }

        host_list = strtok(NULL, ",");
    }

    // Prints the number of hosts that could not be reached
    printf("Number of hosts that could not be reached: %d\n", host_count);

    return 0;
}