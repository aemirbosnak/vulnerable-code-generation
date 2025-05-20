//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("\nWelcome to the shape-shifting Subnet Calculator\n");

    char choice;
    int mask, bitsReq, numHosts, networks, oldMask, newMask, hostsPerNet, netID1, netID2, netID3, netID4, cidr, bitsRemaining, remainingIPs, totalSubnets, totalIPs, bitsPerOctet[4], i, j, k, l;

    // Get input from user
    printf("\nEnter your current subnet mask (in decimal form): ");
    scanf("%d", &oldMask);

    printf("\nEnter the number of bits required for each subnet: ");
    scanf("%d", &bitsReq);

    printf("\nEnter the number of hosts required for each subnet: ");
    scanf("%d", &numHosts);

    // Determine number of networks
    networks = 1 << bitsReq;

    // Determine new subnet mask
    bitsRemaining = 32 - oldMask;
    newMask = 32 - bitsReq;

    printf("\nYour new subnet mask is /%d", newMask);

    // Determine subnetting scheme
    hostsPerNet = numHosts + 2;
    netID1 = 0;
    netID2 = 0;
    netID3 = 0;
    netID4 = 0;
    totalSubnets = 0;
    totalIPs = 0;

    for(i=0; i<networks; i++){
        // Print subnet info
        printf("\n\nSubnet %d:", i+1);

        printf("\nNetwork ID: %d.%d.%d.%d", netID1, netID2, netID3, netID4);
        printf("\nSubnet Mask: %d.%d.%d.%d", 255, 255, 255, (1 << (8 - bitsReq)) - 1);

        // Determine usable IP range for this subnet
        remainingIPs = (1 << (bitsReq - 1)) - 1 - numHosts;
        printf("\nUsable IP Range: %d.%d.%d.%d - %d.%d.%d.%d", netID1, netID2, netID3, netID4+1, netID1, netID2, netID3+1, netID4+numHosts);

        // Determine broadcast address for this subnet
        printf("\nBroadcast Address: %d.%d.%d.%d", netID1, netID2, netID3+1, netID4+remainingIPs+numHosts+1);

        // Calculate total IPs for this subnet
        totalIPs = totalIPs + (1 << bitsReq);

        // Update network information for next subnet
        netID4 = netID4 + hostsPerNet;

        if(netID4 > 255){
            netID4 = 0;
            netID3 = netID3 + 1;

            if(netID3 > 255){
                netID3 = 0;
                netID2 = netID2 + 1;

                if(netID2 > 255){
                    netID2 = 0;
                    netID1 = netID1 + 1;
                }
            }
        }
    }

    // Print summary statistics
    printf("\n\nTotal Subnets: %d", networks);
    printf("\nTotal IPs: %d", totalIPs);

    // Determine bits per octet for new subnet mask
    cidr = 32 - newMask;
    bitsPerOctet[0] = cidr > 8 ? 8 : cidr;
    cidr = cidr - bitsPerOctet[0];
    for(j=1; j<4; j++){
        bitsPerOctet[j] = cidr > 8 ? 8 : cidr;
        cidr = cidr - bitsPerOctet[j];
    }

    // Print new subnet mask in binary form
    printf("\nNew Subnet Mask: ");
    for(k=0; k<4; k++){
        for(l=0; l<8; l++){
            if(bitsPerOctet[k] > 0){
                printf("1");
                bitsPerOctet[k]--;
            }
            else{
                printf("0");
            }
        }

        if(k < 3){
            printf(".");
        }
    }

    return 0;
}