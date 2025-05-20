//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function prototypes
int convert(char c);
int hexadecimalToDecimal(char hex[]);
void decimalToBinary(int n);
void decimalToOctal(int n);

int main(){
    char hex[50];
    int choice, decimal;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    printf("Choose the conversion:\n");
    printf("1. Hexadecimal to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Octal\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            decimal = hexadecimalToDecimal(hex);
            printf("%s in decimal is %d\n", hex, decimal);
            break;
        case 2:
            decimal = hexadecimalToDecimal(hex);
            printf("%s in binary is ", hex);
            decimalToBinary(decimal);
            break;
        case 3:
            decimal = hexadecimalToDecimal(hex);
            printf("%s in octal is ", hex);
            decimalToOctal(decimal);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}

//Convert hexadecimal numbers to decimal
int convert(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    } else if(c >= 'a' && c <= 'f'){
        return c - 'a' + 10;
    } else if(c >= 'A' && c <= 'F'){
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

int hexadecimalToDecimal(char hex[]){
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    for(int i = len - 1; i >= 0; i--){
        if(convert(hex[i]) == -1){
            printf("Invalid input\n");
            exit(0);
        }
        decimal += convert(hex[i]) * base;
        base *= 16;  
    }
    return decimal;
}

//Convert decimal to binary
void decimalToBinary(int n){
    if(n == 0){
        printf("0\n");
    } else {
        int binary[50];
        int i = 0, j;
        while(n > 0){
            binary[i] = n % 2;
            n = n / 2;
            i++;
        }
        for(j = i-1; j >= 0; j--){
            printf("%d", binary[j]);
        }
        printf("\n");
    }
}

//Convert decimal to octal
void decimalToOctal(int n){
    int octal[50];
    int i = 0, j;
    while(n > 0){
        octal[i] = n % 8;
        n = n / 8;
        i++;
    }
    for(j = i-1; j >= 0; j--){
        printf("%d", octal[j]);
    }
    printf("\n");
}