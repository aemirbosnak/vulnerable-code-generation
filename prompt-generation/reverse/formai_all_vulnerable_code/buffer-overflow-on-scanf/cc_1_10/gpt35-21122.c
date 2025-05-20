//FormAI DATASET v1.0 Category: Binary Converter ; Style: modular
#include<stdio.h>
#include<stdlib.h>

int decimalToBinary(int decimalNumber);
int binaryToDecimal(long long binaryNumber);

int main(){
    int option;
    int decimalNumber;
    long long binaryNumber;
    
    do{
        printf("Choose the conversion type:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d",&decimalNumber);
                printf("%d in decimal = %d in binary\n", decimalNumber, decimalToBinary(decimalNumber));
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNumber);
                printf("%lld in binary = %d in decimal\n", binaryNumber, binaryToDecimal(binaryNumber));
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option! Please select a valid option.\n");
        }
        
    }while(option!=3);

    return 0;
}

int decimalToBinary(int decimalNumber){
    int binaryNumber=0, i=1, remainder;

    while(decimalNumber!=0){
        remainder = decimalNumber%2;
        decimalNumber /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }

    return binaryNumber;
}

int binaryToDecimal(long long binaryNumber){
    int decimalNumber=0, i=0, remainder;
    
    while(binaryNumber!=0){
        remainder = binaryNumber%10;
        binaryNumber /= 10;
        decimalNumber += remainder*pow(2,i);
        i++;
    }

    return decimalNumber;

}