//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary string
void decimalToBinary(int n, char *binaryRep) {
    for (int i = 7; i >= 0; i--) {
        binaryRep[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binaryRep[8] = '\0'; // null-terminate the string
}

// Function to compute subnet mask and available hosts
void calculateSubnet(char *ipAddr, int cidr) {
    int subnetMask[4] = {0};
    int hosts;
    char binaryMask[35] = "";
    
    // Compute the subnet mask in decimal
    for (int i = 0; i < 4; i++) {
        if (cidr >= 8) {
            subnetMask[i] = 255;
            cidr -= 8;
        } else {
            subnetMask[i] = (int)(255 << (8 - cidr)) & 255;
            break;
        }
    }

    // Determine the number of hosts
    hosts = (int)(pow(2, (32 - (cidr)))) - 2; // -2 for network and broadcast
    
    // Construct binary representation of the subnet mask
    for (int i = 0; i < 4; i++) {
        char binaryByte[9];
        decimalToBinary(subnetMask[i], binaryByte);
        strcat(binaryMask, binaryByte);
        if (i < 3) strcat(binaryMask, ".");
    }

    // Print the results
    printf("Ollie the Owl says:\n");
    printf("With the IP Address '%s' and CIDR '/%d'\n", ipAddr, cidr);
    printf("The subnet mask is: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("The binary representation of the subnet mask is: %s\n", binaryMask);
    printf("Total available hosts: %d\n\n", hosts);
}

// Function to guide Squeaky the Squirrel
void guideSqueaky() {
    char ipAddr[16];
    int cidr;

    printf("Squeaky the Squirrel approached Ollie the Owl.\n");
    printf("Ollie looked wise and asked: 'What is the IP address you want to use?'\n");
    printf("Enter the IP address (format x.x.x.x): ");
    scanf("%15s", ipAddr);
    
    printf("Ollie continued: 'And what is the CIDR notation?'\n");
    printf("Enter the CIDR (1-32): ");
    scanf("%d", &cidr);
    
    if (cidr < 1 || cidr > 32) {
        printf("Ollie warns: 'That CIDR notation is out of range. It should be between 1 and 32.'\n");
        return;
    }

    // Now, calculate the subnet
    calculateSubnet(ipAddr, cidr);
}

int main() {
    printf("Welcome to Squeaky's Subnet Calculator!\n");
    printf("Join Squeaky and Ollie on their networking adventure!\n");

    while (1) {
        guideSqueaky();
        
        char continueChoice;
        printf("Does Squeaky wish to continue calculating? (Y/N): ");
        getchar(); // Clear the input buffer
        scanf("%c", &continueChoice);
        
        if (continueChoice != 'Y' && continueChoice != 'y') {
            printf("Squeaky thanks Ollie and runs off into the sunset!\n");
            break;
        }
    }
    return 0;
}