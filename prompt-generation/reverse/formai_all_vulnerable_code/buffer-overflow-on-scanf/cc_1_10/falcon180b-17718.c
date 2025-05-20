//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate subnet mask based on IP address and subnet size
char* getSubnetMask(char* ip, int subnetSize) {
    char* mask = malloc(16);
    strcpy(mask, "255.255.255.0");
    // convert IP address to decimal format
    int decimalIp[4] = {0};
    sscanf(ip, "%d.%d.%d.%d", &decimalIp[0], &decimalIp[1], &decimalIp[2], &decimalIp[3]);
    // calculate subnet mask based on subnet size
    int subnetMask = (int)pow(2, 32 - subnetSize) - 1;
    sprintf(mask, "255.255.255.%d", subnetMask);
    return mask;
}

// function to validate IP address format
int isValidIp(char* ip) {
    int count = 0;
    char* token = strtok(ip, ".");
    while (token!= NULL) {
        if (atoi(token) < 0 || atoi(token) > 255) {
            return 0;
        }
        count++;
        token = strtok(NULL, ".");
    }
    if (count!= 4) {
        return 0;
    }
    return 1;
}

int main() {
    char ip[16];
    char subnetMask[16];
    int subnetSize;

    // prompt user for IP address and subnet size
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet size: ");
    scanf("%d", &subnetSize);

    // validate IP address format
    if (!isValidIp(ip)) {
        printf("Invalid IP address format.\n");
        return 1;
    }

    // calculate subnet mask
    char* mask = getSubnetMask(ip, subnetSize);

    // display IP address and subnet mask
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);

    return 0;
}