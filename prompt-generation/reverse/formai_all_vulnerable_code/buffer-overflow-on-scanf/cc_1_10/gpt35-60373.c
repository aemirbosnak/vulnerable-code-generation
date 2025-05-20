//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal_number) {
    int binary_number[1000], index = 0;
    while(decimal_number > 0) {
        binary_number[index] = decimal_number % 2;
        decimal_number /= 2;
        index++;
    }
     
    // Printing binary number
    printf("Binary representation: ");
    for(int i = index - 1; i >= 0; i--) {
        printf("%d", binary_number[i]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(long binary_number) {
    int decimal_number = 0, base = 1, remainder;
    while(binary_number > 0) {
        remainder = binary_number % 10;
        binary_number /= 10;
        decimal_number += remainder * base;
        base *= 2;
    }
     
    // Printing decimal number
    printf("Decimal representation: %d\n", decimal_number);
}

int main() {
    int choice, decimal_number;
    long binary_number;

    printf("********* Welcome to the Binary Converter *********\n");
     
    // Displaying menu
    printf("Enter 1 to convert decimal to binary\n");
    printf("Enter 2 to convert binary to decimal\n");
    printf("Enter 0 to exit\n");
     
    do {
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("Exiting binary converter...");
                break;
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &decimal_number);
                decimalToBinary(decimal_number);
                printf("\n");
                break;
            case 2:
                printf("Enter binary number: ");
                scanf("%ld", &binary_number);
                binaryToDecimal(binary_number);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}