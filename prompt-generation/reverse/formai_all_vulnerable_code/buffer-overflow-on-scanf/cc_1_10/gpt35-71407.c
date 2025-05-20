//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
    int ip[4], mask[4], subnet[4], network_id[4], host_id[4], broadcast_id[4], cidr;
    char choice;

    printf("Welcome to the Subnet Calculator program!\n\n");

    do {
        printf("Enter the IP address in the format xxx.xxx.xxx.xxx: ");
        scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

        printf("Enter the subnet mask in the format xxx.xxx.xxx.xxx: ");
        scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

        // Calculate CIDR notation
        cidr = 0;
        for (int i = 0; i < 4; i++) {
            int count = mask[i];
            while (count > 0) {
                cidr++;
                count = count & (count - 1);
            }
        }

        // Calculate subnet address
        for (int i = 0; i < 4; i++) {
            subnet[i] = ip[i] & mask[i];
        }

        // Calculate network ID, host ID, and broadcast ID
        for (int i = 0; i < 4; i++) {
            network_id[i] = subnet[i];
            host_id[i] = ip[i] & ~mask[i];
            broadcast_id[i] = subnet[i] | ~mask[i];
        }

        // Print results
        printf("\nSubnet Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
        printf("CIDR Notation: /%d\n", cidr);
        printf("Network ID: %d.%d.%d.%d\n", network_id[0], network_id[1], network_id[2], network_id[3]);
        printf("Host ID: %d.%d.%d.%d\n", host_id[0], host_id[1], host_id[2], host_id[3]);
        printf("Broadcast ID: %d.%d.%d.%d\n", broadcast_id[0], broadcast_id[1], broadcast_id[2], broadcast_id[3]);

        // Check if user wants to calculate another subnet
        printf("\nDo you want to calculate another subnet? (y/n): ");
        scanf(" %c", &choice); // leave a space before %c to clear input buffer
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Subnet Calculator program!\n");

    return 0;
}