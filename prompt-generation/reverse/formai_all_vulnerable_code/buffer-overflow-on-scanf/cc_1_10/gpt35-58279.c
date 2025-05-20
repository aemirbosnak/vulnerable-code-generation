//FormAI DATASET v1.0 Category: Binary Converter ; Style: automated
#include<stdio.h>
#include<stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNum){
    int binaryArr[32]; // to store binary digits
    int i = 0;

    while (decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i++;
    }

    // printing binary in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArr[j]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(int binaryNum){
    int decimalNum = 0, base = 1, rem;
    while (binaryNum > 0) {
        rem = binaryNum % 10;
        decimalNum += rem * base;
        binaryNum /= 10;
        base *= 2;
    }
    printf("%d", decimalNum);
}

int main() {
    int choice, decimalNum, binaryNum;
    
    printf("Welcome to Binary Converter\n");

    // asking user for the choice of conversion
    printf("Enter 1 to convert Decimal to Binary\nEnter 2 to convert Binary to Decimal\n");
    scanf("%d", &choice);

    // performing conversion based on user choice
    switch(choice){
        case 1:
            // Converting Decimal to Binary
            printf("Enter the decimal number to convert to Binary: ");
            scanf("%d", &decimalNum);

            printf("The binary conversion of %d is: ", decimalNum);
            decimalToBinary(decimalNum);
            break;
        case 2:
            // Converting Binary to Decimal
            printf("Enter the binary number to convert to Decimal: ");
            scanf("%d", &binaryNum);

            printf("The decimal conversion of %d is: ", binaryNum);
            binaryToDecimal(binaryNum);
            break;
        default:
            printf("Invalid choice, Please try again\n");
    }
    return 0;
}