//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include<stdio.h>
#include<stdlib.h>

/*Function to calculate the subnet mask*/
void subnet_mask(int prefix, int* mask) {
    int bits_set = 0xFFFFFFFF << (32 - prefix);
    mask[0] = (bits_set>>24) & 0xff;
    mask[1] = (bits_set>>16) & 0xff;
    mask[2] = (bits_set>>8) & 0xff;
    mask[3] = bits_set & 0xff;
}

int main() {
    int prefix, mask[4], octet[4], network[4], broadcast[4];
    char ch;
    printf("====================================\n");
    printf("|  Welcome to Retro Subnet Calculator |\n");
    printf("====================================\n");

    while(1){
        printf("\nEnter an IP address (format: 192.168.1.1): ");
        scanf("%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]); //getting input from user
        if(octet[0]>255 || octet[1]>255 || octet[2]>255 || octet[3]>255){
            printf("Invalid Input! Please enter valid IP address.\n");
            continue;
        }
        printf("Enter the CIDR prefix: ");
        scanf("%d", &prefix); //getting input from user
        if(prefix<1 || prefix>32){
            printf("Invalid Input! Please enter CIDR prefix between 1 to 32.\n");
            continue;
        }

        subnet_mask(prefix, mask); //calling function to calculate subnet mask

        /*Calculating Network Address*/
        network[0] = octet[0] & mask[0];
        network[1] = octet[1] & mask[1];
        network[2] = octet[2] & mask[2];
        network[3] = octet[3] & mask[3];

        /*Calculating Broadcast Address*/
        broadcast[0] = network[0] | (~mask[0] & 0xff);
        broadcast[1] = network[1] | (~mask[1] & 0xff);
        broadcast[2] = network[2] | (~mask[2] & 0xff);
        broadcast[3] = network[3] | (~mask[3] & 0xff);

        /*Printing the results*/
        printf("\nNetwork Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
        printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
        printf("Subnet Mask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);

        printf("\nDo you want to calculate another subnet? Press 'y' or 'n': \n");
        scanf(" %c", &ch); //getting input from user to continue or not

        if(ch=='n' || ch=='N')
            break;
    }
    printf("Thanks for using Retro Subnet Calculator! Goodbye.\n");
    return 0;
}