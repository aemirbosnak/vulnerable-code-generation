//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hexToDec(char hex[]) { // Function to convert hexadecimal to decimal
    
    int len=strlen(hex);
    int base=1;
    int dec=0;
    int i;
    for(i=len-1;i>=0;i--){
        if(hex[i]>='0'&&hex[i]<='9')
            dec+=(hex[i]-'0')*base;
        else if(hex[i]>='A'&&hex[i]<='F')
            dec+=(hex[i]-'A'+10)*base;
        base*=16;
    }
    return dec;
}

void decToHex(int dec) { // Function to convert decimal to hexadecimal
    char hex[100];
    int i=0;
    while(dec!=0) {
        int rem=dec%16;
        if(rem<10)
            hex[i++]=rem+'0';
        else
            hex[i++]=rem+55;
        dec/=16;
    }
    printf("Hexadecimal equivalent: ");
    for(int j=i-1;j>=0;j--)
        printf("%c",hex[j]);
}

int main(){
    int choice;
    int dec;
    char hex[100];
    while(1){
        printf("\nEnter your choice:\n1. Hexadecimal to Decimal\n2. Decimal to Hexadecimal\n3. Exit\n");
        scanf("%d",&choice);
        if(choice==1){ // Hexadecimal to Decimal
            printf("\nEnter hexadecimal number: ");
            scanf("%s", hex);
            int dec=hexToDec(hex);
            printf("\nDecimal equivalent: %d", dec);
        }
        else if(choice==2){ // Decimal to Hexadecimal
            printf("\nEnter decimal number: ");
            scanf("%d", &dec);
            decToHex(dec);
        }
        else { // Exit
            printf("\nExiting...");
            exit(0);
        }
    }
    return 0;
}