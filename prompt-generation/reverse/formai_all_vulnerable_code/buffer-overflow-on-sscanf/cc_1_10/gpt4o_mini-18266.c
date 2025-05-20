//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3
#define MAX_NETWORKS 10

typedef struct {
    char ip[MAX_IP_LENGTH];
    char subnet[MAX_SUBNET_LENGTH];
    unsigned char network[4];
    unsigned char mask[4];
} Subnet;

void convert_ip_to_binary(const char *ip_str, unsigned char *binary_ip);
void calculate_network_address(Subnet *subnet);
void print_subnet_info(const Subnet *subnet);
void prompt_user_for_input(Subnet *subnet);
void calculate_and_display_subnets(Subnet *subnets, int count);
int validate_ip(const char *ip_str);

int main() {
    Subnet subnets[MAX_NETWORKS];
    int subnet_count = 0;

    printf("C Subnet Calculator\n");
    printf("====================\n");

    while (subnet_count < MAX_NETWORKS) {
        prompt_user_for_input(&subnets[subnet_count]);
        if (validate_ip(subnets[subnet_count].ip) && 
            validate_ip(subnets[subnet_count].subnet)) {
            calculate_network_address(&subnets[subnet_count]);
            subnet_count++;
        } else {
            printf("Invalid IP or Subnet format – please try again.\n");
        }

        char choice;
        printf("Do you want to add more subnets? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    calculate_and_display_subnets(subnets, subnet_count);
    
    return 0;
}

void convert_ip_to_binary(const char *ip_str, unsigned char *binary_ip) {
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", 
           &binary_ip[0], 
           &binary_ip[1], 
           &binary_ip[2], 
           &binary_ip[3]);
}

void calculate_network_address(Subnet *subnet) {
    unsigned char ip_binary[4];
    unsigned char mask_binary[4];

    convert_ip_to_binary(subnet->ip, ip_binary);
    convert_ip_to_binary(subnet->subnet, mask_binary);

    for (int i = 0; i < 4; i++) {
        subnet->network[i] = ip_binary[i] & mask_binary[i];
        subnet->mask[i] = mask_binary[i];
    }
}

void print_subnet_info(const Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->subnet);
    printf("Network Address: %d.%d.%d.%d\n",
           subnet->network[0], subnet->network[1],
           subnet->network[2], subnet->network[3]);
    printf("Subnet Mask (binary): ");
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (subnet->mask[i] >> j) & 1);
        }
        if (i < 3) printf(".");
    }
    printf("\n");
}

void prompt_user_for_input(Subnet *subnet) {
    printf("Enter IP Address: ");
    scanf("%s", subnet->ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet->subnet);
}

int validate_ip(const char *ip_str) {
    uint32_t ip = 0;
    int num_fields = sscanf(ip_str, "%u.%u.%u.%u", 
                            (unsigned int *)&((uint8_t*)&ip)[0],
                            (unsigned int *)&((uint8_t*)&ip)[1],
                            (unsigned int *)&((uint8_t*)&ip)[2],
                            (unsigned int *)&((uint8_t*)&ip)[3]);
    return (num_fields == 4 && (ip & 0xFFFFFFFF) <= 0xFFFFFFFF);
}

void calculate_and_display_subnets(Subnet *subnets, int count) {
    printf("\nCalculated Network Addresses for all subnets:\n");
    for (int i = 0; i < count; i++) {
        print_subnet_info(&subnets[i]);
        printf("--------------------\n");
    }
}