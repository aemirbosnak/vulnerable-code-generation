//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include<stdio.h>

int main(){
    int address, subnetMask, n, numSubnets, numHosts,i,j,subnetIndex,hostIndex;
    int *subnetResult, *hostResult;
    printf("Enter the IPv4 Address: ");
    scanf("%d",&address);
    printf("Enter the Subnet Mask: ");
    scanf("%d",&subnetMask);

    //Calculate the number of bits for subnets
    n = 0;
    for(i=31;i>=0;i--){
        if((subnetMask & (1<<i))!=0){
            n++;
        }
        else{
            break;
        }
    }

    //Calculate the number of subnets
    numSubnets = 1<<n;

    //Calculate the number of hosts per subnet
    numHosts = 1<<(32-n);

    printf("\nNumber of bits for Subnets: %d",n);
    printf("\nNumber of Subnets: %d",numSubnets);
    printf("\nNumber of Hosts Per Subnet: %d",numHosts);

    //Allocate memory for subnet and host results
    subnetResult = (int*)malloc(numSubnets*sizeof(int));
    hostResult = (int*)malloc(numHosts*sizeof(int));

    //Initialize subnet and host results
    for(i=0;i<numSubnets;i++){
        subnetResult[i] = 0;
    }
    for(i=0;i<numHosts;i++){
        hostResult[i] = 0;
    }

    //Calculate subnet and host addresses
    subnetIndex = 0;
    hostIndex = 0;
    for(i=31;i>=0;i--){
        if((subnetMask & (1<<i))!=0){
            for(j=0;j<numSubnets;j++){
                subnetResult[j] |= (j&1)<<i;
            }
            subnetIndex++;
        }
        else{
            for(j=0;j<numHosts;j++){
                hostResult[j] |= (j&1)<<i;
            }
            hostIndex++;
        }
    }

    //Print the results
    printf("\nSubnet Addresses:\n");
    for(i=0;i<numSubnets;i++){
        printf("%d.%d.%d.%d\n",(address>>24)&0xFF,(subnetResult[i]>>16)&0xFF,(subnetResult[i]>>8)&0xFF,subnetResult[i]&0xFF);
    }
    printf("\nHost Addresses:\n");
    for(i=0;i<numHosts;i++){
        printf("%d.%d.%d.%d\n",(address>>24)&0xFF,(hostResult[i]>>16)&0xFF,(hostResult[i]>>8)&0xFF,hostResult[i]&0xFF);
    }

    free(subnetResult);
    free(hostResult);
    return 0;
}