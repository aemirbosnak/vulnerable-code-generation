//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A subnet calculator for two lovers
// Calculates the subnet of two IP addresses

int main() {

    char lover1_ip[20], lover2_ip[20], subnet[20], *ptr;
    int i, j, a[4], b[4], c[4];

    // Get lover1's IP address
    printf("\nEnter lover1's IP address: ");
    scanf("%s", lover1_ip);

    // Get lover2's IP address
    printf("\nEnter lover2's IP address: ");
    scanf("%s", lover2_ip);

    // Convert lover1's IP address to array of integers
    ptr = strtok(lover1_ip, ".");
    i = 0;
    while (ptr != NULL) {
        a[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    // Convert lover2's IP address to array of integers
    ptr = strtok(lover2_ip, ".");
    i = 0;
    while (ptr != NULL) {
        b[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    // Calculate subnet of the lovers
    for (i = 0; i < 4; i++) {
        c[i] = a[i] & b[i];
    }

    // Convert subnet to dotted decimal notation
    sprintf(subnet, "%d.%d.%d.%d", c[0], c[1], c[2], c[3]);

    // Output the subnet of the lovers
    printf("\nThe subnet of the lovers is %s\n\n", subnet);

    // Print romantic message
    printf("My Beloved, I calculated the subnet of our love,\n");
    printf("And found that it is %s.\n", subnet);
    printf("I hope this is proof that our love is strong and true,\n");
    printf("And that we will always be together, as one.\n");

    return 0;
}