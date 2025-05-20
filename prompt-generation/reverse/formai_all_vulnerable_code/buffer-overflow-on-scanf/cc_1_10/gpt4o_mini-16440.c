//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16

typedef struct {
    unsigned char octets[4];
    unsigned char subnet_mask[4];
    unsigned char broadcast[4];
    int num_hosts;
} Subnet;

void calculate_subnet(int cidr, Subnet *subnet) {
    int mask = 0xFFFFFFFF << (32 - cidr);
    
    for (int i = 0; i < 4; i++) {
        subnet->subnet_mask[i] = (mask >> (i * 8)) & 0xFF;
        subnet->octets[i] = subnet->subnet_mask[i] & subnet->octets[i];
    }

    for (int i = 0; i < 4; i++) {
        subnet->broadcast[i] = subnet->octets[i] | ~subnet->subnet_mask[i];
    }

    subnet->num_hosts = (1 << (32 - cidr)) - 2;
}

void print_subnet_info(Subnet *subnet) {
    printf("Network Address: %d.%d.%d.%d\n", subnet->octets[0], subnet->octets[1], subnet->octets[2], subnet->octets[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet->subnet_mask[0], subnet->subnet_mask[1], subnet->subnet_mask[2], subnet->subnet_mask[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", subnet->broadcast[0], subnet->broadcast[1], subnet->broadcast[2], subnet->broadcast[3]);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
}

void convert_str_to_octets(const char *ip_str, unsigned char *octets) {
    char *token;
    char *ip_copy = strdup(ip_str);
    int i = 0;

    token = strtok(ip_copy, ".");
    while (token != NULL && i < 4) {
        octets[i] = (unsigned char) atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    free(ip_copy);
}

void validate_user_input(int *cidr, char *ip_str) {
    printf("Enter IP address (x.x.x.x format): ");
    scanf("%s", ip_str);
    
    printf("Enter CIDR notation (between 0 and 32): ");
    scanf("%d", cidr);
    
    if (*cidr < 0 || *cidr > 32) {
        fprintf(stderr, "Invalid CIDR notation. Should be between 0 and 32.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Subnet subnet;
    char ip_str[16];
    int cidr;

    validate_user_input(&cidr, ip_str);
    convert_str_to_octets(ip_str, subnet.octets);
    
    calculate_subnet(cidr, &subnet);
    print_subnet_info(&subnet);

    return 0;
}