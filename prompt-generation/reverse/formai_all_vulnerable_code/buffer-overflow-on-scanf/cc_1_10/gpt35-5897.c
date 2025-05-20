//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IP 15 // Maximum length of IP address string
#define MAX_SUBNET 32 // Maximum CIDR subnet mask value
#define MIN_SUBNET 0 // Minimum CIDR subnet mask value
#define MAX_BINARY 11111111 // Maximum binary value for classful IP address
#define MIN_BINARY 0 // Minimum binary value for classful IP address

// Function to validate IP address
int is_valid_ip_address(char *ip_address) {
    int i, num, len;
    char *token, *rest, *dup_ip;

    len = strlen(ip_address);
    if (len < 7 || len > MAX_IP) {
        return 0;
    }

    dup_ip = strdup(ip_address);
    if (dup_ip == NULL) {
        return 0;
    }

    token = strtok_r(dup_ip, ".", &rest);
    i = 0;
    while (token != NULL) {
        if (i == 4) {
            return 0;
        }

        num = atoi(token);
        if (num < 0 || num > 255) {
            return 0;
        }

        token = strtok_r(NULL, ".", &rest);
        i++;
    }

    if (i != 4) {
        return 0;
    }

    return 1;
}

// Function to validate CIDR subnet mask
int is_valid_cidr_subnet(int cidr_subnet) {
    if (cidr_subnet < MIN_SUBNET || cidr_subnet > MAX_SUBNET) {
        return 0;
    }

    return 1;
}

// Function to convert IP address to binary format
void ip_to_binary(char *ip_address, char *binary_address) {
    int i, num, len;
    char *token, *rest, *dup_ip;

    dup_ip = strdup(ip_address);
    token = strtok_r(dup_ip, ".", &rest);
    i = 0;
    while (token != NULL) {
        num = atoi(token);
        binary_address[i++] = (num & 0x80) ? '1' : '0';
        binary_address[i++] = (num & 0x40) ? '1' : '0';
        binary_address[i++] = (num & 0x20) ? '1' : '0';
        binary_address[i++] = (num & 0x10) ? '1' : '0';
        binary_address[i++] = (num & 0x08) ? '1' : '0';
        binary_address[i++] = (num & 0x04) ? '1' : '0';
        binary_address[i++] = (num & 0x02) ? '1' : '0';
        binary_address[i++] = (num & 0x01) ? '1' : '0';
        token = strtok_r(NULL, ".", &rest);
    }
}

// Function to calculate subnet ID and broadcast address
void calculate_subnet_and_broadcast(char *binary_address, char *subnet_id, char *broadcast_address, int cidr_subnet) {
    int i;
    char *subnet_mask;

    subnet_mask = (char*)calloc(MAX_BINARY + 1, sizeof(char));
    for (i = 0; i < cidr_subnet; i++) {
        subnet_mask[i] = '1';
    }
    for (i = cidr_subnet; i < MAX_BINARY; i++) {
        subnet_mask[i] = '0';
    }

    for (i = 0; i < MAX_BINARY; i++) {
        subnet_id[i] = (binary_address[i] & subnet_mask[i]) ? binary_address[i] : '0';
        broadcast_address[i] = (binary_address[i] | ~subnet_mask[i]) ? binary_address[i] : '1';
    }
}

// Main function to calculate subnet and broadcast addresses
int main(int argc, char *argv[]) {
    char ip_address[MAX_IP + 1], binary_address[MAX_IP * 8 + 1], subnet_id[MAX_IP * 8 + 1], broadcast_address[MAX_IP * 8 + 1];
    int cidr_subnet;

    printf("Enter IP address: ");
    scanf("%s", ip_address);
    if (!is_valid_ip_address(ip_address)) {
        printf("Invalid IP address format.\n");
        return 1;
    }

    printf("Enter CIDR subnet mask: ");
    scanf("%d", &cidr_subnet);
    if (!is_valid_cidr_subnet(cidr_subnet)) {
        printf("Invalid CIDR subnet mask value.\n");
        return 1;
    }

    ip_to_binary(ip_address, binary_address);
    calculate_subnet_and_broadcast(binary_address, subnet_id, broadcast_address, cidr_subnet);

    printf("IP address: %s\n", ip_address);
    printf("Binary address: %s\n", binary_address);
    printf("CIDR subnet mask: %d\n", cidr_subnet);
    printf("Subnet ID: %s\n", subnet_id);
    printf("Broadcast address: %s\n", broadcast_address);

    return 0;
}