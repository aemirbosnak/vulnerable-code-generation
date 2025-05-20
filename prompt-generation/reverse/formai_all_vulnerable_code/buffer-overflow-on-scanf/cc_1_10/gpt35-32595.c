//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void decToBinary(int decimalNumber);
int binaryToDecimal(long long binaryNumber);
void welcomeMessage();

int main() {
    int choice, decimalNumber, result;
    long long binaryNumber;

    welcomeMessage();

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the decimal number: ");
                scanf("%d", &decimalNumber);
                printf("The binary equivalent of %d is ", decimalNumber);
                decToBinary(decimalNumber);
                break;
            case 2:
                printf("\nEnter the binary number: ");
                scanf("%lld", &binaryNumber);
                result = binaryToDecimal(binaryNumber);
                printf("The decimal equivalent of %lld is %d", binaryNumber, result);
                break;
            case 3:
                printf("\nThank you for using the Binary Converter.");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose again.");
        }
    }

    return 0;
}

// Function to convert decimal number to binary
void decToBinary(int decimalNumber) {
    int binaryNumber[1000], i = 0;

    while(decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
}

// Function to convert binary number to decimal
int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    while(binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        i++;
    }

    return decimalNumber;
}

// Function to display welcome message
void welcomeMessage() {
    printf("\n********************************");
    printf("\n* Welcome to Binary Converter! *");
    printf("\n********************************");
    printf("\n\n1. Decimal to Binary Conversion\n2. Binary to Decimal Conversion\n3. Exit");
}