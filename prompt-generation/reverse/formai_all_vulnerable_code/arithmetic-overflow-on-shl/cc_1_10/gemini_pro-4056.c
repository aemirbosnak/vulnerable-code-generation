//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[INET6_ADDRSTRLEN];
    int prefix_length;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    struct sockaddr_in6 addr;
    if (inet_pton(AF_INET6, ip_address, &addr.sin6_addr) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    int num_subnets = (1 << (128 - prefix_length));
    int hosts_per_subnet = (1 << (128 - prefix_length)) - 2;

    printf("Number of subnets: %d\n", num_subnets);
    printf("Hosts per subnet: %d\n", hosts_per_subnet);

    for (int i = 0; i < num_subnets; i++) {
        for (int j = 0; j < 16; j++) {
            addr.sin6_addr.s6_addr[j] = (i >> j) | (addr.sin6_addr.s6_addr[j] & ~(1 << j));
        }

        char subnet_address[INET6_ADDRSTRLEN];
        if (inet_ntop(AF_INET6, &addr.sin6_addr, subnet_address, INET6_ADDRSTRLEN) == NULL) {
            perror("inet_ntop");
            exit(EXIT_FAILURE);
        }

        printf("Subnet %d: %s\n", i, subnet_address);

        for (int k = 1; k <= hosts_per_subnet; k++) {
            for (int j = 0; j < 16; j++) {
                addr.sin6_addr.s6_addr[j] = (addr.sin6_addr.s6_addr[j] & ~(1 << j)) | ((k >> j) & 1);
            }

            char host_address[INET6_ADDRSTRLEN];
            if (inet_ntop(AF_INET6, &addr.sin6_addr, host_address, INET6_ADDRSTRLEN) == NULL) {
                perror("inet_ntop");
                exit(EXIT_FAILURE);
            }

            printf("Host %d: %s\n", k, host_address);
        }

        printf("\n");
    }

    return 0;
}