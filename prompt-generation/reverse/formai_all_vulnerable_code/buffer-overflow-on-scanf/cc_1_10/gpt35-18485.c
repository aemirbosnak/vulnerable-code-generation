//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//function to check if string is a valid IP address
int valid_IP(char *ip_address) {
    int num_dots = 0;
    char *temp = ip_address;
    while (*temp) {
        if (*temp == '.') num_dots++;
        temp++;
    }
    if (num_dots != 3) return 0;
    char *token;
    token = strtok(ip_address, ".");
    while (token != NULL) {
        if (!isdigit(*token)) return 0;
        int num = atoi(token);
        if (num < 0 || num > 255) return 0;
        token = strtok(NULL, ".");
    }
    return 1;
}

//function to convert binary string to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    int binary_len = strlen(binary);
    int i;
    for (i = 0; i < binary_len; i++) {
        if (binary[binary_len-i-1] == '1') decimal += pow(2, i);
    }
    return decimal;
}

//function to convert decimal to binary string
char* decimal_to_binary(int decimal) {
    char *binary = (char *)malloc(sizeof(char) * 9);
    int i;
    for (i = 0; i < 8; i++) {
        if (decimal % 2 == 0) {
            binary[7-i] = '0';
        } else {
            binary[7-i] = '1';
        }
        decimal = decimal / 2;
    }
    binary[8] = '\0';
    return binary;
}

int main() {
    char ip_address[16];
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    if (!valid_IP(ip_address)) {
        printf("Invalid IP address\n");
        return -1;
    }

    //Parse IP address into octets    
    int octets[4];
    char *temp;
    temp = strtok(ip_address, ".");
    int i;
    for (i = 0; i < 4; i++) {
        octets[i] = atoi(temp);
        temp = strtok(NULL, ".");
    }
    
    //Calculate class of IP address
    char ip_class;
    int first_octet = octets[0];
    if (first_octet >= 1 && first_octet <= 126) {
        ip_class = 'A';
    } else if (first_octet >= 128 && first_octet <= 191) {
        ip_class = 'B';
    } else if (first_octet >= 192 && first_octet <= 223) {
        ip_class = 'C';
    } else if (first_octet >= 224 && first_octet <= 239) {
        ip_class = 'D';
    } else {
        ip_class = 'E';
    }
    printf("Class of IP address: %c\n", ip_class);

    //Calculate network address and subnet mask
    int network_address[4];
    int subnet_mask[4];
    switch(ip_class) {
        case 'A': {
            network_address[0] = octets[0];
            network_address[1] = 0;
            network_address[2] = 0;
            network_address[3] = 0;
            subnet_mask[0] = 255;
            subnet_mask[1] = 0;
            subnet_mask[2] = 0;
            subnet_mask[3] = 0;
            break;
        }
        case 'B': {
            network_address[0] = octets[0];
            network_address[1] = octets[1];
            network_address[2] = 0;
            network_address[3] = 0;
            subnet_mask[0] = 255;
            subnet_mask[1] = 255;
            subnet_mask[2] = 0;
            subnet_mask[3] = 0;
            break;
        }
        case 'C': {
            network_address[0] = octets[0];
            network_address[1] = octets[1];
            network_address[2] = octets[2];
            network_address[3] = 0;
            subnet_mask[0] = 255;
            subnet_mask[1] = 255;
            subnet_mask[2] = 255;
            subnet_mask[3] = 0;
            break;
        }
        default: {
            printf("Class of IP address %c does not have a subnet mask\n", ip_class);
            return -1;
            break;
        }
    }

    int subnet_bits;
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);
    int num_subnets = pow(2, subnet_bits);
    printf("Number of subnets: %d\n", num_subnets);
    int num_hosts_per_subnet = pow(2, (32-subnet_bits)-2);
    printf("Number of hosts per subnet: %d\n", num_hosts_per_subnet);

    //Calculate subnet number
    int subnet_number = octets[0];
    int subnet_bits_left = subnet_bits - 8;
    if (subnet_bits_left >= 0) {
        subnet_number += pow(2, 8) * octets[1];
    }
    if (subnet_bits_left >= 8) {
        subnet_number += pow(2, 16) * octets[2];
    }
    printf("Subnet number: %d\n", subnet_number);

    //Print network address, subnet mask, and broadcast address for each subnet
    int counter = 0;
    for (i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d:\n", i+1);
        int subnet_num = subnet_number + i * pow(2, (32-subnet_bits));
        int j;
        for (j = 0; j < 4; j++) {
            if (j == 3) {
                printf("%d", subnet_num + counter);
            } else {
                printf("%d.", network_address[j]);
            }
        }
        printf("\nSubnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

        int broadcast_address[4];
        broadcast_address[0] = network_address[0];
        broadcast_address[1] = network_address[1];
        broadcast_address[2] = network_address[2];
        broadcast_address[3] = network_address[3] + pow(2, (32-subnet_bits)) - 1;
        for (j = 0; j < 4; j++) {
            if (j == 3) {
                printf("Broadcast address: %d", broadcast_address[j]);
            } else {
                printf("Broadcast address: %d.", broadcast_address[j]);
            }
        }
        printf("\n");
        counter += num_hosts_per_subnet + 2;
    }
    return 0;
}