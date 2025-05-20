//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address from string to integer
int ip_to_int(char *ip) {
    int i, j, k, num = 0;
    char *ptr;

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            num = num * 256;
            j = i + 1;
        } else {
            k = i;
            while (ip[k]!= '.') {
                k++;
            }
            ptr = (char *) malloc(k - i + 1);
            strncpy(ptr, &ip[i], k - i);
            num += atoi(ptr);
            free(ptr);
            i = k - 1;
        }
    }

    return num;
}

// Function to calculate subnet mask
void subnet_mask(int ip, int subnet) {
    int i, j;
    char mask[16];

    for (i = 0; i < 32; i++) {
        if ((subnet >> i) & 1) {
            mask[i] = '1';
        } else {
            mask[i] = '0';
        }
    }

    mask[32] = '\0';
    printf("Subnet Mask: %s\n", mask);
}

// Function to calculate broadcast address
void broadcast_address(int ip, int subnet) {
    int i, j;
    char broadcast[16];

    for (i = 0; i < 32; i++) {
        if ((subnet >> i) & 1) {
            broadcast[i] = '1';
        } else {
            broadcast[i] = '0';
        }
    }

    broadcast[32] = '\0';
    printf("Broadcast Address: %s\n", broadcast);
}

int main() {
    char ip[16];
    int subnet;

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Convert IP address from string to integer
    int ip_int = ip_to_int(ip);

    // Calculate subnet mask based on subnet bits
    printf("Enter subnet bits: ");
    scanf("%d", &subnet);

    // Calculate subnet mask and broadcast address
    subnet_mask(ip_int, subnet);
    broadcast_address(ip_int, subnet);

    return 0;
}