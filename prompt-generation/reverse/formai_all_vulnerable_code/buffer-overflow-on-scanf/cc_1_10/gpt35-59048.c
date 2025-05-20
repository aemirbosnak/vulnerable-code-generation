//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include<stdio.h>
#include<stdlib.h>

#define MAX_IP_LEN 16  // Maximum IP address length
#define BINARY_STR_LEN 9  // Length of binary string for each octet
#define OCTET_COUNT 4  // Number of octets in IP address

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binaryStr) {
    int i;
    for(i=BINARY_STR_LEN-1; i>=0; i--){
        if(decimal%2 == 0)
            binaryStr[i] = '0';
        else
            binaryStr[i] = '1';
        decimal = decimal/2;
    }
}

int main() {
    char ip[MAX_IP_LEN];  // To store IP address entered by the user
    int subnetMask;  // To store the subnet mask entered by the user
    int octets[OCTET_COUNT]; // To store the octets of IP address
    int i,j;
    char binaryStr[BINARY_STR_LEN+1];  // To store binary string of each octet
    
    // Getting inputs from user
    printf("Enter IP address (in format xxx.xxx.xxx.xxx): ");
    scanf("%s",ip);
    printf("Enter subnet mask (in bits): ");
    scanf("%d",&subnetMask);
    
    // Parsing IP address into octets
    char* temp = strtok(ip,".");
    i=0;
    while(temp != NULL && i<OCTET_COUNT){
        octets[i++] = atoi(temp);
        temp = strtok(NULL, ".");
    }
    
    // Calculating subnet mask
    int maskBits = 0;
    int subnetOctetIndex = subnetMask/8;
    int subnetOctetOffset = subnetMask%8;
    int subnetOctetValue = 0;
    
    // Setting subnet bits in respective octet
    for(i=0; i<OCTET_COUNT; i++){
        if(i < subnetOctetIndex){
            octets[i] = 255;
            maskBits += 8;
        }
        else if(i == subnetOctetIndex){
            for(j=BINARY_STR_LEN-1; j>=BINARY_STR_LEN-subnetOctetOffset; j--){
                binaryStr[j] = '1';
                subnetOctetValue += 1<<(BINARY_STR_LEN-j-1);
            }
            decimalToBinary(subnetOctetValue, binaryStr);
            octets[i] = subnetOctetValue;
            maskBits += subnetOctetOffset;
        }
        else{
            octets[i] = 0;
        }
    }
    
    // Displaying subnet information
    printf("\nSubnet Information\n");
    printf("Subnet Mask: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
    printf("Number of Hosts: %d\n", (int)pow(2.0, 32-maskBits)-2);
    
    return 0;
}