//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include<stdio.h>

//Converting Hexadecimal to Decimal
int hexToDec(char hex[]){
    int i,dec=0,p=1;
    for(i=strlen(hex)-1;i>=0;--i){
        if(hex[i]>='0'&&hex[i]<='9'){
            dec+=(hex[i]-48)*p;
            p*=16;
        }
        else if(hex[i]>='A'&&hex[i]<='F'){
            dec+=(hex[i]-55)*p;
            p*=16;
        }
        else if(hex[i]>='a'&&hex[i]<='f'){
            dec+=(hex[i]-87)*p;
            p*=16;
        }
        else{
            printf("\nInvalid hexadecimal input.");
            return 0;
        }
    }
    return dec;
}

//Converting Decimal to Hexadecimal
void decToHex(int n){
    char hex[100];
    int i=0,j;
    while(n!=0){
        int temp=0;
        temp=n%16;
        if(temp<10){
            hex[i]=temp+48;
            i++;
        }
        else{
            hex[i]=temp+55;
            i++;
        }
        n=n/16;
    }
    printf("\nDecimal in Hexadecimal is: ");
    for(j=i-1;j>=0;j--){
        printf("%c",hex[j]);
    }
}

int main(){
    char hex[100];
    int n,dec=0;
    printf("\nEnter a hexadecimal number: ");
    gets(hex);
    //Converting hexadecimal to decimal
    dec=hexToDec(hex);
    if(dec!=0){
        printf("\nHexadecimal in Decimal is: %d",dec);
        //Converting decimal to hexadecimal
        decToHex(dec);
    }
    printf("\n");
    return 0;
}