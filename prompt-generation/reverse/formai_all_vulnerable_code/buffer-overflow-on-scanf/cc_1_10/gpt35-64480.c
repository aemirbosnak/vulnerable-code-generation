//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int bin_to_dec(char bin[]) {
    int i, len, dec = 0, pos = 1;

    len = strlen(bin);
    for (i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += pos;
        }
        pos *= 2;
    }

    return dec;
}

// Function to convert decimal to binary
void dec_to_bin(int dec, char bin[]) {
    int i, j, temp;
    char rev[8];

    for (i = 0; dec > 0; i++) {
        temp = dec % 2;
        rev[i] = temp + '0';
        dec /= 2;
    }

    // reverse the binary string
    for (j = 0; j < i; j++) {
        bin[j] = rev[i - j - 1];
    }
    bin[j] = '\0';
}

int main() {
    char ip[16], mask[16], *token;
    int i, j, cidr, subnet_mask[4], ip_address[4], network_address[4], broadcast_address[4], subnet_size;
    char subnet_bin[9], subnet_mask_bin[33], ip_bin[33], network_address_bin[33], broadcast_address_bin[33];

    // Cyberpunk style UI
    printf("________________________________________________________________\n");
    printf(" _____          _        _____             _        \n");
    printf("|     |___ ___|_|___   |  _  |___ ___ ___|_|___ ___\n");
    printf("|   --|  _|  _| |_ -|  |   __|   |  _|  _| |_ -|_ -|\n");
    printf("|_____|_| |_| |_|___|  |__|  |_|_|_| |_| |_|___|___|\n");
    printf("\n");
    printf("________________________________________________________________\n");
    printf("\n");

    printf("Please enter an IP address in the format xxx.xxx.xxx.xxx: ");
    scanf("%s", ip);

    printf("Please enter a subnet mask in the format xxx.xxx.xxx.xxx: ");
    scanf("%s", mask);

    // Parse IP address
    token = strtok(ip, ".");
    i = 0;
    while (token != NULL && i < 4) {
        ip_address[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    // Parse subnet mask
    token = strtok(mask, ".");
    i = 0;
    while (token != NULL && i < 4) {
        subnet_mask[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    // Calculate CIDR notation and subnet size
    for (i = 0; i < 4; i++) {
        dec_to_bin(subnet_mask[i], subnet_bin);
        strcat(subnet_mask_bin, subnet_bin);
    }

    cidr = 0;
    for (i = 0; subnet_mask_bin[i] != '\0'; i++) {
        if (subnet_mask_bin[i] == '1') {
            cidr++;
        }
    }

    subnet_size = 1;
    for (i = 0; i < (32 - cidr); i++) {
        subnet_size *= 2;
    }

    // Calculate network address and broadcast address
    for (i = 0; i < 4; i++) {
        network_address[i] = ip_address[i] & subnet_mask[i];
        broadcast_address[i] = network_address[i] | ~(subnet_mask[i]);
    }

    // Convert IP address, network address, and broadcast address to binary
    for (i = 0; i < 4; i++) {
        dec_to_bin(ip_address[i], ip_bin + (i * 8));
        dec_to_bin(network_address[i], network_address_bin + (i * 8));
        dec_to_bin(broadcast_address[i], broadcast_address_bin + (i * 8));
    }

    // Cyberpunk style output
    printf("----------------------------------------------\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("CIDR Notation: /%d\n", cidr);
    printf("Subnet Size: %d\n", subnet_size);
    printf("Network Address: %d.%d.%d.%d = %s\n", network_address[0], network_address[1], network_address[2], network_address[3], network_address_bin);
    printf("Broadcast Address: %d.%d.%d.%d = %s\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3], broadcast_address_bin);
    printf("----------------------------------------------\n");

    return 0;
}