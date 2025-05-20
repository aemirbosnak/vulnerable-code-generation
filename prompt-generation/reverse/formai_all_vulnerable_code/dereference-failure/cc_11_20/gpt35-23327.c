//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LENGTH 255
#define MAX_IP_ADDRESS_LENGTH 16

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: No hostnames provided.\n");
        return 1;
    }

    // Get the list of hostnames to monitor
    char **hostnames = argv + 1;
    int num_hosts = argc - 1;

    // Create the array to hold the IP addresses
    char **ip_addresses = (char **) malloc(num_hosts * sizeof(char *));
    if (ip_addresses == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        return 1;
    }

    // Loop through each hostname and get its IP address
    struct hostent *host_info;
    struct in_addr **addr_list;
    for (int i = 0; i < num_hosts; i++) {
        // Get the host information
        host_info = gethostbyname(hostnames[i]);
        if (host_info == NULL) {
            printf("ERROR: Unable to get host information for %s.\n", hostnames[i]);
            continue;
        }

        // Get the list of IP addresses
        addr_list = (struct in_addr **) host_info->h_addr_list;
        if (addr_list == NULL || *addr_list == NULL) {
            printf("ERROR: No IP addresses found for %s.\n", hostnames[i]);
            continue;
        }

        // Copy the first IP address to the array
        ip_addresses[i] = (char *) malloc(MAX_IP_ADDRESS_LENGTH);
        if (ip_addresses[i] == NULL) {
            printf("ERROR: Unable to allocate memory.\n");
            return 1;
        }
        strncpy(ip_addresses[i], inet_ntoa(*addr_list[0]), MAX_IP_ADDRESS_LENGTH);
    }

    // Initialize the start time
    time_t start_time = time(NULL);

    // Loop indefinitely
    while (1) {
        // Check the status of each host
        for (int i = 0; i < num_hosts; i++) {
            // Create the socket
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                printf("ERROR: Unable to create socket.\n");
                continue;
            }

            // Set the timeout
            struct timeval timeout;
            timeout.tv_sec = 2;
            timeout.tv_usec = 0;
            if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
                printf("ERROR: Unable to set socket timeout.\n");
                close(sockfd);
                continue;
            }

            // Set the address information
            struct sockaddr_in serv_addr;
            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(80);
            if (inet_aton(ip_addresses[i], &serv_addr.sin_addr) == 0) {
                printf("ERROR: Invalid IP address: %s\n", ip_addresses[i]);
                close(sockfd);
                continue;
            }

            // Connect to the server
            if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                printf("%s is down.\n", hostnames[i]);
            } else {
                printf("%s is up.\n", hostnames[i]);
            }

            // Close the socket
            close(sockfd);
        }

        // Sleep for 10 seconds
        sleep(10);
    }

    // Free the IP address array
    for (int i = 0; i < num_hosts; i++) {
        free(ip_addresses[i]);
    }
    free(ip_addresses);

    return 0;
}