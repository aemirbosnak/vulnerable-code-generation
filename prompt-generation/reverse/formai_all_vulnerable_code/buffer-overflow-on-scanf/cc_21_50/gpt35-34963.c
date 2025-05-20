//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
//ROMEO AND JULIET SUBNET CALCULATOR
//By: William Shakespeare

#include<stdio.h>
#include<string.h>

int main(){
    int subnet;
    char ipaddress[20], firstoctet[4], secondoctet[4], thirdoctet[4], fourthoctet[4];
    printf("Oh fair maiden, what be thy IP address? ");
    scanf("%s",ipaddress);
    printf("And what subnet doth thou desire? ");
    scanf("%d",&subnet);
    
    //Parsing Octets
    int i,j,k,temp;
    for(i=0,j=0,k=0; i<=strlen(ipaddress); i++){
        if(ipaddress[i] == '.' || ipaddress[i] == '\0'){
            if(k == 0){
                temp = atoi(strncpy(firstoctet,&ipaddress[j],i-j));
            }
            else if(k == 1){
                temp = atoi(strncpy(secondoctet,&ipaddress[j],i-j));
            }
            else if(k == 2){
                temp = atoi(strncpy(thirdoctet,&ipaddress[j],i-j));
            }
            else if(k == 3){
                temp = atoi(strncpy(fourthoctet,&ipaddress[j],i-j));
            }
            j=i+1;
            k++;
        }
    }
    
    //Binary Conversion
    int bin[4][8];
    for(i=0; i<4; i++){
        int num = 0, base = 128;
        temp = (i == 0) ? firstoctet[i] : (i == 1) ? secondoctet[i] : (i == 2) ? thirdoctet[i] : fourthoctet[i];
        for(j=0; j<8; j++){
            if((num + base) <= temp){
                num += base;
                bin[i][j] = 1;
            }
            else{
                bin[i][j] = 0;
            }
            base /= 2;
        }
    }
    
    //Subnet Mask Calculation
    int snetbin[4][8];
    int mask = subnet/8;
    int rem = subnet%8;
    for(i=0; i<4; i++){
        for(j=0; j<8; j++){
            if(i < mask || (i == mask && j < rem)){
                snetbin[i][j] = 1;
            }
            else{
                snetbin[i][j] = 0;
            }
        }
    }
    
    //Binary to Decimal Conversion
    int snetdec[4], netdec[4];
    for(i=0; i<4; i++){
        int num = 0, base = 128;
        for(j=0; j<8; j++){
            num += (snetbin[i][j] * base);
            base /= 2;
        }
        snetdec[i] = num;
    }
    
    for(i=0; i<4; i++){
        int num = 0, base = 128;
        for(j=0; j<8; j++){
            num += (bin[i][j] * base);
            base /= 2;
        }
        netdec[i] = num & snetdec[i];
    }
    
    //Printing Result
    printf("The IP Address is: %d.%d.%d.%d\n",firstoctet[0],secondoctet[0],thirdoctet[0],fourthoctet[0]);
    printf("The Subnet Mask is: %d.%d.%d.%d\n",snetdec[0],snetdec[1],snetdec[2],snetdec[3]);
    printf("The Network Address is: %d.%d.%d.%d\n",netdec[0],netdec[1],netdec[2],netdec[3]);
    printf("Farewell lovestruck friends!\n");
    return 0;
}