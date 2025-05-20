//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char ip[16], subnet[16];
    int mask[4], cidr;
    int nmask[4], wmask[4], bcast[4], naddr[4], faddr[4];

    //Get IP Address from user
    printf("Enter IP Address: ");
    scanf("%s", ip);

    //Get Subnet Mask from user
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet);

    //Split IP and Subnet Mask into four parts
    sscanf(ip, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);
    sscanf(subnet, "%d.%d.%d.%d", &nmask[0], &nmask[1], &nmask[2], &nmask[3]);

    //Convert Subnet Mask to CIDR notation
    cidr = 0;
    for(int i = 0; i < 4; i++){
        int bits = 0;
        for(int j = 7; j >= 0; j--){
            int b = (nmask[i] >> j) & 1;
            if(b == 1){
                bits++;
            } else {
                break;
            }
        }
        cidr += bits;
    }

    //Calculate Wildcard Mask
    for(int i = 0; i < 4; i++){
        wmask[i] = 255 - nmask[i];
    }

    //Calculate Network Address
    for(int i = 0; i < 4; i++){
        naddr[i] = mask[i] & nmask[i];
    }

    //Calculate Broadcast Address
    for(int i = 0; i < 4; i++){
        bcast[i] = naddr[i] | wmask[i];
    }

    //Calculate First Usable Address
    faddr[0] = naddr[0];
    faddr[1] = naddr[1];
    faddr[2] = naddr[2];
    faddr[3] = naddr[3] + 1;

    //Print Results
    printf("\nIP Address:       %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("Subnet Mask:      %d.%d.%d.%d\n", nmask[0], nmask[1], nmask[2], nmask[3]);
    printf("CIDR Notation:    /%d\n", cidr);
    printf("Wildcard Mask:    %d.%d.%d.%d\n", wmask[0], wmask[1], wmask[2], wmask[3]);
    printf("Network Address:  %d.%d.%d.%d\n", naddr[0], naddr[1], naddr[2], naddr[3]);
    printf("Broadcast Address:%d.%d.%d.%d\n", bcast[0], bcast[1], bcast[2], bcast[3]);
    printf("First Usable Addr:%d.%d.%d.%d\n", faddr[0], faddr[1], faddr[2], faddr[3]);

    return 0;
}