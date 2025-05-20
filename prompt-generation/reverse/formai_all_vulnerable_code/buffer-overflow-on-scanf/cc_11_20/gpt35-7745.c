//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ip[16],temp[4],subnet[16];
    int cidr,i,j,k,num,mask[4];
    printf("Enter an IP address: ");
    scanf("%15s",ip);
    printf("Enter CIDR notation: /");
    scanf("%d",&cidr);

    num=cidr/8;    //Number of complete octets
    j=cidr%8;      //Bits remaining in incomplete octet
    for(i=0;i<num;i++){   //Finding the octets of the subnet mask
        mask[i]=255;
    }
    if(num<4){
        for(i=num;i<4;i++){
            mask[i]=0;
        }
    }
    if(j!=0){
        for(k=7;k>7-j;k--){
            mask[num]=mask[num] & ~(1<<k);
        }
    }
    
    //Converting the IP address and subnet mask into binary
    int ipBinary[32],subnetBinary[32];
    for(i=0;i<4;i++){
        num=atoi(strncpy(temp,ip+i*4,3)); //Extracting the octets of the IP address
        for(k=7;k>=0;k--){
            ipBinary[i*8+7-k]=(num>>k)&1;
        }
        num=mask[i];  //Extracting the octets of the subnet mask
        for(k=7;k>=0;k--){
            subnetBinary[i*8+7-k]=(num>>k)&1;
        }
    }

    //Calculating the network and broadcast addresses
    int network[32],broadcast[32];
    for(i=0;i<32;i++){
        network[i]=ipBinary[i] & subnetBinary[i];
        broadcast[i]=network[i];
    }
    for(i=31;i>=31-j;i--){
        broadcast[i]=broadcast[i] | 1;
    }
    
    //Converting the network and broadcast addresses back into decimal
    char networkDecimal[16],broadcastDecimal[16];
    for(i=0;i<4;i++){
        num=0;
        for(k=7;k>=0;k--){
            num=num*2+network[i*8+7-k];
        }
        sprintf(temp,"%d",num);
        if(i!=3){
            strcat(temp,".");
        }
        strcat(networkDecimal,temp);
        num=0;
        for(k=7;k>=0;k--){
            num=num*2+broadcast[i*8+7-k];
        }
        sprintf(temp,"%d",num);
        if(i!=3){
            strcat(temp,".");
        }
        strcat(broadcastDecimal,temp);
    }

    printf("Network address: %s/%d\n",networkDecimal,cidr);
    printf("Broadcast address: %s/%d\n",broadcastDecimal,cidr);

    return 0;
}