//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef struct {
    uint32_t prefixlen;
    uint32_t ip;
    char *mask;
    uint32_t available_ips;
} subnet_t;

int main()
{
    // Get the user input
    char ip_string[16];
    uint32_t prefixlen;
    printf("Enter the IP address: ");
    scanf("%s", ip_string);
    printf("Enter the prefix length: ");
    scanf("%u", &prefixlen);

    // Parse the IP address
    uint32_t ip;
    if (inet_pton(AF_INET, ip_string, &ip) != 1)
    {
        printf("Invalid IP address\n");
        return -1;
    }

    // Calculate the subnet mask
    uint32_t mask = ~((1 << (32 - prefixlen)) - 1);

    // Calculate the network address
    uint32_t network = ip & mask;

    // Calculate the broadcast address
    uint32_t broadcast = network | ~mask;

    // Calculate the number of available IPs
    uint32_t available_ips = ((1 << (32 - prefixlen)) - 2);

    // Print the results
    printf("Subnet Mask: %s\n", inet_ntoa(*((struct in_addr *)&mask)));
    printf("Network Address: %s\n", inet_ntoa(*((struct in_addr *)&network)));
    printf("Broadcast Address: %s\n", inet_ntoa(*((struct in_addr *)&broadcast)));
    printf("Available IPs: %u\n", available_ips);

    return 0;
}