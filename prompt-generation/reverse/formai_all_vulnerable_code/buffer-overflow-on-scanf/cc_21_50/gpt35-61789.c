//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include<stdio.h>
#include<math.h>

int main(){
    //program to calculate subnet of a class C ip address
    int octet[4], subnet_bits, subnet_oct, subnet_mask[4], i, j, k;
    int host_bits, host_oct, host_no, total_hosts;
    char choice;

    //get input ip address
    printf("\nEnter Class C IP Address:\n");
    scanf("%d.%d.%d.%d",&octet[0],&octet[1],&octet[2],&octet[3]);

    //check if entered ip address is valid
    for(i=0; i<=3; i++){
        if(octet[i]<0 || octet[i]>255){
            printf("\nInvalid IP Address.\n");
            return 0;
        }
    }

    //get input subnet bits
    printf("Enter Number of Subnet Bits:\n");
    scanf("%d",&subnet_bits);

    //calculate number of subnets
    subnet_oct=subnet_bits/8;
    j=subnet_bits%8;
    if(j>0){
        subnet_oct++;
    }
    total_hosts=pow(2,8-j)-2;
    for(i=subnet_oct; i<=3; i++){
        subnet_mask[i]=0;
    }
    for(i=7; i>=j; i--){
        subnet_mask[subnet_oct]+=(int)pow(2,i);
    }
    for(i=subnet_oct+1; i<=3; i++){
        subnet_mask[i]=255;
    }
    
    //display subnet mask
    printf("\nSubnet Mask:");
    for(i=0; i<=3; i++){
        printf("%d",subnet_mask[i]);
        if(i<=2){
            printf(".");
        }
    }

    //get input host bits
    printf("\nEnter Number of Host Bits:\n");
    scanf("%d",&host_bits);

    //calculate number of hosts
    host_oct=host_bits/8;
    k=host_bits%8;
    if(k>0){
        host_oct++;
    }
    host_no=pow(2,8-k)-2;
    for(i=host_oct; i<=3; i++){
        host_no+=pow(2,8);
    }

    //display number of subnets and hosts
    printf("\n\nNumber of Subnets: ");
    for(i=0; i<=subnet_oct; i++){
        printf("255.");
    }
    printf("%d\n",total_hosts);
    printf("Number of Hosts: ");
    for(i=0; i<=host_oct; i++){
        printf("255.");
    }
    printf("%d\n",host_no);

    //ask to repeat
    printf("\nDo you want to calculate again? Press Y for yes and N for no.\n");
    scanf(" %c",&choice);

    //repeat until user quits
    while(choice=='Y' || choice=='y'){
        //get input ip address
        printf("\nEnter Class C IP Address:\n");
        scanf("%d.%d.%d.%d",&octet[0],&octet[1],&octet[2],&octet[3]);

        //check if entered ip address is valid
        for(i=0; i<=3; i++){
            if(octet[i]<0 || octet[i]>255){
                printf("\nInvalid IP Address.\n");
                return 0;
            }
        }

        //get input subnet bits
        printf("Enter Number of Subnet Bits:\n");
        scanf("%d",&subnet_bits);

        //calculate number of subnets
        subnet_oct=subnet_bits/8;
        j=subnet_bits%8;
        if(j>0){
            subnet_oct++;
        }
        total_hosts=pow(2,8-j)-2;
        for(i=subnet_oct; i<=3; i++){
            subnet_mask[i]=0;
        }
        for(i=7; i>=j; i--){
            subnet_mask[subnet_oct]+=(int)pow(2,i);
        }
        for(i=subnet_oct+1; i<=3; i++){
            subnet_mask[i]=255;
        }

        //display subnet mask
        printf("\nSubnet Mask:");
        for(i=0; i<=3; i++){
            printf("%d",subnet_mask[i]);
            if(i<=2){
                printf(".");
            }
        }

        //get input host bits
        printf("\nEnter Number of Host Bits:\n");
        scanf("%d",&host_bits);

        //calculate number of hosts
        host_oct=host_bits/8;
        k=host_bits%8;
        if(k>0){
            host_oct++;
        }
        host_no=pow(2,8-k)-2;
        for(i=host_oct; i<=3; i++){
            host_no+=pow(2,8);
        }

        //display number of subnets and hosts
        printf("\n\nNumber of Subnets: ");
        for(i=0; i<=subnet_oct; i++){
            printf("255.");
        }
        printf("%d\n",total_hosts);
        printf("Number of Hosts: ");
        for(i=0; i<=host_oct; i++){
            printf("255.");
        }
        printf("%d\n",host_no);

        //ask to repeat
        printf("\nDo you want to calculate again? Press Y for yes and N for no.\n");
        scanf(" %c",&choice);
    }
    return 0;
}