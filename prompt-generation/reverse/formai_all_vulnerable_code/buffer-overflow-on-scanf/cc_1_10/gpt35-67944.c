//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void subnet_calculator(){

    printf("\nWelcome to the Crazy Subnet Calculator!\n\n");

    char ipAddress[15];
    int subnetBits;
    char subnetMask[15];
    char Class;

    printf("\nEnter the IP address you want to calculate in dotted decimal format (eg: 192.168.1.1) : ");
    scanf("%s", ipAddress);

    printf("\nHow many bits do you want to use to subnet this network? : ");
    scanf("%d", &subnetBits);

    if(subnetBits > 32)
    {
        printf("\nOh boy! That subnet mask ain't gonna work! Enter a number between 1 and 32 : ");
        scanf("%d",&subnetBits);
    }

    printf("\nCalculating.......\n");

    /* crazy subnet calculations */
    if (subnetBits >= 0 && subnetBits <= 7){
        strcpy(subnetMask,"255.0.0.0");
        Class = 'A';
    }
    else if (subnetBits >= 8 && subnetBits <= 15){
        strcpy(subnetMask,"255.255.0.0");
        Class = 'B';
    }
    else if (subnetBits >= 16 && subnetBits <= 23){
        strcpy(subnetMask,"255.255.255.0");
        Class = 'C';
    }
    else if (subnetBits >= 24 && subnetBits <= 31){
        strcpy(subnetMask,"255.255.255.128");
        Class = 'C';
    }
    else {
        printf("\nSorry we cannot calculate it as of now. Please select between 0-32 Bits only.\n");
        exit(0);
    }

    printf("\nYour IP address: %s", ipAddress);
    printf("\nYour subnet mask: %s", subnetMask);
    printf("\nYour class: Class %c", Class);

    printf("\n\nThis is the end of the Crazy Subnet Calculator! Thank you for using it!");

}

int main(){

    subnet_calculator();

    return 0;
}