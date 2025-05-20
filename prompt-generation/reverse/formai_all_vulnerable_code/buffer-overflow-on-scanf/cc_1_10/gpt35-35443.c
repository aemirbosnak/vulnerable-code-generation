//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void binaryToDecimal() {
    char binaryInput[50];
    printf("Enter a binary number: ");
    scanf("%s", binaryInput);
    int decimalOutput = 0;
    int binaryLength = strlen(binaryInput);
    for(int i = 0; i < binaryLength; i++) {
        if(binaryInput[i] == '1') {
            decimalOutput += pow(2, binaryLength-i-1);
        } else if(binaryInput[i] == '0') {
            // Do nothing
        } else {
            printf("%c is an invalid binary digit!\n", binaryInput[i]);
            return;
        }
    }
    printf("Decimal output: %d\n", decimalOutput);
}

void decimalToBinary() {
    int decimalInput;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalInput);

    if(decimalInput < 0) {
        printf("Invalid input!\n");
        return;
    }

    int binaryOutput[50];
    for(int i = 0; decimalInput > 0; i++) {
        binaryOutput[i] = decimalInput % 2;
        decimalInput /= 2;
    }

    printf("Binary output: ");
    for(int i = sizeof(binaryOutput)/sizeof(binaryOutput[0]) - 1; i >= 0; i--) {
        printf("%d", binaryOutput[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the curious Binary Converter program!\n");
    printf("Choose an option below!\n");
    printf("1. Binary to Decimal Conversion\n");
    printf("2. Decimal to Binary Conversion\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            binaryToDecimal();
            break;
        case 2:
            decimalToBinary();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    printf("Thank you for using the curious Binary Converter. Come back soon!\n");
    return 0;
}