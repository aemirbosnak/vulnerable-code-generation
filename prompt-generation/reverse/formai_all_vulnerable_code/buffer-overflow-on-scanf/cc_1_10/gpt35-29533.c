//FormAI DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int binaryToDecimal(int binaryNumber){
    int decimalNumber = 0, base = 1;

    while (binaryNumber > 0)
    {
        int lastDigit = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += lastDigit * base;
        base *= 2;
    }

    return decimalNumber;
}

int decimalToBinary(int decimalNumber){
    int binaryNumber = 0, base = 1;

    while(decimalNumber > 0){
        int lastDigit = decimalNumber % 2;
        binaryNumber += lastDigit * base;
        base *= 10;
        decimalNumber /= 2;
    }

    return binaryNumber;
}

int main(){
    int choice, number, answer;

    printf("Welcome to the Binary Converter!\n\n");

    while(1){
        printf("Please choose from the following options:\n");
        printf("1. Convert Binary to Decimal\n");
        printf("2. Convert Decimal to Binary\n");
        printf("3. Quit\n\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter a binary number: ");
                scanf("%d", &number);
                answer = binaryToDecimal(number);
                printf("%d in decimal is %d\n\n", number, answer);
                break;

            case 2:
                printf("\nEnter a decimal number: ");
                scanf("%d", &number);
                answer = decimalToBinary(number);
                printf("%d in binary is %d\n\n", number, answer);
                break;

            case 3:
                printf("\nThank you for using the Binary Converter!");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    }
    return 0;
}