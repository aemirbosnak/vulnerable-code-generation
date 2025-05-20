//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    if (decimal == 0) {
        hexadecimal[0] = '0';
        hexadecimal[1] = '\0';
        return;
    }
    
    int index = 0;
    
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = (remainder - 10) + 'A';
        }
        decimal = decimal / 16;
    }

    // Add null terminator at the end
    hexadecimal[index] = '\0';
    
    // Reverse the hexadecimal string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

void inputValidation(int *number) {
    char buffer[100];
    char *endptr;
    
    while (1) {
        printf("Please enter a positive integer: ");
        fgets(buffer, sizeof(buffer), stdin);
        *number = strtol(buffer, &endptr, 10);

        if (endptr == buffer || *number < 0) {
            printf("Invalid input. Try again.\n");
        } else {
            break;
        }
    }
}

void displayHexadecimal(int decimal) {
    char hexadecimal[50];
    decimalToHexadecimal(decimal, hexadecimal);
    printf("Decimal: %d => Hexadecimal: %s\n", decimal, hexadecimal);
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("----------------------\n");
    printf("1. Convert a Decimal Number\n");
    printf("2. Convert Multiple Decimal Numbers\n");
    printf("3. Exit\n");
}

void convertMultipleNumbers() {
    int count;
    printf("How many numbers would you like to convert? ");
    scanf("%d", &count);
    getchar();  // Clear the newline character from the buffer

    for (int i = 0; i < count; i++) {
        int number;
        inputValidation(&number);
        displayHexadecimal(number);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the buffer

        switch (choice) {
            case 1: {
                int number;
                inputValidation(&number);
                displayHexadecimal(number);
                break;
            }
            case 2:
                convertMultipleNumbers();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}