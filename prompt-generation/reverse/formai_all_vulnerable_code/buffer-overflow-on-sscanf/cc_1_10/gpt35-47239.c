//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isValidIP(char *ip_address);
bool isValidCIDR(char *cidr);
int parseOctet(char *octet);
void calculateMask(int cidr, char* mask);
void calculateNetworkAddress(char *ip_address, char *mask, char *network_address);
void calculateBroadcastAddress(char *ip_address, char *mask, char *broadcast_address);
void printResults(char *ip_address, char *mask, char *network_address, char *broadcast_address);

int main(int argc, char *argv[]) {
    char ip_address[20], cidr[5], mask[20], network_address[20], broadcast_address[20];

    // check if user has entered 2 arguments only
    if (argc != 2) {
        printf("Usage: ./subnet_calculator <ip_address>/<cidr>\n");
        return 1;
    }

    // copy IP address and CIDR from argument to respective variables
    sscanf(argv[1], "%[^/]/%s", ip_address, cidr);

    // check if user entered a valid IP address and CIDR
    if (!isValidIP(ip_address)) {
        printf("Invalid IP address.\n");
        return 1;
    } else if (!isValidCIDR(cidr)) {
        printf("Invalid CIDR notation.\n");
        return 1;
    }

    // calculate mask, network address and broadcast address
    calculateMask(atoi(cidr), mask);
    calculateNetworkAddress(ip_address, mask, network_address);
    calculateBroadcastAddress(ip_address, mask, broadcast_address);

    // print results
    printResults(ip_address, mask, network_address, broadcast_address);

    return 0;
}

// check if the IP address is valid or not
bool isValidIP(char *ip_address) {
    int i, octet;

    // check if the IP address contains 4 octets separated by dots
    if (sscanf(ip_address, "%d.%d.%d.%d", &octet, &octet, &octet, &octet) != 4) {
        return false;
    }

    // check if each octet is between 0 and 255 inclusive
    for (i = 0; i < 4; i++) {
        octet = parseOctet(strtok(i == 0 ? ip_address : NULL, "."));

        if (octet < 0 || octet > 255) {
            return false;
        }
    }

    return true;
}

// check if the CIDR notation is valid or not
bool isValidCIDR(char *cidr) {
    int i, cidr_value;

    cidr_value = atoi(cidr);

    // check if the CIDR notation is between 0 and 32 inclusive
    if (cidr_value < 0 || cidr_value > 32) {
        return false;
    }

    // check if the CIDR notation is a power of 2
    for (i = 0; i < 32; i++) {
        if (cidr_value == pow(2, i)) {
            return true;
        }
    }

    return false;
}

// parse octet and return its integer value
int parseOctet(char *octet) {
    char *pEnd;
    return (int) strtol(octet, &pEnd, 10);
}

// calculate mask from CIDR notation
void calculateMask(int cidr, char* mask) {
    int i, j;

    strcpy(mask, "");

    for (i = 0; i < cidr; i++) {
        j = i % 8;

        if (j == 0) {
            strcat(mask, ".");
        }

        strcat(mask, "1");
    }

    // pad mask with zeros to make it a 32-bit binary number
    while (strlen(mask) < 32) {
        strcat(mask, "0");
    }

    // convert mask to dotted decimal notation
    for (i = 0; i < 4; i++) {
        sprintf(strstr(mask, "1") - 1, "%d", strtol(strtok(i == 0 ? mask : NULL, "."), NULL, 2));
    }
}

// calculate network address from IP address and mask
void calculateNetworkAddress(char *ip_address, char *mask, char *network_address) {
    int i, octet, mask_octet, network_octet;

    for (i = 0; i < 4; i++) {
        octet = parseOctet(strtok(i == 0 ? ip_address : NULL, "."));
        mask_octet = parseOctet(strtok(i == 0 ? mask : NULL, "."));
        network_octet = octet & mask_octet;
        sprintf(strstr(network_address, "\0"), "%d.", network_octet);
    }

    // remove extra dot at the end
    *(strstr(network_address, "\0") - 1) = '\0';
}

// calculate broadcast address from IP address and mask
void calculateBroadcastAddress(char *ip_address, char *mask, char *broadcast_address) {
    int i, octet, mask_octet, broadcast_octet;

    for (i = 0; i < 4; i++) {
        octet = parseOctet(strtok(i == 0 ? ip_address : NULL, "."));
        mask_octet = parseOctet(strtok(i == 0 ? mask : NULL, "."));
        broadcast_octet = octet | (~mask_octet & 0xff);
        sprintf(strstr(broadcast_address, "\0"), "%d.", broadcast_octet);
    }

    // remove extra dot at the end
    *(strstr(broadcast_address, "\0") - 1) = '\0';
}

// print the calculated results
void printResults(char *ip_address, char *mask, char *network_address, char *broadcast_address) {
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
}