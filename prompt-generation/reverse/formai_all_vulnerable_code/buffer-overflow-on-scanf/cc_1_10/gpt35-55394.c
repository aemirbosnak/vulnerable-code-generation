//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

//function prototypes
void decToHexa(int n);
void hexToDec(char hex[]);

int main(){
    int choice;
    printf("****************************************************\n");
    printf("******** Welcome to the Hexadecimal Converter ********\n");
    printf("****************************************************\n\n");
    printf("Please choose one of the following options:\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("Choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:{
            int decimal;
            printf("\nEnter decimal number: ");
            scanf("%d",&decimal);
            printf("\nHexadecimal conversion of %d is : ",decimal);
            decToHexa(decimal);
            break;
        }
        case 2:{
            char hex[20];
            printf("\nEnter hexadecimal number: ");
            scanf("%s",hex);
            hexToDec(hex);
            break;
        }
        default:{
            printf("\nInvalid choice. Try Again!");
            break;
        }
    }
    return 0;
}

void decToHexa(int n){
    char hexaDeciNum[100];
    int i = 0;
    while(n!=0){
        int temp  = 0;
        temp = n % 16;
        if (temp < 10){
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else{
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n/16; 
    }
    for(int j=i-1;j>=0;j--){
        printf("%c",hexaDeciNum[j]);
    }
}

void hexToDec(char hex[]){
    int decimal = 0;
    int base = 1;
    int length = strlen(hex);
    for(int i=length-1;i>=0;i--){
        if(hex[i]>='0' && hex[i]<='9'){
            decimal += (hex[i] - 48)*base;
            base = base * 16;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            decimal += (hex[i] - 55)*base;
            base = base * 16;
        }
    }
    printf("\nDecimal conversion of %s is: %d",hex,decimal);
}