//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int subnetSize(int prefix) {
    return 1 << (32 - prefix);
}

void printSubnetMask(int prefix) {
    int mask = (~0) << (32 - prefix);
    printf("Subnet Mask: %d.%d.%d.%d\n", (mask>>24)&0xff, (mask>>16)&0xff, (mask>>8)&0xff, mask&0xff);
}

void printSubnet(char* ip, int prefix, int subNum) {
    int mask = (~0) << (32 - prefix);
    int subSize = subnetSize(prefix);
    int subMask = subSize - 1;
    int firstSub = subNum * subSize;
    int firstIp1 = atoi(strtok(ip, "."));
    int firstIp2 = atoi(strtok(NULL, "."));
    int firstIp3 = atoi(strtok(NULL, "."));
    int firstIp4 = atoi(strtok(NULL, "."));
    firstIp4 += firstSub & 0xff;
    firstIp3 += (firstSub>>8) & 0xff;
    firstIp2 += (firstSub>>16) & 0xff;
    firstIp1 += firstSub>>24;
    printf("Subnet %d: %d.%d.%d.%d/%d (", subNum+1, firstIp1, firstIp2, firstIp3, firstIp4, prefix);
    printSubnetMask(prefix);
    printf(")\n");
}

int main() {
    char ip[16];
    int prefix, subNum, subCount;

    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Subnet Prefix Length: ");
    scanf("%d", &prefix);
    printf("Enter Number of Subnets: ");
    scanf("%d", &subCount);
    printf("\n");

    int subSize = subnetSize(prefix);
    if (subSize > subCount) {
        printf("Error: Subnet size greater than number of subnets\n");
        return 1;
    }

    printSubnetMask(prefix);
    printf("\n");

    for (subNum = 0; subNum < subCount; subNum++) {
        printSubnet(ip, prefix, subNum);
    }

    return 0;
}