//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the number of bits required for subnet mask
int calculateBits(int num) {
    int count = 0;
    while (num!= 0) {
        num = num >> 1;
        count++;
    }
    return count;
}

// Function to validate the input IP address
int validIP(char* ip) {
    int len = strlen(ip);
    char* token = strtok(ip, ".");
    int count = 0;
    while (token!= NULL) {
        if (count > 3) {
            return 0;
        }
        if (strlen(token) == 0 || strlen(token) > 3) {
            return 0;
        }
        int val = atoi(token);
        if (val < 0 || val > 255) {
            return 0;
        }
        token = strtok(NULL, ".");
        count++;
    }
    if (count!= 4) {
        return 0;
    }
    return 1;
}

// Function to calculate the subnet mask
void subnetMask(char* ip, char* mask) {
    int a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    int bits = calculateBits(atoi(mask));
    int subnet = 0;
    for (int i = 0; i < 4; i++) {
        if (i < bits) {
            subnet = (subnet << 8) | (0xff << (8 - bits));
        } else {
            subnet = (subnet << 8) | (0xff >> (8 - (32 - bits)));
        }
    }
    sprintf(mask, "%d.%d.%d.%d", (subnet >> 24) & 0xff, (subnet >> 16) & 0xff, (subnet >> 8) & 0xff, subnet & 0xff);
}

int main() {
    char ip[16], mask[16];
    printf("Enter the IP address: ");
    scanf("%s", ip);
    if (!validIP(ip)) {
        printf("Invalid IP address!\n");
        return 1;
    }
    printf("Enter the subnet mask: ");
    scanf("%s", mask);
    if (!validIP(mask)) {
        printf("Invalid subnet mask!\n");
        return 1;
    }
    subnetMask(ip, mask);
    printf("Subnet mask: %s\n", mask);
    return 0;
}