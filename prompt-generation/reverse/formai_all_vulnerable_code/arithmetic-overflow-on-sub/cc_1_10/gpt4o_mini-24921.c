//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNET 32

typedef struct {
    char ip[16];
    int subnet_mask;
} NetworkConfig;

void convert_to_binary(int num, char *binary) {
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

void calculate_subnet(NetworkConfig *config) {
    unsigned int mask = 0xFFFFFFFF << (MAX_SUBNET - config->subnet_mask);
    int number_of_hosts = (1 << (MAX_SUBNET - config->subnet_mask)) - 2;

    printf("Calculating Subnet for: %s/%d\n", config->ip, config->subnet_mask);
    printf("Subnet Mask: %d (CIDR) : %X\n", config->subnet_mask, mask);

    char binary_mask[9];
    int octets[4];
    sscanf(config->ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    printf("Binary Representation: ");
    for (int i = 0; i < 4; i++) {
        convert_to_binary(octets[i], binary_mask);
        printf("%s.", binary_mask);
    }
    printf("\n");

    printf("Number of Hosts: %d\n", number_of_hosts);
}

void get_user_input(NetworkConfig *config) {
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%s", config->ip);
    printf("Enter Subnet Mask (CIDR format, e.g., 24): ");
    scanf("%d", &config->subnet_mask);
    while (config->subnet_mask < 0 || config->subnet_mask > 32) {
        printf("Invalid subnet mask! Please enter a value between 0 and 32: ");
        scanf("%d", &config->subnet_mask);
    }
}

void display_menu() {
    printf("\n--- C Subnet Calculator ---\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
}

int main() {
    NetworkConfig config;

    while (1) {
        display_menu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            get_user_input(&config);
            calculate_subnet(&config);
        } else if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}