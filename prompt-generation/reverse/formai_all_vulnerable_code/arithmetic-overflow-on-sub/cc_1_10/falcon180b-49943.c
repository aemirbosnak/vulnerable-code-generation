//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

int main() {
    char subnet[100];
    int mask, i, j, k, n;
    printf("Enter the subnet mask: ");
    scanf("%s", subnet);

    // Convert the subnet mask from string to integer
    for (i = 0, mask = 0; subnet[i]; i++) {
        if (subnet[i] == '.') {
            k = 0;
            n = 0;
            while (subnet[i + 1] >= '0' && subnet[i + 1] <= '9') {
                n = (n << 1) + (subnet[i + 1] - '0');
                i++;
            }
            mask |= (n << (8 - k));
            k += n;
        } else {
            mask |= (subnet[i] - '0');
        }
    }

    // Calculate the number of subnets
    int num_subnets = (int) pow(2, 32 - mask);

    // Calculate the number of hosts per subnet
    int num_hosts = (int) pow(2, 32 - mask - 1) - 1;

    // Calculate the number of broadcast addresses per subnet
    int num_broadcasts = num_hosts - 1;

    // Calculate the number of valid IP addresses per subnet
    int num_valid_ips = num_hosts - 2;

    // Calculate the number of total IP addresses per subnet
    int num_total_ips = num_valid_ips + num_broadcasts;

    // Calculate the number of subnets per network
    int num_networks = num_subnets / num_subnets;

    printf("Subnet mask: %s\n", subnet);
    printf("Number of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", num_hosts);
    printf("Number of broadcast addresses per subnet: %d\n", num_broadcasts);
    printf("Number of valid IP addresses per subnet: %d\n", num_valid_ips);
    printf("Number of total IP addresses per subnet: %d\n", num_total_ips);
    printf("Number of subnets per network: %d\n", num_networks);

    return 0;
}