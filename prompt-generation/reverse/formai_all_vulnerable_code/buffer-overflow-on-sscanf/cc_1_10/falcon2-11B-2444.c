//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

/* Function to calculate the subnet mask for a given IP address */
char* getSubnetMask(char* ip)
{
    // Convert the IP address to binary format
    char* binaryIP = (char*)malloc(32 * sizeof(char));
    char* binaryMask = (char*)malloc(32 * sizeof(char));

    // Convert IP to binary format
    int ipBytes[4];
    char* ipBin = ip;
    for (int i = 0; i < 4; i++) {
        sscanf(ipBin, "%x", &ipBytes[i]);
        sprintf(binaryIP + (i * 8), "%d", ipBytes[i]);
    }

    // Convert subnet mask to binary format
    int maskBytes[4];
    char* maskBin = ip;
    for (int i = 0; i < 4; i++) {
        sscanf(maskBin, "%x", &maskBytes[i]);
        sprintf(binaryMask + (i * 8), "%d", maskBytes[i]);
    }

    // Calculate the subnet mask
    char* subnetMask = (char*)malloc(32 * sizeof(char));
    for (int i = 0; i < 32; i++) {
        if (binaryMask[i] == '1') {
            subnetMask[i] = '1';
        } else {
            subnetMask[i] = '0';
        }
    }

    return subnetMask;
}

/* Function to calculate the CIDR (Classless Inter-Domain Routing) value for a given IP address */
char* getCIDR(char* ip)
{
    // Convert the IP address to binary format
    char* binaryIP = (char*)malloc(32 * sizeof(char));
    char* binaryCIDR = (char*)malloc(32 * sizeof(char));

    // Convert IP to binary format
    int ipBytes[4];
    char* ipBin = ip;
    for (int i = 0; i < 4; i++) {
        sscanf(ipBin, "%x", &ipBytes[i]);
        sprintf(binaryIP + (i * 8), "%d", ipBytes[i]);
    }

    // Convert CIDR value to binary format
    int cidrBytes[4];
    char* cidrBin = ip;
    for (int i = 0; i < 4; i++) {
        sscanf(cidrBin, "%x", &cidrBytes[i]);
        sprintf(binaryCIDR + (i * 8), "%d", cidrBytes[i]);
    }

    // Calculate the CIDR value
    char* cidrValue = (char*)malloc(32 * sizeof(char));
    for (int i = 0; i < 32; i++) {
        if (binaryCIDR[i] == '1') {
            cidrValue[i] = '1';
        } else {
            cidrValue[i] = '0';
        }
    }

    return cidrValue;
}

int main()
{
    // Example usage
    char* ip = "192.168.0.1";
    char* subnetMask = getSubnetMask(ip);
    char* cidrValue = getCIDR(ip);

    printf("Subnet mask: %s\n", subnetMask);
    printf("CIDR value: %s\n", cidrValue);

    return 0;
}