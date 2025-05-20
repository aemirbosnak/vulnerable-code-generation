//FormAI DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <math.h>

// function to convert binary to decimal
int binToDec(long long n) {
    int decimal = 0, i = 0, remainder;
    // loop to calculate decimal value
    while(n != 0) {
        remainder = n % 10;
        n /= 10;
        decimal += remainder * pow(2, i);
        i++;
    }
    return decimal;
}

// function to convert decimal to binary
long long decToBin(int n) {
    // declaring variables
    int i = 1, remainder;
    long long binary = 0;
    // loop to calculate binary value
    while(n != 0) {
        remainder = n % 2;
        n /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int main() {
    // declaring variables
    long long binary;
    int decimal, choice;
    // prompting user to choose the conversion type
    printf("Please choose conversion type:\n1. Binary to Decimal\n2. Decimal to Binary\n");
    scanf("%d", &choice);
    // switch statement to perform the conversion based on user choice
    switch(choice) {
        case 1:
            // prompting user to enter binary number
            printf("Enter a binary number: ");
            scanf("%lld", &binary);
            // calling the function to convert binary to decimal
            decimal = binToDec(binary);
            // displaying the decimal value
            printf("%lld in binary = %d in decimal\n", binary, decimal);
            break;
        case 2:
            // prompting user to enter decimal number
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            // calling the function to convert decimal to binary
            binary = decToBin(decimal);
            // displaying the binary value
            printf("%d in decimal = %lld in binary\n", decimal, binary);
            break;
        default:
            // displaying error message if user choice is invalid
            printf("Invalid choice!\n");
    }
    return 0;
}