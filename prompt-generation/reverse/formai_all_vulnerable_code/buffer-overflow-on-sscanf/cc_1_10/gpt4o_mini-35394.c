//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayUsage() {
    printf("Usage: Subnet Calculator\n");
    printf("Enter an IP Address and a Subnet Mask to decipher the network mysteries.\n");
}

void calculateSubnet(char *ip, char *mask) {
    unsigned int ipParts[4], maskParts[4], networkParts[4];
    sscanf(ip, "%u.%u.%u.%u", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(mask, "%u.%u.%u.%u", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    // Calculate the Network Address
    for (int i = 0; i < 4; i++) {
        networkParts[i] = ipParts[i] & maskParts[i];
    }

    // Display the results of our deduction
    printf("The fog clears and reveals the mystery:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %u.%u.%u.%u\n", networkParts[0], networkParts[1], networkParts[2], networkParts[3]);
}

int main() {
    char ip[16], mask[16];
    char proceed;

    printf("Good evening, dear Watson! Let us engage in some network detective work.\n");

    do {
        printf("Please enter the IP Address (e.g., 192.168.1.1): ");
        fgets(ip, sizeof(ip), stdin);
        ip[strcspn(ip, "\n")] = 0; // Remove trailing newline

        printf("Now, dear friend, provide the Subnet Mask (e.g., 255.255.255.0): ");
        fgets(mask, sizeof(mask), stdin);
        mask[strcspn(mask, "\n")] = 0; // Remove trailing newline

        calculateSubnet(ip, mask);

        printf("Would you like to investigate another case? (y/n): ");
        scanf(" %c", &proceed);
        while (getchar() != '\n'); // Clear buffer
    } while (proceed == 'y' || proceed == 'Y');

    printf("Very well, Watson. Until our next intrigue on the network frontier!\n");
    return 0;
}