//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned int address;
    unsigned int netmask;
    unsigned int cidr;
    unsigned int num_hosts;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int broadcast;
} subnet_info;

void print_subnet_info(subnet_info subnet) {
    printf("Subnet Information:\n");
    printf("--------------------\n");
    printf("Address: %u.%u.%u.%u\n", (subnet.address >> 24) & 0xFF, (subnet.address >> 16) & 0xFF, (subnet.address >> 8) & 0xFF, subnet.address & 0xFF);
    printf("Netmask: %u.%u.%u.%u\n", (subnet.netmask >> 24) & 0xFF, (subnet.netmask >> 16) & 0xFF, (subnet.netmask >> 8) & 0xFF, subnet.netmask & 0xFF);
    printf("CIDR: %u\n", subnet.cidr);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
    printf("First Host: %u.%u.%u.%u\n", (subnet.first_host >> 24) & 0xFF, (subnet.first_host >> 16) & 0xFF, (subnet.first_host >> 8) & 0xFF, subnet.first_host & 0xFF);
    printf("Last Host: %u.%u.%u.%u\n", (subnet.last_host >> 24) & 0xFF, (subnet.last_host >> 16) & 0xFF, (subnet.last_host >> 8) & 0xFF, subnet.last_host & 0xFF);
    printf("Broadcast: %u.%u.%u.%u\n", (subnet.broadcast >> 24) & 0xFF, (subnet.broadcast >> 16) & 0xFF, (subnet.broadcast >> 8) & 0xFF, subnet.broadcast & 0xFF);
}

int main() {
    char input[100];
    subnet_info subnet;

    printf("Enter the subnet address and netmask in the format 'x.x.x.x/y': ");
    fgets(input, sizeof(input), stdin);

    // Parse the input
    char *ptr = strtok(input, "/");
    if (ptr == NULL) {
        printf("Invalid input format.\n");
        return EXIT_FAILURE;
    }
    subnet.address = inet_addr(ptr);
    ptr = strtok(NULL, "/");
    if (ptr == NULL) {
        printf("Invalid input format.\n");
        return EXIT_FAILURE;
    }
    subnet.cidr = atoi(ptr);

    // Calculate the netmask
    subnet.netmask = 0xFFFFFFFF << (32 - subnet.cidr);

    // Calculate the number of hosts
    subnet.num_hosts = (1 << (32 - subnet.cidr)) - 2;

    // Calculate the first host
    subnet.first_host = subnet.address & subnet.netmask;

    // Calculate the last host
    subnet.last_host = subnet.first_host + subnet.num_hosts;

    // Calculate the broadcast address
    subnet.broadcast = subnet.last_host | ~subnet.netmask;

    // Print the subnet information
    print_subnet_info(subnet);

    return EXIT_SUCCESS;
}