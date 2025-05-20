//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <math.h>

// function to convert decimal number to binary
void DecimalToBinary(int decimalNumber, int binary[]) {
    int i = 0;
    while (decimalNumber > 0) {
        binary[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
}

// function to convert binary number to decimal
int BinaryToDecimal(int binary[]) {
    int decimalNumber = 0;
    int base = 1;
    for (int i = 0; i < 8; i++) {
        decimalNumber += binary[i] * base;
        base *= 2;
    }
    return decimalNumber;
}

int main() {
    int ipAddress[4];
    int subnetMask[4];
    int networkAddress[4];
    int hostAddress[4];
    int binarySubnetMask[32];
    int prefixLength;
    int binaryIpAddress[32];

    // get input from user
    printf("Enter IP Address (Format: A.B.C.D): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    printf("\nEnter Subnet Mask (Format: A.B.C.D): ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    // convert ip address and subnet mask to binary
    DecimalToBinary(ipAddress[0], &binaryIpAddress[0]);
    DecimalToBinary(ipAddress[1], &binaryIpAddress[8]);
    DecimalToBinary(ipAddress[2], &binaryIpAddress[16]);
    DecimalToBinary(ipAddress[3], &binaryIpAddress[24]);

    DecimalToBinary(subnetMask[0], &binarySubnetMask[0]);
    DecimalToBinary(subnetMask[1], &binarySubnetMask[8]);
    DecimalToBinary(subnetMask[2], &binarySubnetMask[16]);
    DecimalToBinary(subnetMask[3], &binarySubnetMask[24]);

    // calculate prefix length
    for (int i = 0; i < 32; i++) {
        if (binarySubnetMask[i] == 1) {
            prefixLength++;
        }
    }

    // calculate network address and host address
    for (int i = 0; i < 32; i++) {
        if (i < prefixLength) {
            networkAddress[i/8] += pow(2, (7 - (i % 8)));
        } else {
            hostAddress[i/8] += binaryIpAddress[i] * pow(2, (7 - (i % 8)));
        }
    }

    // print the output in a medieval style
    printf("\nThe IP Address %d.%d.%d.%d with a Subnet Mask of %d.%d.%d.%d has a Network Address of %d.%d.%d.%d\n",
        ipAddress[0],ipAddress[1],ipAddress[2],ipAddress[3],
        subnetMask[0],subnetMask[1],subnetMask[2],subnetMask[3],
        networkAddress[0],networkAddress[1],networkAddress[2],networkAddress[3]);

    printf("And the Host Address of %d.%d.%d.%d\n",
        hostAddress[0],hostAddress[1],hostAddress[2],hostAddress[3]);

    return 0;
}