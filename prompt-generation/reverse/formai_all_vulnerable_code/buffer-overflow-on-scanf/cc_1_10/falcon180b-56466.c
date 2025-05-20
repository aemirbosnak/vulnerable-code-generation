//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 8
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[32];
    int size;
    int mask;
} Subnet;

void print_subnets(Subnet subnets[], int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, subnets[i].size);
    }
}

int main() {
    char ip_address[16];
    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    int num_octets = 0;
    char *token = strtok(ip_address, ".");
    while (token!= NULL) {
        num_octets++;
        token = strtok(NULL, ".");
    }

    if (num_octets!= 4) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int network_size = 0;
    int network_mask = 0;
    int host_size = 0;
    int host_mask = 0;

    for (int i = 0; i < num_octets; i++) {
        int octet = atoi(strtok(ip_address, "."));
        network_size += (octet & 0x7F) << (i * 8);
        network_mask += 0xFF << (i * 8);
        host_size += (octet & 0x80) << (i * 8);
        host_mask += 0xFF << (i * 8);
    }

    int subnet_size = network_size + 1;
    int subnet_mask = network_mask | ~host_mask;

    if (subnet_size > 32) {
        printf("Subnet size too large.\n");
        return 1;
    }

    if (subnet_mask == 0xFFFFFFFF) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    while (num_subnets < MAX_SUBNETS && subnet_size > 1) {
        Subnet new_subnet;
        strcpy(new_subnet.name, ip_address);
        new_subnet.size = subnet_size;
        new_subnet.mask = subnet_mask;
        subnets[num_subnets++] = new_subnet;

        subnet_size -= 2;
        subnet_mask += 2;
    }

    if (num_subnets == 0) {
        printf("No subnets found.\n");
        return 1;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}