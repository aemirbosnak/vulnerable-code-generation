//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_MASK_LENGTH 2

void split_ip(char *ip_address, int *octets) {
    char *token;
    int index = 0;

    token = strtok(ip_address, ".");
    while (token != NULL && index < 4) {
        octets[index++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void calculate_subnet(int *octets, int subnet_mask) {
    int subnet[4] = {0, 0, 0, 0};
    for (int i = 0; i < subnet_mask / 8; i++) {
        subnet[i] = octets[i];
    }
    if (subnet_mask % 8 != 0) {
        subnet[subnet_mask / 8] = octets[subnet_mask / 8] & (0xFF << (8 - (subnet_mask % 8)));
    }
    printf("Subnet Address: %d.%d.%d.%d\n",
           subnet[0], subnet[1], subnet[2], subnet[3]);
}

void calculate_broadcast(int *octets, int subnet_mask) {
    int broadcast[4] = {0, 0, 0, 0};
    for (int i = 0; i < subnet_mask / 8; i++) {
        broadcast[i] = octets[i];
    }
    if (subnet_mask % 8 != 0) {
        broadcast[subnet_mask / 8] = octets[subnet_mask / 8] & (0xFF << (8 - (subnet_mask % 8))) | (0xFF >> (subnet_mask % 8));
    } else {
        for (int i = subnet_mask / 8; i < 4; i++) {
            broadcast[i] = 255;
        }
    }
    printf("Broadcast Address: %d.%d.%d.%d\n",
           broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

void calculate_range(int *octets, int subnet_mask) {
    int first_host[4] = {0, 0, 0, 0};
    int last_host[4] = {0, 0, 0, 0};

    for (int i = 0; i < subnet_mask / 8; i++) {
        first_host[i] = octets[i];
        last_host[i] = octets[i];
    }

    if (subnet_mask % 8 != 0) {
        first_host[subnet_mask / 8] = octets[subnet_mask / 8] & (0xFF << (8 - (subnet_mask % 8)));
        last_host[subnet_mask / 8] = octets[subnet_mask / 8] | (0xFF >> (subnet_mask % 8));
    } else {
        for (int i = subnet_mask / 8; i < 4; i++) {
            first_host[i] = 0;
            last_host[i] = 255;
        }
    }
    first_host[3]++;
    last_host[3]--;

    printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           first_host[0], first_host[1], first_host[2], first_host[3],
           last_host[0], last_host[1], last_host[2], last_host[3]);
}

int main() {
    char ip_address[MAX_IP_LENGTH + 1];
    int octets[4];
    int subnet_mask;

    printf("=====================================\n");
    printf("C Subnet Calculator\n");
    printf("=====================================\n");
    printf("Enter IP Address (x.x.x.x): ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = 0;

    printf("Enter Subnet Mask (e.g. 24): ");
    scanf("%d", &subnet_mask);

    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask. Please enter a value between 0 and 32.\n");
        return 1;
    }

    split_ip(ip_address, octets);
    
    printf("Analyzing IP: %s / %d\n", ip_address, subnet_mask);
    
    calculate_subnet(octets, subnet_mask);
    calculate_broadcast(octets, subnet_mask);
    calculate_range(octets, subnet_mask);

    printf("=====================================\n");
    printf("End of Calculation.\n");
    printf("=====================================\n");
    
    return 0;
}