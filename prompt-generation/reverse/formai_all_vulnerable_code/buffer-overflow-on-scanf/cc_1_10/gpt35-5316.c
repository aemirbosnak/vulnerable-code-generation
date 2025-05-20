//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert subnet mask from CIDR notation to dotted decimal format
void cidr_to_mask(int prefix, char* mask){
    // initializing mask array with 32 length
    int i, j, c;
    for (i=0; i<32; i++){
        mask[i] = '0';
    }

    // setting prefix number of bits to 1 in subnet mask
    for (j=0; j<prefix; j++){
        mask[j] = '1';
    }

    // converting subnet mask to dotted decimal format
    for (i=0; i<4; i++){
        c = 0;
        for (j=0; j<8; j++){
            c = c*2 + (mask[i*8+j] - '0');
        }
        sprintf(mask+strlen(mask), "%d", c);
        if (i!=3){
            strcat(mask, ".");
        }
    }
}

// Function to calculate network address from IP and subnet mask
void calculate_network_address(char* ip_address, char* subnet_mask, char* network_address){
    char *token1, *token2;
    int i, c1, c2;
    char temp[4];

    // extracting octets from IP address and subnet mask
    for (i=0; i<4; i++){
        // extracting octet from IP address
        token1 = strtok_r(ip_address, ".", &ip_address);
        c1 = atoi(token1);
        
        // extracting octet from subnet mask
        strcpy(temp, "");
        token2 = strtok_r(subnet_mask, ".", &subnet_mask);
        c2 = atoi(token2);
        
        // calculating octet of network address
        sprintf(temp, "%d", c1 & c2);
        strcat(network_address, temp);
        if (i!=3){
            strcat(network_address, ".");
        }
    }
}

int main(){
    char ip_address[15], subnet_mask[18], network_address[16];
    int prefix;
    char mask[33];

    // getting IP address, prefix and calculating subnet mask
    printf("Enter the IPv4 address (in dotted decimal format): ");
    scanf("%s", ip_address);
    printf("Enter the prefix (e.g. 24 for 255.255.255.0): ");
    scanf("%d", &prefix);
    cidr_to_mask(prefix, mask);
    strcpy(subnet_mask, mask);

    // displaying subnet mask
    printf("\nThe subnet mask is: %s\n\n", subnet_mask);

    // calculating and displaying network address
    strcpy(network_address, "");
    calculate_network_address(ip_address, subnet_mask, network_address);
    printf("The network address is: %s\n", network_address);

    return 0;
}