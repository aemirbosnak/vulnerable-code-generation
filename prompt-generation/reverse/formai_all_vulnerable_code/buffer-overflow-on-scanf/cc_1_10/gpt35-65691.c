//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
/* 
 * C Subnet Calculator Example Program
 * A program to calculate CIDR notation subnet parameters
 * Single-threaded implementation
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_IP_ADDRESS_LEN 15
#define MAX_SUBNET_MASK 32
#define MAX_CIDR_NOTATION_LEN 3

// Function to validate IPv4 address
bool validate_ip_address(char *ip_address) {
    int i, j, k;
    char octet[4];
    int octet_int;
    int dot_count = 0;

    for (i=0, j=0, k=0; ip_address[i]!='\0'; i++) {
        if (ip_address[i] == '.') {
            octet[j] = '\0';
            j = 0;
            dot_count++;
            octet_int = atoi(octet);
            if (octet_int < 0 || octet_int > 255) {
                return false;
            }
            k += sprintf(&ip_address[k], "%d.", octet_int);
        } else if (isdigit(ip_address[i])) {
            octet[j++] = ip_address[i];
        } else {
            return false;
        }
    }

    if (dot_count != 3) {
        return false;
    }

    octet[j] = '\0';
    octet_int = atoi(octet);
    if (octet_int < 0 || octet_int > 255) {
        return false;
    }
    k += sprintf(&ip_address[k], "%d", octet_int);

    if (k != strlen(ip_address)) {
        return false;
    }

    return true;
}

// Function to validate CIDR notation
bool validate_cidr_notation(char *cidr_notation) {
    int i, len;

    len = strlen(cidr_notation);
    if (len < 1 || len > MAX_CIDR_NOTATION_LEN) {
        return false;
    }

    for (i=0; i<len; i++) {
        if (!isdigit(cidr_notation[i])) {
            return false;
        }
    }

    int subnet_mask = atoi(cidr_notation);
    if (subnet_mask < 1 || subnet_mask > MAX_SUBNET_MASK) {
        return false;
    }

    return true;
}

// Function to bitwise AND two IP addresses
char *bitwise_and(char *ip_address_1, char *ip_address_2) {
    static char result[MAX_IP_ADDRESS_LEN+1];
    int i, len;

    len = strlen(ip_address_1);
    memset(result, 0, MAX_IP_ADDRESS_LEN);

    for (i=0; i<len; i++) {
        if (ip_address_1[i] == '.') {
            result[i] = '.';
        } else {
            result[i] = ((ip_address_1[i] - '0') & (ip_address_2[i] - '0')) + '0';
        }
    }

    return result;
}

int main() {
    char ip_address[MAX_IP_ADDRESS_LEN+1];
    char cidr_notation[MAX_CIDR_NOTATION_LEN+1];

    printf("Enter IP address (e.g. 192.168.0.1): ");
    scanf("%s", ip_address);

    if (!validate_ip_address(ip_address)) {
        printf("Invalid IP address\n");
        exit(1);
    }

    printf("Enter CIDR notation (e.g. 24): ");
    scanf("%s", cidr_notation);

    if (!validate_cidr_notation(cidr_notation)) {
        printf("Invalid CIDR notation\n");
        exit(2);
    }

    int subnet_mask = atoi(cidr_notation);

    // Calculate subnet mask based on CIDR notation
    int i, j;
    int octet_num = 1;
    int octet_val = 0;
    char subnet_mask_str[MAX_IP_ADDRESS_LEN+1];
    memset(subnet_mask_str, 0, MAX_IP_ADDRESS_LEN+1);

    for (i=0; i<subnet_mask; i++) {
        if (octet_val == 0) {
            octet_val = 128;
        } else {
            octet_val /= 2;
        }

        if (i == 7 || i == 15 || i == 23) {
            j = sprintf(&subnet_mask_str[strlen(subnet_mask_str)], "%d.", octet_val);
            octet_num++;
            octet_val = 0;
        }
    }

    j = sprintf(&subnet_mask_str[strlen(subnet_mask_str)], "%d", octet_val);

    // Calculate network and broadcast addresses
    char network_address[MAX_IP_ADDRESS_LEN+1];
    memset(network_address, 0, MAX_IP_ADDRESS_LEN+1);

    char broadcast_address[MAX_IP_ADDRESS_LEN+1];
    memset(broadcast_address, 0, MAX_IP_ADDRESS_LEN+1);

    int octet_count = 0;

    char *result = bitwise_and(ip_address, subnet_mask_str);
    for (i=0; i<strlen(result); i++) {
        if (result[i] == '.') {
            octet_num++;
            octet_count = 0;
        } else {
            octet_count++;
        }

        if (octet_num == 4 && octet_count == 1) {
            sprintf(&broadcast_address[i], "255");
            sprintf(&network_address[i], "%c", result[i]);
        } else if (octet_num == 4) {
            sprintf(&broadcast_address[i], "%c", result[i]);
            sprintf(&network_address[i], "%c", result[i]);
        } else {
            sprintf(&broadcast_address[i], "%c", result[i]);
            sprintf(&network_address[i], "%c", result[i]);
        }
    }

    // Print results
    printf("IP address: %s\n", ip_address);
    printf("Subnet mask: %s\n", subnet_mask_str);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);

    return 0;
}