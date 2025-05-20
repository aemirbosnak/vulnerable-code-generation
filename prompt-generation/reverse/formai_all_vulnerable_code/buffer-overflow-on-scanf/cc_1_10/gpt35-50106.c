//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// binary to decimal conversion function
int binaryToDecimal(int binary){
    int decimal = 0, base = 1;
    while(binary){
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

// decimal to binary conversion function
void decimalToBinary(int decimal){
    int binary[32], index = 0;
    while(decimal > 0){
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    for(int i=index-1; i>=0; i--){
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main(){
    char choice;
    do{
        int option;
        printf("Choose an option:\n1. Binary to decimal conversion.\n2. Decimal to binary conversion.\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter a binary number to convert to decimal: ");
                int binary;
                scanf("%d", &binary);
                printf("Decimal equivalent of %d is %d.\n", binary, binaryToDecimal(binary));
                break;
            case 2:
                printf("Enter a decimal number to convert to binary: ");
                int decimal;
                scanf("%d", &decimal);
                printf("Binary equivalent of %d is ", decimal);
                decimalToBinary(decimal);
                break;
            default:
                printf("Invalid option selected!\n");
                break;
        }
        printf("Do you want to continue? (y/n): ");
        scanf("%s", &choice);
    }while(choice == 'y' || choice == 'Y');
    return 0;
}