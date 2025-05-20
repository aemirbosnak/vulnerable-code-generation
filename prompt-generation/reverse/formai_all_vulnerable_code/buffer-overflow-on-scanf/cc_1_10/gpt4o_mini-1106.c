//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void clearInputBuffer() {
    while (getchar() != '\n');
}

void toHexadecimal(int decimal, char *hex) {
    sprintf(hex, "%X", decimal);
}

int isValidDecimal(const char *input) {
    // Check if input is a valid decimal number
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

void inputData(char *inputBuffer, size_t size) {
    if (fgets(inputBuffer, size, stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    // Remove newline character if present
    size_t len = strlen(inputBuffer);
    if (len > 0 && inputBuffer[len - 1] == '\n') {
        inputBuffer[len - 1] = '\0';
    }
}

void convertAndDisplayHexadecimal() {
    char input[MAX_INPUT_SIZE];
    char hexadecimal[MAX_INPUT_SIZE];
    
    printf("Enter a decimal number to convert to hexadecimal: ");
    
    // Read input
    inputData(input, sizeof(input));

    // Validate input
    if (!isValidDecimal(input)) {
        printf("Invalid input. Please enter a valid decimal number.\n");
        return;
    }

    // Convert to decimal
    int decimal = atoi(input);
    
    // Convert to hexadecimal string
    toHexadecimal(decimal, hexadecimal);
    
    // Display the result
    printf("Decimal: %d → Hexadecimal: %s\n", decimal, hexadecimal);
}

void displayMenu() {
    printf("--------- Hexadecimal Converter ---------\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("----------------------------------------\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            clearInputBuffer(); // clear invalid input
            continue;
        }

        clearInputBuffer(); // clear newline character from buffer

        switch (choice) {
            case 1:
                convertAndDisplayHexadecimal();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}