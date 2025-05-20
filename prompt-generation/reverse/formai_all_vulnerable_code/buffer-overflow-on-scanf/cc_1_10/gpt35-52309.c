//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <math.h>

int validateInput(int input, int min, int max) {
    if (input < min || input > max) {
        printf("Invalid input. Please enter a value between %d and %d\n", min, max);
        return 0;
    }
    return 1;
}

void printBinary(unsigned int binary, int bits) {
    int i;
    for (i = bits - 1; i >= 0; i--) {
        printf("%d", (binary >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
}

int main() {
    unsigned int ip, subnet;
    int prefix, cidr, num_hosts;

    // Get IP address
    printf("Enter IP address (in decimal form): ");
    scanf("%u", &ip);

    // Get subnet mask
    printf("Enter subnet mask (in decimal form): ");
    scanf("%u", &subnet);

    // Validate input
    if (!validateInput(ip, 0, 4294967295) || !validateInput(subnet, 0, 4294967295)) {
        return 1;
    }

    // Calculate prefix length
    cidr = 0;
    while (subnet % 2 == 0) {
        cidr++;
        subnet /= 2;
    }
    prefix = cidr + (int)log2(subnet);
    if (prefix < 0 || prefix > 32) {
        printf("Invalid subnet mask. Please enter a valid subnet mask\n");
        return 1;
    }

    // Calculate number of host bits
    num_hosts = pow(2, 32 - prefix) - 2;

    // Output results
    printf("\nIP address: ");
    printBinary(ip, 32);
    printf("\nSubnet mask: ");
    printBinary(subnet, 32);
    printf("\nPrefix length: %d\n", prefix);
    printf("Number of host bits: %d\n", 32 - prefix);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}