//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//This is a subnet calculator program that calculates subnet masks, network addresses and broadcast addresses for a given IP address and subnet mask

int main() {

    char ip_address[20], subnet_mask[20], temp[8], network_address[20], broadcast_address[20];
    int subnet_bits, i, j, k, l, octet, subnet_octets[4], subnet_mask_bin[32], ip_address_bin[32], network_address_bin[32], broadcast_address_bin[32];

    //Get user inputs for IP address and subnet mask
    printf("\n\n*** Subnet Calculator ***\n\n");
    printf("Enter IP address (in dotted decimal notation):");
    scanf("%s", ip_address);
    printf("Enter subnet mask (in dotted decimal notation):");
    scanf("%s", subnet_mask);

    //Convert IP address from dotted decimal notation to binary
    for(i=0,j=0,k=0,l=0;i<=strlen(ip_address);i++) {
        if(ip_address[i]=='.' || ip_address[i]=='\0') {
            temp[k]='\0';
            octet=atoi(temp);
            ip_address_bin[j]=octet/128;
            octet=octet%128;
            ip_address_bin[j+1]=octet/64;
            octet=octet%64;
            ip_address_bin[j+2]=octet/32;
            octet=octet%32;
            ip_address_bin[j+3]=octet/16;
            octet=octet%16;
            ip_address_bin[j+4]=octet/8;
            octet=octet%8;
            ip_address_bin[j+5]=octet/4;
            octet=octet%4;
            ip_address_bin[j+6]=octet/2;
            octet=octet%2;
            ip_address_bin[j+7]=octet;
            j=j+8;
            k=0;
        }
        else {
            temp[k]=ip_address[i];
            k++;
        }
    }

    //Convert subnet mask from dotted decimal notation to binary
    for(i=0,j=0,k=0,l=0;i<=strlen(subnet_mask);i++) {
        if(subnet_mask[i]=='.' || subnet_mask[i]=='\0') {
            temp[k]='\0';
            octet=atoi(temp);
            subnet_mask_bin[j]=octet/128;
            octet=octet%128;
            subnet_mask_bin[j+1]=octet/64;
            octet=octet%64;
            subnet_mask_bin[j+2]=octet/32;
            octet=octet%32;
            subnet_mask_bin[j+3]=octet/16;
            octet=octet%16;
            subnet_mask_bin[j+4]=octet/8;
            octet=octet%8;
            subnet_mask_bin[j+5]=octet/4;
            octet=octet%4;
            subnet_mask_bin[j+6]=octet/2;
            octet=octet%2;
            subnet_mask_bin[j+7]=octet;
            j=j+8;
            k=0;
        }
        else {
            temp[k]=subnet_mask[i];
            k++;
        }
    }

    //Calculate number of subnet bits
    for(i=0;i<=31;i++) {
        if(subnet_mask_bin[i]==1)
            subnet_bits++;
    }

    //Calculate subnet octets
    for(i=0,j=0;i<=31;i=i+8,j++) {
        subnet_octets[j]=subnet_mask_bin[i]*128+subnet_mask_bin[i+1]*64+subnet_mask_bin[i+2]*32+subnet_mask_bin[i+3]*16+subnet_mask_bin[i+4]*8+subnet_mask_bin[i+5]*4+subnet_mask_bin[i+6]*2+subnet_mask_bin[i+7];
    }

    //Calculate network address
    for(i=0;i<=31;i++) {
        network_address_bin[i]=ip_address_bin[i] & subnet_mask_bin[i];
    }

    //Calculate broadcast address
    for(i=0;i<=31;i++) {
        if(subnet_mask_bin[i]==1)
            broadcast_address_bin[i]=network_address_bin[i];
        else
            broadcast_address_bin[i]=1;
    }

    //Convert network address and broadcast address from binary to dotted decimal notation
    for(i=0,j=0,k=0,l=0;i<=31;i++) {
        if((i+1)%8==0) {
            temp[k]='\0';
            octet=atoi(temp);
            if(j<3) {
                sprintf(&network_address[l], "%d.", octet);
                sprintf(&broadcast_address[l], "%d.", octet);
            }
            else {
                sprintf(&network_address[l], "%d", octet);
                sprintf(&broadcast_address[l], "%d", octet);
            }
            k=0;
            j++;
            l=l+strlen(temp)+1;
        }
        else {
            sprintf(&temp[k], "%d", network_address_bin[i]);
            sprintf(&temp[k+1], "%c", '\0');
            k++;
        }
    }

    //Print output
    printf("\n\nIP Address: %s",ip_address);
    printf("\nSubnet mask: %s",subnet_mask);
    printf("\n\nNumber of subnet bits: %d",subnet_bits);
    printf("\n\nSubnet octet values: %d.%d.%d.%d",subnet_octets[0],subnet_octets[1],subnet_octets[2],subnet_octets[3]);
    printf("\n\nNetwork Address: %s",network_address);
    printf("\nBroadcast Address: %s\n\n",broadcast_address);

    return 0;
}