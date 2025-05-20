//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char ip[50], subnet[50];
    int subnet_cidr, subnet_mask[4], subnet_bits[32];
    int i, j, b, m, n, x, k = 0;
    unsigned long int subnet_decimal = 0, subnet_size = 0;

    printf("Enter IP address: ");
    scanf("%s", ip);

    // Extracting subnet mask in CIDR notation
    printf("Enter Subnet mask in CIDR notation: ");
    scanf("%d", &subnet_cidr);

    // Converting Subnet CIDR notation to binary format
    for(i=0; i<32; i++){
        subnet_bits[i] = (i<subnet_cidr) ? 1 : 0;
    }

    // Storing Subnet IP in decimal format
    for(i=0; i<4; i++){
        x = 0;
        for(j=0; j<8; j++){
            x = (x << 1) + subnet_bits[k++];
        }
        subnet_mask[i] = x;
        subnet_decimal = (subnet_decimal << 8) + x;
    }
    
    // Calculating Subnet Size
    for (i=0; i<4; i++){
        for (j=7; j>=0; j--){
            if ((unsigned char)(subnet_mask[i] << j) >> 7){
                subnet_size = 1;
            }
            else{
                printf("Error: Invalid subnet mask input.\n");
                return 0;
            }
        }
    }

    // Reporting the Input IP, Subnet Mask and Subnet Size
    printf("\n\nEntered IP: %s\n", ip);
    printf("Entered Subnet Mask: %d.%d.%d.%d/%d\n", subnet_mask[0],subnet_mask[1],subnet_mask[2],subnet_mask[3], subnet_cidr);
    printf("Calculated Subnet Size: %lu\n", subnet_size);

    return 0;
}