//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, char *binary);
void printBinaryRepresentation(int num);
void reverseString(char *str);
int power(int base, int exp);
int binaryToDecimal(const char *binary);

int main() {
    int choice;
    int number;
    char binary[32];

    printf("Welcome to the Binary Converter Program!\n");
    printf("This program converts decimal numbers to binary and vice versa.\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToBinary(number, binary);
                printf("Binary representation of %d is: %s\n", number, binary);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                number = binaryToDecimal(binary);
                printf("Decimal representation of binary %s is: %d\n", binary, number);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}

void decimalToBinary(int num, char *binary) {
    int index = 0;

    if (num == 0) {
        binary[index++] = '0';
        binary[index] = '\0';
        return;
    }

    while (num > 0) {
        binary[index++] = (num % 2) + '0'; // Convert int to char
        num = num / 2;
    }
    binary[index] = '\0';  // Null-terminate the string

    reverseString(binary);  // Reverse the binary string
}

void reverseString(char *str) {
    int start = 0;
    int end = 0;

    // Calculate string length
    while (str[end] != '\0') {
        end++;
    }
    end--;  // Adjust for null terminator

    // Swap characters to reverse the string
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int length = 0;

    // Calculate the length of binary string
    while (binary[length] != '\0') {
        length++;
    }

    // Convert binary to decimal
    for (int i = 0; i < length; i++) {
        if (binary[length - 1 - i] == '1') {
            decimal += power(2, i);
        }
    }

    return decimal;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}