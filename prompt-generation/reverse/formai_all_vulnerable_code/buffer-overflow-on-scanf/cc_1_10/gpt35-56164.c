//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include<stdio.h> //header file for standard input and output operations
#include<math.h>  //header file for mathematical operations

int main() {
    //variables for the subnet mask
    int mask[4];
    int maskBits;
    //variables for the IP address
    int ip[4];
    //variables for the network address
    int networkAddress[4];
    //variables for the broadcast address
    int broadcastAddress[4];
    //variables for the number of hosts
    int numberOfHosts;

    //input of the IP address
    printf("Enter the IP address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    //input of the subnet mask
    printf("Enter the subnet mask in bits: ");
    scanf("%d", &maskBits);

    //calculate the subnet mask
    for(int i=0; i<4; i++){
        if(maskBits>=8){
            mask[i] = 255;
            maskBits -= 8;
        } else if(maskBits>0) {
            mask[i] = 256 - pow(2, (8 - maskBits));
            maskBits = 0;
        } else {
            mask[i] = 0;
        }
    }

    //calculate the network address
    for(int i=0; i<4; i++){
        networkAddress[i] = ip[i] & mask[i];
    }

    //calculate the broadcast address
    for(int i=0; i<4; i++){
        broadcastAddress[i] = networkAddress[i] | (255 ^ mask[i]);
    }

    //calculate the number of hosts
    numberOfHosts = pow(2, (32-maskBits)) - 2;

    //print the information about the network
    printf("\nIP Address: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    printf("\nSubnet Mask: %d.%d.%d.%d", mask[0], mask[1], mask[2], mask[3]);
    printf("\nNetwork Address: %d.%d.%d.%d", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("\nBroadcast Address: %d.%d.%d.%d", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
    printf("\nNumber of Hosts: %d\n", numberOfHosts);
    
    return 0;
}