//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int class, subnet;
    int subnetMask[4] = {0};
    printf("Welcome to the subnet calculator! Let's get started!\n");

    // User input for the class of the network
    printf("Enter the class of your network (A, B, or C): ");
    scanf("%c", &class);

    // User input for the desired subnet
    printf("Enter the desired subnet: ");
    scanf("%d", &subnet);

    // Calculating subnet mask based on class and subnet
    if(class == 'A') {
        subnetMask[0] = 255;
        if(subnet == 1) {
            subnetMask[1] = 0;
            subnetMask[2] = 0;
            subnetMask[3] = 0;
        }
        else if(subnet == 2) {
            subnetMask[1] = 128;
            subnetMask[2] = 0;
            subnetMask[3] = 0;
        }
        else if(subnet == 3) {
            subnetMask[1] = 192;
            subnetMask[2] = 0;
            subnetMask[3] = 0;
        }
        else {
            printf("Invalid input. Please try again.\n");
            return 0;
        }
    }
    else if(class == 'B') {
        subnetMask[0] = 255;
        subnetMask[1] = 255;
        if(subnet == 1) {
            subnetMask[2] = 0;
            subnetMask[3] = 0;
        }
        else if(subnet == 2) {
            subnetMask[2] = 128;
            subnetMask[3] = 0;
        }
        else if(subnet == 3) {
            subnetMask[2] = 192;
            subnetMask[3] = 0;
        }
        else {
            printf("Invalid input. Please try again.\n");
            return 0;
        }
    }
    else if(class == 'C') {
        subnetMask[0] = 255;
        subnetMask[1] = 255;
        subnetMask[2] = 255;
        if(subnet == 1) {
            subnetMask[3] = 0;
        }
        else if(subnet == 2) {
            subnetMask[3] = 128;
        }
        else if(subnet == 3) {
            subnetMask[3] = 192;
        }
        else {
            printf("Invalid input. Please try again.\n");
            return 0;
        }
    }
    else {
        printf("Invalid input. Please try again.\n");
        return 0;
    }

    // Outputting the subnet mask
    printf("The subnet mask for the class %c network with subnet %d is %d.%d.%d.%d\n", class, subnet, subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

    return 0;
}