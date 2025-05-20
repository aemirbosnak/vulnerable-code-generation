//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>

// Function to calculate the subnet mask
void subnet_mask_calculation(int cidr, int *subnet_mask) {
    int bit = 0;
    // Loop to calculate subnet mask bits
    for (int i = 31; i >= 0; i--) {
        if (bit < cidr) {
            subnet_mask[i] = 1;
            bit++;
        } else {
            subnet_mask[i] = 0;
        }
    }
}

// Function to validate user input for IP address and CIDR block
int validate_input(char *ip_address, int cidr_block) {
    // Splitting the IP address into individual octects
    int a, b, c, d;
    if (sscanf(ip_address, "%d.%d.%d.%d", &a, &b, &c, &d) == 4) {
        if (a >= 0 && a <= 255 && b >= 0 && b <= 255 && c >= 0 &&
            c <= 255 && d >= 0 && d <= 255 && cidr_block >= 0 && cidr_block <= 32) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Taking input from user
    char ip_address[50];
    int cidr_block;
    printf("Enter the IP Address with CIDR Block (Example: 192.168.1.1/24)\n");
    scanf("%s", ip_address);
    scanf("/%d", &cidr_block);
    // Validating user input
    if (!validate_input(ip_address, cidr_block)) {
        printf("Invalid Input, Please try again\n");
        return 0;
    }

    int subnet_mask[32] = {0};
    int index = 31;
    // Calling the function to calculate the subnet mask
    subnet_mask_calculation(cidr_block, subnet_mask);

    printf("The Subnet Mask for %s/%d is ", ip_address, cidr_block);
    // Printing the subnet mask
    for (int i = 0; i < 4; i++) {
        int octect = 0;
        for (int j = 0; j < 8; j++) {
            octect += subnet_mask[index--] * pow(2, j);
        }
        printf("%d", octect);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");

    return 0;
}