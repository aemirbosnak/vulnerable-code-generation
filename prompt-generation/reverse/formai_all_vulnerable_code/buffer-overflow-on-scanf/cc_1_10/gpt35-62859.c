//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_CIDR_LEN 2
#define MAX_MASK_LEN 15
#define MAX_BINARY_LEN 35
#define FIRST_BYTE_MAX 255
#define OCTET_COUNT 4
#define BINARY_BASE 2

void printMenu() {
    printf("Subnet Calculator\n\n");
    printf("1. Calculate Subnet and Mask\n");
    printf("2. Check if IP is valid\n");
    printf("3. Determine Network and Broadcast addresses\n");
    printf("4. Determine Valid Host Range\n");
    printf("5. Quit\n\n");
}

void calculateSubnetAndMask(int cidr, char* mask) {
    int octet, i;
    int maskOctets[OCTET_COUNT];
    memset(maskOctets, 0, sizeof(maskOctets));

    for (i = 0; cidr > 0 && i < OCTET_COUNT; i++) {
        octet = cidr >= 8 ? 255 : (FIRST_BYTE_MAX << (MAX_CIDR_LEN - cidr) & FIRST_BYTE_MAX);
        maskOctets[i] = octet;
        cidr -= 8;
    }

    sprintf(mask, "%d.%d.%d.%d", maskOctets[0], maskOctets[1], maskOctets[2], maskOctets[3]);
    printf("Subnet Mask: %s\n", mask);
}

int isValidIP(char* ipStr) {
    int octet;
    char* ptr;

    // Convert IP string to octets
    for (octet = 1, ptr = strtok(ipStr, "."); octet <= OCTET_COUNT && ptr != NULL; octet++, ptr = strtok(NULL, ".")) {
        // Check if octet is valid
        if (atoi(ptr) > FIRST_BYTE_MAX) {
            return 0;
        }
    }

    // Check if IP has all octets
    if (octet <= OCTET_COUNT) {
        return 0;
    }

    return 1;
}

void determineNetworkAndBroadcast(char* ipStr, char* maskStr) {
    int ipOctets[OCTET_COUNT], maskOctets[OCTET_COUNT], netOctets[OCTET_COUNT], broadcastOctets[OCTET_COUNT];
    int i;
    memset(ipOctets, 0, sizeof(ipOctets));
    memset(maskOctets, 0, sizeof(maskOctets));
    memset(netOctets, 0, sizeof(netOctets));
    memset(broadcastOctets, 0, sizeof(broadcastOctets));

    // Convert IP address and subnet mask to octets
    sscanf(ipStr, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);
    sscanf(maskStr, "%d.%d.%d.%d", &maskOctets[0], &maskOctets[1], &maskOctets[2], &maskOctets[3]);

    // Calculate Network and Broadcast addresses
    for (i = 0; i < OCTET_COUNT; i++) {
        netOctets[i] = ipOctets[i] & maskOctets[i];
        broadcastOctets[i] = netOctets[i] | ~maskOctets[i];
    }

    printf("Network Address: %d.%d.%d.%d\n", netOctets[0], netOctets[1], netOctets[2], netOctets[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastOctets[0], broadcastOctets[1], broadcastOctets[2], broadcastOctets[3]);
}

void determineHostRange(char* ipStr, char* maskStr) {
    int ipOctets[OCTET_COUNT], maskOctets[OCTET_COUNT], netOctets[OCTET_COUNT], broadcastOctets[OCTET_COUNT];
    int i;
    memset(ipOctets, 0, sizeof(ipOctets));
    memset(maskOctets, 0, sizeof(maskOctets));
    memset(netOctets, 0, sizeof(netOctets));
    memset(broadcastOctets, 0, sizeof(broadcastOctets));

    // Convert IP address and subnet mask to octets
    sscanf(ipStr, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);
    sscanf(maskStr, "%d.%d.%d.%d", &maskOctets[0], &maskOctets[1], &maskOctets[2], &maskOctets[3]);

    // Calculate Network and Broadcast addresses
    for (i = 0; i < OCTET_COUNT; i++) {
        netOctets[i] = ipOctets[i] & maskOctets[i];
        broadcastOctets[i] = netOctets[i] | ~maskOctets[i];
    }

    if (broadcastOctets[3] - netOctets[3] >= 2) {
        netOctets[3]++;
        broadcastOctets[3]--;
        printf("Valid Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", 
               netOctets[0], netOctets[1], netOctets[2], netOctets[3], 
               broadcastOctets[0], broadcastOctets[1], broadcastOctets[2], broadcastOctets[3]);
    }
    else {
        printf("No Valid Host Range in Network\n");
    }
}

void clearInputBuffer() {
    // Clear input buffer by reading until a newline or EOF
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opt;
    int cidr;
    char ipStr[MAX_IP_LEN+1];
    char maskStr[MAX_MASK_LEN+1];

    do {
        printMenu();
        printf("Enter Option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nEnter CIDR: ");
                scanf("%d", &cidr);
                calculateSubnetAndMask(cidr, maskStr);
                break;
            case 2:
                printf("\nEnter IP Address: ");
                clearInputBuffer();
                fgets(ipStr, MAX_IP_LEN+1, stdin);
                ipStr[strlen(ipStr)-1] = '\0'; // Remove newline character from fgets
                if (isValidIP(ipStr)) {
                    printf("Valid IP Address\n");
                }
                else {
                    printf("Invalid IP Address\n");
                }
                break;
            case 3:
                printf("\nEnter IP Address: ");
                clearInputBuffer();
                fgets(ipStr, MAX_IP_LEN+1, stdin);
                ipStr[strlen(ipStr)-1] = '\0'; // Remove newline character from fgets
                printf("Enter Subnet Mask: ");
                fgets(maskStr, MAX_MASK_LEN+1, stdin);
                maskStr[strlen(maskStr)-1] = '\0'; // Remove newline character from fgets
                determineNetworkAndBroadcast(ipStr, maskStr);
                break;
            case 4:
                printf("\nEnter IP Address: ");
                clearInputBuffer();
                fgets(ipStr, MAX_IP_LEN+1, stdin);
                ipStr[strlen(ipStr)-1] = '\0'; // Remove newline character from fgets
                printf("Enter Subnet Mask: ");
                fgets(maskStr, MAX_MASK_LEN+1, stdin);
                maskStr[strlen(maskStr)-1] = '\0'; // Remove newline character from fgets
                determineHostRange(ipStr, maskStr);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("Invalid Option\n");
                break;
        }

        printf("\n");

    } while (opt != 5);

    return 0;
}