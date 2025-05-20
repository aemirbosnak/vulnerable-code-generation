//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/time.h>

#define IP_ADDR_LEN 16
#define MAX_SUBNETS 100

struct subnet {
    char ip[IP_ADDR_LEN];
    char subnet_mask[IP_ADDR_LEN];
    char subnet_ip[IP_ADDR_LEN];
    char broadcast_ip[IP_ADDR_LEN];
    char first_host_ip[IP_ADDR_LEN];
    char last_host_ip[IP_ADDR_LEN];
    int total_hosts;
};

// Function to get user input
void get_input(char *ip_address, char *subnet_mask, int *num_subnets) {
    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    printf("Enter number of subnets required: ");
    scanf("%d", num_subnets);
    printf("\n");
}

// Function to parse the IP address and subnet mask strings and convert them to binary format
void parse_ip_address(char *ip_address, unsigned char ip_addr[]) {
    char *token = strtok(ip_address, ".");
    int i = 0;

    while (token != NULL) {
        ip_addr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void parse_subnet_mask(char *subnet_mask, unsigned char subnet_mask_bin[]) {
    int subnet_mask_cidr = atoi(subnet_mask);
    int i = 0;

    for (i = 0; i < 4; i++) {
        if (subnet_mask_cidr >= 8) {
            subnet_mask_bin[i] = 255;
            subnet_mask_cidr -= 8;
        } else if (subnet_mask_cidr > 0) {
            subnet_mask_bin[i] = 256 - (int) pow(2, 8 - subnet_mask_cidr);
            subnet_mask_cidr = 0;
        } else {
            subnet_mask_bin[i] = 0;
        }
    }
}

// Function to calculate the subnet mask, subnet IP and broadcast IP for the main network
void calculate_main_network(char *ip_address, char *subnet_mask, char *subnet_ip, char *broadcast_ip) {
    unsigned char ip_addr[4];
    unsigned char subnet_mask_bin[4];
    unsigned char subnet_ip_bin[4];
    unsigned char broadcast_ip_bin[4];
    char ip_addr_str[IP_ADDR_LEN];

    parse_ip_address(ip_address, ip_addr);
    parse_subnet_mask(subnet_mask, subnet_mask_bin);

    for (int i = 0; i < 4; i++) {
        subnet_ip_bin[i] = ip_addr[i] & subnet_mask_bin[i];
        broadcast_ip_bin[i] = subnet_ip_bin[i] | (~subnet_mask_bin[i] & 0xFF);
    }

    sprintf(subnet_ip, "%d.%d.%d.%d", subnet_ip_bin[0], subnet_ip_bin[1], subnet_ip_bin[2], subnet_ip_bin[3]);
    sprintf(broadcast_ip, "%d.%d.%d.%d", broadcast_ip_bin[0], broadcast_ip_bin[1], broadcast_ip_bin[2], broadcast_ip_bin[3]);
}

// Function to calculate the subnet mask, subnet IP, broadcast IP and available IP range for each subnet
void calculate_subnets(struct subnet subnets[], int num_subnets, char *subnet_mask, char *subnet_ip) {
    unsigned char subnet_mask_bin[4];
    unsigned char subnet_ip_bin[4];
    unsigned char broadcast_ip_bin[4];
    unsigned char first_host_ip_bin[4];
    unsigned char last_host_ip_bin[4];
    unsigned int total_hosts;
    int subnet_bits = 0;

    parse_subnet_mask(subnet_mask, subnet_mask_bin);
    for (int i = 0; i < 4; i++) {
        subnet_bits += __builtin_popcount(subnet_mask_bin[i]);
    }

    total_hosts = pow(2, 32 - subnet_bits) - 2;
    total_hosts = total_hosts / num_subnets;
    total_hosts = total_hosts - (total_hosts % 2);

    parse_ip_address(subnet_ip, subnet_ip_bin);
    for (int i = 0; i < num_subnets; i++) {
        sprintf(subnets[i].subnet_mask, "%d.%d.%d.%d", subnet_mask_bin[0], subnet_mask_bin[1], subnet_mask_bin[2], subnet_mask_bin[3]);
        sprintf(subnets[i].subnet_ip, "%d.%d.%d.%d", subnet_ip_bin[0], subnet_ip_bin[1], subnet_ip_bin[2], subnet_ip_bin[3]);

        for (int j = 3; j >= 0; j--) {
            if ((subnet_mask_bin[j] & 0x80) == 0x80) {
                subnet_ip_bin[j] |= 1;
                broadcast_ip_bin[j] = subnet_ip_bin[j];
                first_host_ip_bin[j] = subnet_ip_bin[j] + 1;
                last_host_ip_bin[j] = broadcast_ip_bin[j] - 1;

                for (int k = j - 1; k >= 0; k--) {
                    subnet_ip_bin[k] = 0;
                    broadcast_ip_bin[k] = 255;
                    first_host_ip_bin[k] = 0;
                    last_host_ip_bin[k] = 255;
                }

                break;
            } else {
                subnet_ip_bin[j] &= ~1;
                broadcast_ip_bin[j] = subnet_ip_bin[j] | (~subnet_mask_bin[j] & 0xFF);
                first_host_ip_bin[j] = subnet_ip_bin[j] + 1;
                last_host_ip_bin[j] = broadcast_ip_bin[j] - 1;
            }
        }

        sprintf(subnets[i].ip, "%d.%d.%d.%d", subnet_ip_bin[0], subnet_ip_bin[1], subnet_ip_bin[2], subnet_ip_bin[3]);
        sprintf(subnets[i].broadcast_ip, "%d.%d.%d.%d", broadcast_ip_bin[0], broadcast_ip_bin[1], broadcast_ip_bin[2], broadcast_ip_bin[3]);
        sprintf(subnets[i].first_host_ip, "%d.%d.%d.%d", first_host_ip_bin[0], first_host_ip_bin[1], first_host_ip_bin[2], first_host_ip_bin[3]);
        sprintf(subnets[i].last_host_ip, "%d.%d.%d.%d", last_host_ip_bin[0], last_host_ip_bin[1], last_host_ip_bin[2], last_host_ip_bin[3]);
        subnets[i].total_hosts = total_hosts;

        subnet_ip_bin[3] = broadcast_ip_bin[3] + 1;
    }
}

int main() {
    char ip_address[IP_ADDR_LEN];
    char subnet_mask[IP_ADDR_LEN];
    char subnet_ip[IP_ADDR_LEN];
    char broadcast_ip[IP_ADDR_LEN];
    struct subnet subnets[MAX_SUBNETS];
    int num_subnets;

    get_input(ip_address, subnet_mask, &num_subnets);
    calculate_main_network(ip_address, subnet_mask, subnet_ip, broadcast_ip);
    calculate_subnets(subnets, num_subnets, subnet_mask, subnet_ip);

    printf("Main Network:\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Subnet IP: %s\n", subnet_ip);
    printf("Broadcast IP: %s\n", broadcast_ip);
    printf("\n");

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("Subnet IP: %s\n", subnets[i].subnet_ip);
        printf("Broadcast IP: %s\n", subnets[i].broadcast_ip);
        printf("First Host IP: %s\n", subnets[i].first_host_ip);
        printf("Last Host IP: %s\n", subnets[i].last_host_ip);
        printf("Total Hosts: %d\n", subnets[i].total_hosts);
        printf("\n");
    }

    return 0;
}