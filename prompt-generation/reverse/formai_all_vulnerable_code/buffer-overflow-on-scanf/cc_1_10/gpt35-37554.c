//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 16

bool validate_ip_address(char* ip_address) {
    int num, dots = 0;
    char* ptr;

    if (ip_address == NULL) return false;

    ptr = strtok(ip_address, ".");

    if (ptr == NULL) return false;

    while (ptr) {
        if (!isdigit(*ptr)) return false;

        num = atoi(ptr);

        if (num < 0 || num > 255) return false;

        ptr = strtok(NULL, ".");

        if (ptr != NULL) dots++;
    }

    if (dots != 3) return false;

    return true;
}

int get_subnet_mask_bits(char* subnet_mask) {
    int bits = 0, num;

    if (subnet_mask == NULL) return bits;

    char* ptr = strtok(subnet_mask, ".");

    if (ptr == NULL) return bits;

    while (ptr) {
        num = atoi(ptr);

        if (num != 255 && num != 0) {
            while (num) {
                if (num % 2) {
                    bits++;
                }

                num /= 2;
            }
        } else if (num == 255) {
            bits += 8;
        }

        ptr = strtok(NULL, ".");
    }

    return bits;
}

void print_subnet_details(char* ip_address, char* subnet_mask) {
    if (!validate_ip_address(ip_address)) {
        printf("Invalid IP Address\n");
        return;
    }

    if (!validate_ip_address(subnet_mask)) {
        printf("Invalid Subnet Mask\n");
        return;
    }

    int subnet_mask_bits = get_subnet_mask_bits(subnet_mask);
    int total_subnet_addresses = 1 << (32 - subnet_mask_bits);
    int total_host_addresses = total_subnet_addresses - 2;

    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Subnet Mask Bits: %d\n", subnet_mask_bits);
    printf("Total Subnet Addresses: %d\n", total_subnet_addresses);
    printf("Total Host Addresses: %d\n", total_host_addresses);
    printf("Network Address: ");

    char* ptr = strtok(ip_address, ".");

    for (int i = 0; i < 4; i++) {
        int num = atoi(ptr);

        if (i == 3) {
            printf("%d", (num & 0xff) >> subnet_mask_bits);
        } else {
            printf("%d.", num);
        }

        ptr = strtok(NULL, ".");
    }
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_IP_LENGTH];

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    print_subnet_details(ip_address, subnet_mask);

    return 0;
}