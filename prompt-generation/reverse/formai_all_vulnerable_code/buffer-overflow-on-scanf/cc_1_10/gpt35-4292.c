//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* decimalToBinary(int n){
    char* binary = malloc(sizeof(char)*33);
    int i = 0;
    while(n > 0){
        binary[i] = n%2 + '0';
        n = n/2;
        i++;
    }
    binary[i] = '\0';
    return binary;
}

int binaryToDecimal(char* binary){
    int decimal = 0;
    int len = strlen(binary);
    int base = 1;
    for(int i=len-1; i>=0; i--){
        if(binary[i] == '1'){
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int main(){
    int choice;
    printf("\n***Welcome to Binary Converter***");
    do{
        printf("\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int decimalNumber;
                printf("\nEnter decimal number to convert to binary: ");
                scanf("%d", &decimalNumber);
                char* binaryNumber = decimalToBinary(decimalNumber);
                printf("Binary equivalent of %d is %s\n", decimalNumber, binaryNumber);
                free(binaryNumber);
                break;
            }
            case 2:{
                char binaryNumber[33];
                printf("\nEnter binary number (up to 32 bits) to convert to decimal: ");
                scanf("%s", binaryNumber);
                int decimalNumber = binaryToDecimal(binaryNumber);
                printf("Decimal equivalent of %s is %d\n", binaryNumber, decimalNumber);
                break;
            }
            case 3:
                printf("\nExiting Binary Converter...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }while(choice != 3);
    
    return 0;
}