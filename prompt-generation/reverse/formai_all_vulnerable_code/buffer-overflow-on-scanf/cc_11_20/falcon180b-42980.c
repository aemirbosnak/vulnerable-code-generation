//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_IP_LENGTH 15
#define NUM_OCTETS 4

typedef struct {
    char ip[MAX_IP_LENGTH];
    int mask;
} Subnet;

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];
    char input[MAX_IP_LENGTH];
    char *token;
    int octet_count = 0;

    // Prompt user for number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnet array
    for (i = 0; i < num_subnets; i++) {
        subnets[i].mask = 0;
    }

    // Loop through each subnet
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d IP address: ", i+1);
        scanf("%s", input);

        // Validate input
        if (strlen(input) > MAX_IP_LENGTH) {
            printf("Error: IP address is too long.\n");
            exit(1);
        }

        // Convert input to uppercase
        for (int j = 0; j < strlen(input); j++) {
            input[j] = toupper(input[j]);
        }

        // Parse IP address into octets
        char *ptr = strtok(input, ".");
        while (ptr!= NULL) {
            if (octet_count >= NUM_OCTETS) {
                printf("Error: IP address has too many octets.\n");
                exit(1);
            }
            subnets[i].ip[octet_count] = atoi(ptr);
            octet_count++;
            ptr = strtok(NULL, ".");
        }

        // Check for missing octets
        if (octet_count < NUM_OCTETS) {
            printf("Error: IP address is missing octets.\n");
            exit(1);
        }

        // Calculate subnet mask
        subnets[i].mask = 0;
        for (int j = 0; j < NUM_OCTETS; j++) {
            if (subnets[i].ip[j] == 0) {
                subnets[i].mask |= (0xFF << (j * 8));
            } else {
                subnets[i].mask |= (subnets[i].ip[j] << (j * 8));
            }
        }
    }

    // Print subnet information
    printf("\nSubnet IP address\tSubnet mask\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%-15s\t\t%d.%d.%d.%d\n", subnets[i].ip, (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
    }

    return 0;
}