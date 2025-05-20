//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>

int main() {
    int ip_addr[4], subnet_mask[4], cidr_notation, wildcard_mask[4], num_hosts;
    int network_addr[4], broadcast_addr[4], first_host_addr[4], last_host_addr[4];

    printf("Please enter IP address in decimal notation (e.g. 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ip_addr[0], &ip_addr[1], &ip_addr[2], &ip_addr[3]);

    printf("Please enter subnet mask in decimal notation (e.g. 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    cidr_notation = 0;
    for(int i = 0; i < 4; i++) {
        // Counting the bits in subnet mask
        int bits = 0;
        for(int j = 7; j >= 0; j--) {
            if((subnet_mask[i] & (1 << j)) >> j == 1) {
                bits++;
            } else {
                break;
            }
        }
        cidr_notation += bits;
    }

    // Calculating the wildcard mask
    for(int i = 0; i < 4; i++) {
        wildcard_mask[i] = 255 - subnet_mask[i];
    }

    // Calculating the network address
    for(int i = 0; i < 4; i++) {
        network_addr[i] = ip_addr[i] & subnet_mask[i];
    }

    // Calculating the broadcast address
    for(int i = 0; i < 4; i++) {
        broadcast_addr[i] = ip_addr[i] | wildcard_mask[i];
    }

    // Calculating the number of hosts
    num_hosts = 1;
    for(int i = 0; i < 32 - cidr_notation; i++) {
        num_hosts *= 2;
    }
    num_hosts -= 2;

    // Calculating the first host address
    first_host_addr[3] = network_addr[3] + 1;
    for(int i = 2; i >= 0; i--) {
        if(ip_addr[i] == 255) {
            first_host_addr[i] = network_addr[i];
        } else {
            first_host_addr[i] = ip_addr[i] + 1;
            break;
        }
    }
    first_host_addr[1] = first_host_addr[1] & subnet_mask[1];
    first_host_addr[2] = first_host_addr[2] & subnet_mask[2];

    // Calculating the last host address
    last_host_addr[3] = broadcast_addr[3] - 1;
    for(int i = 2; i >= 0; i--) {
        if(ip_addr[i] == 0) {
            last_host_addr[i] = broadcast_addr[i];
        } else {
            last_host_addr[i] = ip_addr[i] - 1;
            break;
        }
    }
    last_host_addr[1] = last_host_addr[1] | wildcard_mask[1];
    last_host_addr[2] = last_host_addr[2] | wildcard_mask[2];

    // Printing the results
    printf("\n");
    printf("CIDR notation: /%d\n", cidr_notation);
    printf("Wildcard mask: %d.%d.%d.%d\n", wildcard_mask[0], wildcard_mask[1], wildcard_mask[2], wildcard_mask[3]);
    printf("Network address: %d.%d.%d.%d\n", network_addr[0], network_addr[1], network_addr[2], network_addr[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_addr[0], broadcast_addr[1], broadcast_addr[2], broadcast_addr[3]);
    printf("Number of hosts: %d\n", num_hosts);
    printf("First host address: %d.%d.%d.%d\n", first_host_addr[0], first_host_addr[1], first_host_addr[2], first_host_addr[3]);
    printf("Last host address: %d.%d.%d.%d\n", last_host_addr[0], last_host_addr[1], last_host_addr[2], last_host_addr[3]);

    return 0;
}