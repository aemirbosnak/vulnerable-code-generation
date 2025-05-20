//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char ip[16];
    int mask;

    printf("Welcome to the Unique Subnet Calculator\n");
    printf("Enter IP Address (e.g. 192.168.1.1): ");
    scanf("%s", ip);

    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    scanf("%d", &mask);

    printf("\nCalculating...\n");

    int octet1 = atoi(strtok(ip, "."));
    int octet2 = atoi(strtok(NULL, "."));
    int octet3 = atoi(strtok(NULL, "."));
    int octet4 = atoi(strtok(NULL, "."));

    int binaryMask[32];
    int i;

    for(i=0; i<32; i++){
        if(i < mask){
            binaryMask[i] = 1;
        }
        else{
            binaryMask[i] = 0;
        }
    }

    int subnetOctet1 = 0;
    int subnetOctet2 = 0;
    int subnetOctet3 = 0;
    int subnetOctet4 = 0;

    for(i=0; i<8; i++){
        if(binaryMask[i] == 1){
            subnetOctet1 += (1 << (7-i));
        }
    }

    for(i=8; i<16; i++){
        if(binaryMask[i] == 1){
            subnetOctet2 += (1 << (7-(i-8)));
        }
    }

    for(i=16; i<24; i++){
        if(binaryMask[i] == 1){
            subnetOctet3 += (1 << (7-(i-16)));
        }
    }

    for(i=24; i<32; i++){
        if(binaryMask[i] == 1){
            subnetOctet4 += (1 << (7-(i-24)));
        }
    }

    subnetOctet1 = octet1 & subnetOctet1;
    subnetOctet2 = octet2 & subnetOctet2;
    subnetOctet3 = octet3 & subnetOctet3;
    subnetOctet4 = octet4 & subnetOctet4;

    printf("\nSubnet Address: %d.%d.%d.%d\n", subnetOctet1, subnetOctet2, subnetOctet3, subnetOctet4);

    return 0;

}