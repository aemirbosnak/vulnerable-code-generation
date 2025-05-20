//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("Welcome to the Cyberpunk Subnet Calculator!\n\n");

    char ip_address[15];
    int subnet_mask;

    //Requesting the IP address and Subnet Mask from the user
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter subnet mask: ");
    scanf("%d", &subnet_mask);

    char *token;
    int octet[4];
    int i = 0;

    token = strtok(ip_address, ".");

    //Parsing the IP address
    while(token != NULL){
        octet[i] = atoi(token);
        i++;
        token = strtok(NULL, ".");
    }

    int subnet_octet = subnet_mask/8;
    int remaining_bits = subnet_mask%8;

    //Calculating the number of hosts using the formula (2^(8-remaining_bits))-2
    int num_hosts = (1 << (8-remaining_bits))-2;
    
    printf("\nIP Address: %d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_octet == 1 ? 255 : subnet_octet == 2 ? 255 : subnet_octet == 3 ? 255 : octet[0], 
                                    subnet_octet == 2 ? 255 : subnet_octet == 3 ? 255 : octet[1], 
                                    subnet_octet == 3 ? 255 : octet[2], 
                                    remaining_bits == 0 ? 0 : remaining_bits == 1 ? 128 : remaining_bits == 2 ? 192 : remaining_bits == 3 ? 224 : remaining_bits == 4 ? 240 : remaining_bits == 5 ? 248 : remaining_bits == 6 ? 252 : 254);
    printf("Network Address: %d.%d.%d.%d\n", octet[0] & (subnet_octet == 1 ? 255 : subnet_octet == 2 ? 255 : subnet_octet == 3 ? 255 : octet[0]), 
                                              octet[1] & (subnet_octet == 2 ? 255 : subnet_octet == 3 ? 255 : octet[1]), 
                                              octet[2] & (subnet_octet == 3 ? 255 : octet[2]), 
                                              octet[3] & (remaining_bits == 0 ? 0 : remaining_bits == 1 ? 128 : remaining_bits == 2 ? 192 : remaining_bits == 3 ? 224 : remaining_bits == 4 ? 240 : remaining_bits == 5 ? 248 : remaining_bits == 6 ? 252 : 254));
    printf("Broadcast Address: %d.%d.%d.%d\n", octet[0] | (subnet_octet == 1 ? 0 : subnet_octet == 2 ? 0 : subnet_octet == 3 ? 0 : ~octet[0]), 
                                                octet[1] | (subnet_octet == 2 ? 0 : subnet_octet == 3 ? 0 : ~octet[1]), 
                                                octet[2] | (subnet_octet == 3 ? 0 : ~octet[2]), 
                                                octet[3] | (remaining_bits == 0 ? 255 : remaining_bits == 1 ? 127 : remaining_bits == 2 ? 63 : remaining_bits == 3 ? 31 : remaining_bits == 4 ? 15 : remaining_bits == 5 ? 7 : remaining_bits == 6 ? 3 : 1));
    printf("Number of Hosts: %d\n\n", num_hosts);

    return 0;
}