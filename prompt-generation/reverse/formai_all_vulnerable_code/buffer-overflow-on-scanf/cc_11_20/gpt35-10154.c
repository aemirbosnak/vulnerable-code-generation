//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
    Puzzle: 
    I am a subnet calculator, but I have lost my memory. All I remember is that I belong to an unknown IP address and I can only operate with a subnet mask of exactly 24 bits. 
    Can you help me to discover which subnet I belong to?
*/

int main(){
    printf("Welcome to the Subnet Calculator!\n");
    printf("Please enter the IP address (format: xxx.xxx.xxx.xxx): ");
    char ip_address[16];
    scanf("%s",ip_address);
    
    //let's validate the IP address
    int n[4], num=0, count=0, invalid=0;
    char temp[4];
    for(int i=0;i<strlen(ip_address);i++){
        if(ip_address[i]!='.') temp[count++]=ip_address[i];
        else{
            temp[count]='\0';
            n[num++] = atoi(temp);
            count=0;
        }
    }
    temp[count]='\0';
    n[num++] = atoi(temp);
    for(int i=0;i<4;i++) 
        if(n[i]<0 || n[i]>255) invalid=1;
        
    if(invalid || num!=4){
        printf("Invalid IP Address!\n");
        return 0;
    }
    
    //IP address validation passed, let's check the subnet
    int subnet[4];
    printf("Please enter the subnet mask (format: xxx.xxx.xxx.xxx): ");
    char subnet_mask[16];
    scanf("%s",subnet_mask);
    
    //let's validate the subnet mask
    num=0;
    count=0;
    invalid=0;
    for(int i=0;i<strlen(subnet_mask);i++){
        if(subnet_mask[i]!='.') temp[count++]=subnet_mask[i];
        else{
            temp[count]='\0';
            subnet[num++] = atoi(temp);
            count=0;
        }
    }
    temp[count]='\0';
    subnet[num++] = atoi(temp);
    for(int i=0;i<4;i++) 
        if(subnet[i]!=255 && subnet[i]!=0) invalid=1;
    if(invalid || num!=4){
        printf("Invalid Subnet Mask!\n");
        return 0;
    }
    if(subnet[0]!=255 || subnet[1]!=255 || subnet[2]!=255 || subnet[3]!=0){
        printf("Invalid Subnet Mask! Mask must be exactly 24 bits.\n");
        return 0;
    }
    
    //subnet is valid, let's find the subnet address
    int subnet_address[4];
    for(int i=0;i<4;i++)
        subnet_address[i]=subnet[i] & n[i];
        
    printf("\nSubnet Address: %d.%d.%d.%d\n",subnet_address[0],subnet_address[1],subnet_address[2],subnet_address[3]);
    printf("Number of Hosts in Subnet: %d\n\n",(int)pow(2,8)-2);
    
    return 0;
}