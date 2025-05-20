//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printRomanticHeader() {
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*          Welcome to the Subnet Romance       *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
}

void displaySubnetDetails(const char *ip, const char *subnet, int hosts) {
    printf("\nIn this beautiful encounter, we have:\n");
    printf("Your IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet);
    printf("Total Hosts available in this subnet: %d\n", hosts);
    printf("Yes, your love can reach out to %d lovers in this range.\n", hosts);
}

int calculateSubnetHosts(const char *subnet) {
    int mask;
    sscanf(subnet, "%*d.%*d.%*d.%d", &mask); // Assume subnet is in CIDR format

    // A loving calculation of host addresses
    return (int)(pow(2, (32 - mask)) - 2); // -2 for network and broadcast address
}

int main() {
    char ip[16];
    char subnet[10];
    
    printRomanticHeader();
    
    // A gentle request to share your heart's address
    printf("Please enter your IP Address (e.g., 192.168.1.1): ");
    scanf("%15s", ip);
    
    // Whispering a request for the subnet
    printf("And now, dear, provide your Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%9s", subnet);
    
    // Every love story has a twist; let's invoke the magic of calculations
    int hosts = calculateSubnetHosts(subnet);
    
    // Revealing the results of our calculations
    displaySubnetDetails(ip, subnet, hosts);

    // A sweet farewell
    printf("\nWe may part ways, but our connection transcends distance. Goodbye, dear!\n");
    
    return 0;
}