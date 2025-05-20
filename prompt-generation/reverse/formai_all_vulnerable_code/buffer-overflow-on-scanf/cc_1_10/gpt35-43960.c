//FormAI DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binaryToDecimal(char binaryNumber[]) {
    int decimalNumber = 0;
    int length = strlen(binaryNumber);
    
    for (int i = 0; i < length; i++) {
        if (binaryNumber[i] == '1') {
            decimalNumber += pow(2, length - 1 - i);
        }
    }
    
    printf("Binary Number: %s\nDecimal Number: %d\n", binaryNumber, decimalNumber);
}

void decimalToBinary(int decimalNumber) {
    int binaryNumber[1000];
    int index = 0;
    
    while (decimalNumber > 0) {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber /= 2;
        index++;
    }
    
    printf("Decimal Number: %d\nBinary Number: ", decimalNumber);
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryNumber[i]);
    }
    
    printf("\n");
}

int main() {
    char binaryNumber[1000];
    int decimalNumber;
    int option;
    int exit = 0;
    
    while (!exit) {
        printf("1. Convert Binary to Decimal\n2. Convert Decimal to Binary\n3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%s", binaryNumber);
                binaryToDecimal(binaryNumber);
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                decimalToBinary(decimalNumber);
                break;
            case 3:
                printf("Exiting...\n");
                exit = 1;
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}