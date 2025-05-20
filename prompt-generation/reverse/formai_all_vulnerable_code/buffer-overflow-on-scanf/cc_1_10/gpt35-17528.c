//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binary_to_decimal(char *bin){
    int dec=0,base=1;
    int len=strlen(bin);
    for(int i=len-1;i>=0;i--){
        if(bin[i]=='1'){
            dec+=base;
        }
        base*=2;
    }
    return dec;
}

int main(){
    char ip_address[16];
    int subnet_mask,octet[4];
    printf("Enter IP Address: ");
    scanf("%s",ip_address);
    printf("Enter Subnet Mask (CIDR Notation): ");
    scanf("%d",&subnet_mask);
    int total_octets=(subnet_mask/8)+1;
    int total_bits=subnet_mask%8;
    char binary_octets[4][9];
    char subnet_mask_binary[33];
    int subnet_octets[4];
    memset(binary_octets,'0',sizeof binary_octets);
    memset(subnet_mask_binary,'0',sizeof subnet_mask_binary);
    int i=0,x,y;
    while(ip_address[i]!='\0' && ip_address[i]!='/' && i<16){
        i++;
    }
    ip_address[i]='\0';
    int len=i;
    for(int i=0,j=0,x=0;i<=len;i++){
        if(ip_address[i]=='.' || ip_address[i]=='\0'){
            binary_octets[j][8]='\0';
            octet[x]=binary_to_decimal(binary_octets[j]);
            x++;
            j=0;
        }
        else{
            binary_octets[x][j]=ip_address[i];
            j++;
        }
    }
    for(int i=0;i<total_octets;i++){
        subnet_mask_binary[i*8+total_bits]='1';
    }
    subnet_mask_binary[subnet_mask+1]='\0';
    for(int i=0,j=0;i<=subnet_mask;i++){
        subnet_octets[j]=subnet_mask_binary[i];
        j++;
        if(j==8){
            j=0;
            printf("%d",binary_to_decimal(subnet_octets));
            if(i!=subnet_mask){
                printf(".");
            }
        }
    }
    printf("\n");
    for(int i=0;i<4;i++){
        if(i<total_octets-1){
            printf("%d.",octet[i]);
        }
        else{
            for(int j=0;j<8-total_bits;j++){
                binary_octets[i][j]='0';
            }
            binary_octets[i][8]='\0';
            printf("%d.",binary_to_decimal(binary_octets[i]));
        }
    }
    return 0;
}