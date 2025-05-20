//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include<stdio.h>

int main(){
    printf("Welcome to the Subnet Calculator Program!\n");

    unsigned int ip;
    printf("Enter IP Address in Decimal Format: ");
    scanf("%u",&ip);

    unsigned int mask;
    printf("Enter Subnet Mask in Decimal Format: ");
    scanf("%u",&mask);

    int cidr = 0;
    unsigned int temp = mask;
    while(temp>0){
        if(temp%2!=0){
            cidr++;
        }
        temp = temp/2;
    }

    printf("\nCIDR Notation: /%d\n",cidr);

    unsigned int subnetMask = 0;
    unsigned int bits = 0xFFFFFFFF;
    bits = bits<<(32-cidr);
    subnetMask = bits;

    printf("Subnet Mask in Binary: ");
    int octet = 0;
    for(int i=31;i>=0;i--){
        if(subnetMask&(1<<i)){
            octet++;
            printf("1");
        }
        else{
            printf("0");
        }

        if(octet%8==0 && octet!=32){
            printf(".");
        }
    }
    printf("\n");

    unsigned int networkAddr = ip & subnetMask;
    printf("Network Address: %u\n",networkAddr);

    unsigned int broadcastAddr = ip|(~subnetMask);
    printf("Broadcast Address: %u\n",broadcastAddr);

    printf("\nThank you for using the Subnet Calculator Program!");

    return 0;
}