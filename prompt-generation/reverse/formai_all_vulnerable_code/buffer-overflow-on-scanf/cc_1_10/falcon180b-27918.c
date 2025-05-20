//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33]; // Maximum length of binary number is 32 bits + 1 for null terminator
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    printf("Binary: %s\n", binary);
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    while (*binary) {
        decimal += (*binary - '0') * pow(2, power);
        power++;
        binary++;
    }
    return decimal;
}

int main() {
    int choice;
    char input[33];

    // Loop until user chooses to exit
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a decimal number: ");
            scanf("%s", input);
            decimal_to_binary(atoi(input));
        }
        else if (choice == 2) {
            printf("Enter a binary number: ");
            scanf("%s", input);
            int decimal = binary_to_decimal(input);
            printf("Decimal: %d\n", decimal);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}