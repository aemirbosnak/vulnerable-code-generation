//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: decentralized
// This is a C program to convert decimal numbers to binary and vice versa.
// The program takes input from the user and displays the output.

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int choice;
    char input[50];
    int decimal, binary[50];
    int i, j, remainder, length, temp;

    // Initializing variables
    decimal = 0;
    length = 0;
    temp = 0;

    // Displaying menu
    printf("Enter 1 to convert decimal to binary\n");
    printf("Enter 2 to convert binary to decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Taking input from user
    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%s", input);
        length = strlen(input);

        // Validating input
        for (i = 0; i < length; i++) {
            if (input[i] < '0' || input[i] > '9') {
                printf("Invalid input\n");
                return 0;
            }
        }

        // Converting decimal to binary
        for (i = length - 1; i >= 0; i--) {
            decimal += (input[i] - '0') * pow(2, length - 1 - i);
        }

        // Displaying binary number
        printf("Binary number: ");
        for (i = 0; i < 8; i++) {
            remainder = decimal % 2;
            binary[i] = remainder;
            decimal /= 2;
        }
        for (i = 0; i < 8; i++) {
            printf("%d", binary[i]);
        }
    }
    else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%s", input);
        length = strlen(input);

        // Validating input
        for (i = 0; i < length; i++) {
            if (input[i]!= '0' && input[i]!= '1') {
                printf("Invalid input\n");
                return 0;
            }
        }

        // Converting binary to decimal
        decimal = 0;
        for (i = 0; i < length; i++) {
            if (input[i] == '1') {
                decimal += pow(2, length - 1 - i);
            }
        }

        // Displaying decimal number
        printf("Decimal number: %d\n", decimal);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}