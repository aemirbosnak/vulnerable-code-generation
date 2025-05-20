//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("\n=================== Subnet Calculator ===================\n");
    printf("1. Calculate Subnet using Classful addressing\n");
    printf("2. Calculate Subnet using Classless addressing\n");
    printf("3. Exit\n");
    printf("==========================================================\n");
}

void calculateClassfulSubnet(char *ip, int subnetClass) {
    int networkAddress[4], subnetMask[4];
    char *token;
    char temp[16];

    // Based on the class, define the default subnet mask
    switch (subnetClass) {
        case 1: // Class A
            subnetMask[0] = 255; subnetMask[1] = 0;   subnetMask[2] = 0;    subnetMask[3] = 0;
            break;
        case 2: // Class B
            subnetMask[0] = 255; subnetMask[1] = 255; subnetMask[2] = 0;  subnetMask[3] = 0;
            break;
        case 3: // Class C
            subnetMask[0] = 255; subnetMask[1] = 255; subnetMask[2] = 255; subnetMask[3] = 0;
            break;
        default:
            printf("Invalid Class!\n");
            return;
    }

    // Split the IP into components
    strcpy(temp, ip);
    token = strtok(temp, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        networkAddress[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        networkAddress[i] &= subnetMask[i];
    }

    // Calculate the broadcast address
    int broadcastAddress[4];
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = networkAddress[i] | (~subnetMask[i] & 255);
    }

    int usableHosts = (1 << (32 - (subnetClass == 1 ? 8 : subnetClass == 2 ? 16 : 24))) - 2;

    printf("Classful Subnet Calculation:\n");
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
    printf("Number of Usable Hosts: %d\n", usableHosts);
}

void calculateClasslessSubnet(char *ip, char *subnetMaskStr) {
    int networkAddress[4], subnetMask[4];
    char *token;
    char temp[16];

    // Convert the subnet mask into an array of integers
    strcpy(temp, subnetMaskStr);
    token = strtok(temp, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        subnetMask[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Split the IP into components
    strcpy(temp, ip);
    token = strtok(temp, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        networkAddress[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        networkAddress[i] &= subnetMask[i];
    }

    // Calculate the broadcast address
    int broadcastAddress[4];
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = networkAddress[i] | (~subnetMask[i] & 255);
    }

    // Calculate usable hosts
    int totalBits = 0;
    for (int i = 0; i < 4; i++) {
        totalBits += __builtin_popcount(~subnetMask[i]);
    }
    int usableHosts = (1 << totalBits) - 2;

    printf("Classless Subnet Calculation:\n");
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
    printf("Number of Usable Hosts: %d\n", usableHosts);
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        char ip[16];
        switch (choice) {
            case 1:
                printf("Enter IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip);
                printf("Choose Class (1: A, 2: B, 3: C): ");
                int classChoice;
                scanf("%d", &classChoice);
                calculateClassfulSubnet(ip, classChoice);
                break;
            case 2:
                printf("Enter IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip);
                char subnetMask[16];
                printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
                scanf("%s", subnetMask);
                calculateClasslessSubnet(ip, subnetMask);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}