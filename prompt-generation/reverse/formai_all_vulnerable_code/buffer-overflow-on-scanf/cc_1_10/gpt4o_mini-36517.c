//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100

void convertToHex(int number, char *hexString) {
    sprintf(hexString, "%X", number);
}

int isValidNumber(const char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return 0; // Invalid character found
        }
    }
    return 1; // Valid number
}

int inputNumber() {
    char input[MAX_INPUT];
    
    while (1) {
        printf("Please enter a positive integer: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;
        
        if (isValidNumber(input)) {
            return atoi(input);
        } else {
            printf("Invalid input. Only positive integers are allowed.\n");
        }
    }
}

void displayHexadecimal(int number) {
    char hexString[MAX_INPUT];
    convertToHex(number, hexString);
    printf("The hexadecimal representation of %d is: %s\n", number, hexString);
}

void menu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Convert a number to hexadecimal\n");
    printf("2. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;
    int number;

    while (1) {
        menu();
        printf("Please select an option: ");
        scanf("%d", &choice);

        // Handle input buffer to prevent any issues
        while(getchar() != '\n');

        switch (choice) {
            case 1:
                number = inputNumber();
                displayHexadecimal(number);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}