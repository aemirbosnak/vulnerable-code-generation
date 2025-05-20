//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to validate IP address
int validate_ip(char *ip) {
    int count = 0;
    char *ptr = strtok(ip, ".");
    while (ptr != NULL) {
        count++;
        int num = atoi(ptr);
        if(num < 0 || num > 255)
            return 0;
        ptr = strtok(NULL, ".");
    }
    if(count != 4)
        return 0;
    return 1;
}

// Function to return network address
char* get_network_address(char *ip, char *subnet_mask) {
    char *network_address = (char *)malloc(sizeof(char) * 16);
    char *ptr1 = strtok(ip, ".");
    char *ptr2 = strtok(subnet_mask, ".");
    int i = 0;
    while (ptr1 != NULL) {
        int num1 = atoi(ptr1);
        int num2 = atoi(ptr2);
        int result = num1 & num2;
        char temp[4];
        sprintf(temp, "%d", result);
        if(i != 0)
            strcat(network_address, ".");
        strcat(network_address, temp);
        ptr1 = strtok(NULL, ".");
        ptr2 = strtok(NULL, ".");
        i++;
    }
    return network_address;
}

// Function to return broadcast address
char* get_broadcast_address(char *ip, char *subnet_mask) {
    char *broadcast_address = (char *)malloc(sizeof(char) * 16);
    char *ptr1 = strtok(ip, ".");
    char *ptr2 = strtok(subnet_mask, ".");
    int i = 0;
    while (ptr1 != NULL) {
        int num1 = atoi(ptr1);
        int num2 = atoi(ptr2);
        int result = num1 ^ ~num2;
        char temp[4];
        sprintf(temp, "%d", result);
        if(i != 0)
            strcat(broadcast_address, ".");
        strcat(broadcast_address, temp);
        ptr1 = strtok(NULL, ".");
        ptr2 = strtok(NULL, ".");
        i++;
    }
    return broadcast_address;
}

// Function to return first host
char* get_first_host(char *network_address) {
    char *first_host = (char *)malloc(sizeof(char) * 16);
    char *ptr = strtok(network_address, ".");
    int i = 0;
    while (ptr != NULL) {
        if(i == 3) {
            strcat(first_host, ptr);
            strcat(first_host, ".");
            strcat(first_host, "1");
        } else {
            strcat(first_host, ptr);
            strcat(first_host, ".");
        }
        ptr = strtok(NULL, ".");
        i++;
    }
    return first_host;
}

// Function to return last host
char* get_last_host(char *broadcast_address) {
    char *last_host = (char *)malloc(sizeof(char) * 16);
    char *ptr = strtok(broadcast_address, ".");
    int i = 0;
    while (ptr != NULL) {
        if(i == 3) {
            strcat(last_host, ptr);
            strcat(last_host, ".");
            strcat(last_host, "254");
        } else {
            strcat(last_host, ptr);
            strcat(last_host, ".");
        }
        ptr = strtok(NULL, ".");
        i++;
    }
    return last_host;
}

// Function to return total usable hosts
int get_total_hosts(char *subnet_mask) {
    int num_bits = 0;
    char *ptr = strtok(subnet_mask, ".");
    while (ptr != NULL) {
        int num = atoi(ptr);
        num_bits += (int)log2(num);
        ptr = strtok(NULL, ".");
    }
    return pow(2, (32 - num_bits)) - 2;
}

int main() {
    char ip[16], subnet_mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip);
    while (!validate_ip(ip)) {
        printf("Invalid IP! Enter again: ");
        scanf("%s", ip);
    }
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);
    while (!validate_ip(subnet_mask)) {
        printf("Invalid Subnet Mask! Enter again: ");
        scanf("%s", subnet_mask);
    }

    char *network_address = get_network_address(ip, subnet_mask);
    char *broadcast_address = get_broadcast_address(ip, subnet_mask);
    char *first_host = get_first_host(network_address);
    char *last_host = get_last_host(broadcast_address);
    int total_hosts = get_total_hosts(subnet_mask);

    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("First Host: %s\n", first_host);
    printf("Last Host: %s\n", last_host);
    printf("Total Usable Hosts: %d\n", total_hosts);

    // Freeing up dynamically allocated memory
    free(network_address);
    free(broadcast_address);
    free(first_host);
    free(last_host);

    return 0;
}