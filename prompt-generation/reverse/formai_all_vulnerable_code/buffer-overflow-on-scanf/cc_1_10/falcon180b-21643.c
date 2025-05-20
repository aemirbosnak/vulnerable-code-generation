//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if input is a valid IP address
int is_valid_ip(char *ip) {
    int i;
    int count = 0;
    char *token;

    token = strtok(ip, ".");

    while (token!= NULL) {
        for (i = 0; i < strlen(token); i++) {
            if (!isdigit(token[i])) {
                return 0;
            }
        }
        count++;
        token = strtok(NULL, ".");
    }

    if (count!= 4) {
        return 0;
    }

    return 1;
}

// Function to calculate subnet mask
void calculate_subnet_mask(int num_hosts, char *ip, char *mask) {
    int i;
    int host_id;
    int subnet_id;

    // Calculate number of bits for subnet ID
    for (i = 0; i < 4; i++) {
        if (ip[i] == '0' && mask[i] == '1') {
            subnet_id++;
        }
    }

    // Calculate number of bits for host ID
    for (i = 0; i < 4; i++) {
        if (ip[i] == '1' && mask[i] == '0') {
            host_id++;
        }
    }

    // Calculate number of hosts
    num_hosts = pow(2, host_id);

    // Calculate subnet mask
    for (i = 0; i < 4; i++) {
        if (ip[i] == '1' && mask[i] == '0') {
            mask[i] = '1';
        } else if (ip[i] == '0' && mask[i] == '1') {
            mask[i] = '0';
        }
    }
}

// Function to calculate broadcast address
void calculate_broadcast_address(char *ip, char *mask) {
    int i;

    for (i = 0; i < 4; i++) {
        if (ip[i] == '1' && mask[i] == '0') {
            ip[i] = '1';
        } else if (ip[i] == '0' && mask[i] == '1') {
            ip[i] = '0';
        }
    }
}

int main() {
    char ip[16];
    char mask[16];
    int num_hosts;

    printf("Enter IP address: ");
    scanf("%s", ip);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    printf("Enter number of hosts: ");
    scanf("%d", &num_hosts);

    calculate_subnet_mask(num_hosts, ip, mask);

    printf("Subnet mask: %s\n", mask);

    calculate_broadcast_address(ip, mask);

    printf("Broadcast address: %s\n", ip);

    return 0;
}