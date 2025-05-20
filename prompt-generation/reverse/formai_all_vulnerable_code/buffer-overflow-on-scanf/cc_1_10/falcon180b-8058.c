//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a valid IP address
int is_valid_ip(char *ip) {
    int i, j;
    char *ptr;
    int num_parts = 0;

    ptr = strtok(ip, ".");
    while (ptr!= NULL) {
        num_parts++;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return 0;
            }
        }
        ptr = strtok(NULL, ".");
    }

    if (num_parts!= 4) {
        return 0;
    }

    return 1;
}

// Function to calculate the subnet mask based on the given IP address and netmask
void calculate_subnet(char *ip, char *netmask, char *subnet) {
    int i, j, k;
    char *ptr;
    int num_parts = 0;

    ptr = strtok(ip, ".");
    while (ptr!= NULL) {
        num_parts++;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return;
            }
        }
        ptr = strtok(NULL, ".");
    }

    if (num_parts!= 4) {
        return;
    }

    ptr = strtok(netmask, ".");
    while (ptr!= NULL) {
        num_parts = 0;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return;
            }
        }
        num_parts++;
        ptr = strtok(NULL, ".");
    }

    if (num_parts!= 4) {
        return;
    }

    strcpy(subnet, ip);
    ptr = strtok(subnet, ".");
    while (ptr!= NULL) {
        num_parts = 0;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return;
            }
        }
        num_parts++;
        ptr = strtok(NULL, ".");
    }

    if (num_parts!= 4) {
        return;
    }

    for (i = 0; i < strlen(netmask); i++) {
        if (netmask[i] == '.') {
            for (j = 0; j < 3; j++) {
                subnet[i + j] = '.';
            }
        } else {
            subnet[i] = netmask[i];
        }
    }

    printf("Subnet mask: %s\n", subnet);
}

int main() {
    char ip[16], netmask[16];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter netmask: ");
    scanf("%s", netmask);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address\n");
        return 0;
    }

    if (!is_valid_ip(netmask)) {
        printf("Invalid netmask\n");
        return 0;
    }

    calculate_subnet(ip, netmask, "subnet");

    return 0;
}