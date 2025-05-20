//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

    int subnet[4];
    char ip[20];
    char subnetMask[20];
    int cidr;

    printf("Enter the IP address: ");
    scanf("%s",ip);

    // Split the IP address into 4 parts
    char *token = strtok(ip, ".");
    int i = 0;
    while (token) {
        subnet[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    printf("Enter the subnet mask address: ");
    scanf("%s",subnetMask);

    // Convert subnet mask from string to int array
    token = strtok(subnetMask, ".");
    int subnetMaskArr[4];
    i = 0;
    while (token) {
        subnetMaskArr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    printf("Prefix length: ");
    scanf("%d", &cidr);

    // Calculate the subnet mask using prefix length
    int subnetMaskBits = 0xFFFFFFFF << (32 - cidr);
    int subnetMaskArr2[4];
    subnetMaskArr2[0] = (subnetMaskBits >> 24) & 0xFF;
    subnetMaskArr2[1] = (subnetMaskBits >> 16) & 0xFF;
    subnetMaskArr2[2] = (subnetMaskBits >> 8) & 0xFF;
    subnetMaskArr2[3] = subnetMaskBits & 0xFF;

    printf("\n\n==========Subnet Calculator=============\n\n");
    printf("IP Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Subnet Mask Decimal: %d.%d.%d.%d\n", subnetMaskArr[0], subnetMaskArr[1], subnetMaskArr[2], subnetMaskArr[3]);
    printf("Subnet Mask CIDR: /%d\n\n", cidr);

    // Subnet calculation
    int networkAddress[4];
    int broadcast[4];
    int subnetMaskDec[4];
    int hostMin[4];
    int hostMax[4];
    int totalHosts;

    for(i=0;i<4;i++){
        networkAddress[i] = subnet[i] & subnetMaskArr2[i];
        broadcast[i] = networkAddress[i] | (~subnetMaskArr2[i] & 0xFF);
        subnetMaskDec[i] = subnetMaskArr2[i];

        if(i==3){
            hostMin[i] = networkAddress[i] + 1;
            hostMax[i] = broadcast[i] - 1;
            totalHosts = pow(2,(8-cidr))-2;
        }
        else{
            hostMin[i] = 0;
            hostMax[i] = 255;
        }
    }

    printf("Network Address: %d.%d.%d.%d\n",networkAddress[0],networkAddress[1],networkAddress[2],networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n",broadcast[0],broadcast[1],broadcast[2],broadcast[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n",subnetMaskDec[0],subnetMaskDec[1],subnetMaskDec[2],subnetMaskDec[3]);
    printf("Hosts per subnet: %d\n\n",totalHosts);
    printf("Range: %d.%d.%d.%d to %d.%d.%d.%d\n\n",hostMin[0],hostMin[1],hostMin[2],hostMin[3],hostMax[0],hostMax[1],hostMax[2],hostMax[3]);

    return 0;
}