//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char ip[20];
    int subnet_mask, subnet_add, subnet_bits, i, j, k;
    const char bitmask[32][4] = {"128","64","32","16","8","4","2","1",  //Array of subnet mask bit values
                               "0","0","0","0","0","0","0","0",
                               "0","0","0","0","0","0","0","0",
                               "0","0","0","0","0","0","0","0"};

    printf("Enter IP address (e.g. 192.168.0.1): ");
    scanf("%s", ip);

    //Extracting the subnet mask portion
    char *ptr = strstr(ip,"/");
    if(ptr!=NULL){
        ptr++;
        subnet_bits = atoi(ptr);
    }else{
        printf("\nSubnet mask not specified.");
        printf("\nAssuming default subnet mask (24 bits).");
        subnet_bits = 24;
    }

    subnet_mask = (int)pow(2, subnet_bits)-1;

    //Extracting the network address portion
    char *tok = strtok(ip, ".");
    int network_add[4];
    for (i = 0; i < 4; i++){
        network_add[i] = atoi(tok);
        tok = strtok(NULL, ".");
        if(tok==NULL && i<3){
            printf("\nInvalid IP address format.");
            return 0;
        }
    }

    subnet_add = network_add[3] & subnet_mask;

    //Printing network address
    printf("\nNetwork Address: %d.%d.%d.%d", network_add[0],network_add[1],network_add[2],subnet_add);

    //Printing broadcast address
    printf("\nBroadcast Address: %d.%d.%d.%d", network_add[0],network_add[1],network_add[2],subnet_add+(int)pow(2, 32-subnet_bits)-1);

    //Printing all possible host addresses
    printf("\n\nHost Addresses: ");
    for(i=0; i<256; i+=(int)pow(2, 8-subnet_bits)){
        for(j=0; j<256; j+=(int)pow(2, 8-subnet_bits)){
            for(k=0; k<256; k+=(int)pow(2, 8-subnet_bits)){
                if(i==subnet_add && j==subnet_add && k==subnet_add){
                    k+=(int)pow(2, 8-subnet_bits);
                }
                printf("\n%d.%d.%d.%d", i,j,k,subnet_add);
                k+=(int)pow(2, 8-subnet_bits)-1;
            }
            j+=(int)pow(2, 8-subnet_bits)-1;
        }
        i+=(int)pow(2, 8-subnet_bits)-1;
    }

    //Printing subnet mask in dotted decimal format
    printf("\n\nSubnet Mask: ");
    for(i=0; i<32; i+=8){
        unsigned int decval=0;
        for(j=i, k=0; j<i+8; j++, k++){
            if(bitmask[j][0] == '1'){
                decval += (unsigned int)pow(2, (double)(7-k));
            }
        }
        printf("%d", decval);
        if(i<24){
            printf(".");
        }
    }

    printf("\n\nNo. of Subnets = %d", (int)pow(2, 32-subnet_bits));
    printf("\nNo. of Hosts per Subnet = %d", (int)pow(2, subnet_bits)-2);

    return 0;
}