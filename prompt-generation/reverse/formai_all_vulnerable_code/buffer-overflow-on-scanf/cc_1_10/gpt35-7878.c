//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include<stdio.h>
#include<math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, int binary[]) {
    int index = 0;
    while(decimal > 0) {
        binary[index++] = decimal%2;
        decimal /= 2;
    }
}

// Function to calculate subnet mask in binary
void calculateSubnetMask(int subnetMask[], int prefix) {
    int index = 0;
    while(prefix >= 8) {
        subnetMask[index++] = 255;
        prefix -= 8;
    }
    int power = 7;
    int octet = 0;
    while(prefix > 0) {
        octet += pow(2, power--);
        prefix--;
    }
    subnetMask[index++] = octet;
    while(index < 4) {
        subnetMask[index++] = 0;
    }
}

// Function to calculate maximum number of subnet and hosts per subnet
int calculateMaxSubnet(int prefix) {
    return pow(2, 32 - prefix) - 2;
}

int main() {
    int ip[4], subnetMask[4], binaryIP[32], binarySubnetMask[32], prefix, maxSubnet, maxHosts;
    printf("Enter the IP address in dot-decimal notation:\n");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter the prefix length:\n");
    scanf("%d", &prefix);

    // Convert IP address to binary
    decimalToBinary(ip[0], &binaryIP[0]);
    decimalToBinary(ip[1], &binaryIP[8]);
    decimalToBinary(ip[2], &binaryIP[16]);
    decimalToBinary(ip[3], &binaryIP[24]);

    // Calculate subnet mask in binary
    calculateSubnetMask(binarySubnetMask, prefix);

    // Convert subnet mask to decimal
    subnetMask[0] = binarySubnetMask[0]*128 + binarySubnetMask[1]*64 + binarySubnetMask[2]*32 + binarySubnetMask[3]*16 + binarySubnetMask[4]*8 + binarySubnetMask[5]*4 + binarySubnetMask[6]*2 + binarySubnetMask[7];
    subnetMask[1] = binarySubnetMask[8]*128 + binarySubnetMask[9]*64 + binarySubnetMask[10]*32 + binarySubnetMask[11]*16 + binarySubnetMask[12]*8 + binarySubnetMask[13]*4 + binarySubnetMask[14]*2 + binarySubnetMask[15];
    subnetMask[2] = binarySubnetMask[16]*128 + binarySubnetMask[17]*64 + binarySubnetMask[18]*32 + binarySubnetMask[19]*16 + binarySubnetMask[20]*8 + binarySubnetMask[21]*4 + binarySubnetMask[22]*2 + binarySubnetMask[23];
    subnetMask[3] = binarySubnetMask[24]*128 + binarySubnetMask[25]*64 + binarySubnetMask[26]*32 + binarySubnetMask[27]*16 + binarySubnetMask[28]*8 + binarySubnetMask[29]*4 + binarySubnetMask[30]*2 + binarySubnetMask[31];

    // Calculate maximum number of subnet and hosts per subnet
    maxSubnet = calculateMaxSubnet(prefix);
    maxHosts = pow(2, 32 - prefix) - 2;

    // Print the results
    printf("IP address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Prefix length: %d\n", prefix);
    printf("Maximum number of subnets: %d\n", maxSubnet);
    printf("Maximum number of hosts per subnet: %d\n", maxHosts);

    return 0;
}