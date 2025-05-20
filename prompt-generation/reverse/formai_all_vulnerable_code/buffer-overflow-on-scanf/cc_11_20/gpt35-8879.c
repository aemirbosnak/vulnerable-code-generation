//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main() {
    int i,j,n,ip1,ip2,ip3,ip4,subnet;
    int mask[4],sub[4],f_bin[8],s_bin[8],t_bin[8],ff_bin[8],comp[4],nw_adr[4],broad_adr[4],first_host[4],last_host[4],host;
    char ch,ch1,ch2,ch3,ch4;

    //get input IP address from user
    printf("Enter IP Address:\n");
    scanf("%d%c%d%c%d%c%d",&ip1,&ch1,&ip2,&ch2,&ip3,&ch3,&ip4);

    //get input subnet mask from user
    printf("\nEnter Subnet Mask in bits:\n");
    scanf("%d.%d.%d.%d",&mask[0],&mask[1],&mask[2],&mask[3]);

    //binary representation of IP address and subnet mask
    f_bin[0]=ip1,f_bin[1]=ip2,f_bin[2]=ip3,f_bin[3]=ip4;
    for(i=0;i<=3;i++) {
        for(j=7;j>=0;j--) {
            printf("%d",f_bin[i]>>j&1);
        }
        printf(" ");
    }

    //network and broadcast address calculation
    for(i=0;i<=3;i++) {
        sub[i]=mask[i];
        comp[i]=255-mask[i];
        nw_adr[i]=f_bin[i]&sub[i];
        broad_adr[i]=nw_adr[i]+comp[i];
    }

    //binary representation of first octet of network address
    for(i=7;i>=0;i--) {
        printf("%d",nw_adr[0]>>i&1);
    }
    printf(" ");

    //binary representation of last octet of network address
    for(i=0;i<=3;i++) {
        printf("%d",nw_adr[i]);
        if(i<3) printf(".");
    }
    printf("\n");

    //binary representation of first octet of broadcast address
    for(i=7;i>=0;i--) {
        printf("%d",broad_adr[0]>>i&1);
    }
    printf(" ");

    //binary representation of last octet of broadcast address
    for(i=0;i<=3;i++) {
        printf("%d",broad_adr[i]);
        if(i<3) printf(".");
    }
    printf("\n");

    //number of hosts on the network
    host=256-mask[3];

    //binary representation of first host IP address
    first_host[3]=nw_adr[3]+1;
    for(i=0;i<=3;i++) {
        printf("%d",nw_adr[i]);
        if(i<3) printf(".");
    }
    printf("\n");
    printf("Binary Representation of First Host IP Address:\n");
    for(i=7;i>=0;i--) {
        s_bin[i]=first_host[3]>>i&1;
        printf("%d",s_bin[i]);
    }
    printf(" ");

    //binary representation of last host IP address
    last_host[3]=broad_adr[3]-1;
    printf("\n");
    printf("\nBinary Representation of Last Host IP Address:\n");
    for(i=7;i>=0;i--) {
        t_bin[i]=last_host[3]>>i&1;
        printf("%d",t_bin[i]);
    }
    printf(" ");
    return 0;
}