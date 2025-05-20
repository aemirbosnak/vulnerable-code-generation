//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void convertToHex(int num, char* hexBuffer) {
    sprintf(hexBuffer, "0x%X", num);
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("=========================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("=========================\n");
    printf("Choose an option (1 or 2): ");
}

int getDecimalInput() {
    int num;
    printf("Enter a decimal number: ");
    if (scanf("%d", &num) != 1) {
        while (getchar() != '\n');  // Clear the input buffer
        printf("Invalid input. Please enter a valid decimal number.\n");
        return getDecimalInput();
    }
    return num;
}

void convertAllNumbersToHex(int count, int* numbers) {
    printf("\nDecimal to Hexadecimal Conversion Results:\n");
    for (int i = 0; i < count; i++) {
        char hexBuffer[BUFFER_SIZE];
        convertToHex(numbers[i], hexBuffer);
        printf("Decimal: %d -> Hexadecimal: %s\n", numbers[i], hexBuffer);
    }
}

int main() {
    int choice;
    int numbers[BUFFER_SIZE];
    int count = 0;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("How many numbers do you want to convert? ");
                int n;
                scanf("%d", &n);
                if (n <= 0 || n > BUFFER_SIZE) {
                    printf("Please enter a number between 1 and %d\n", BUFFER_SIZE);
                    break;
                }
                for (int i = 0; i < n; i++) {
                    numbers[i] = getDecimalInput();
                }
                count = n;
                convertAllNumbersToHex(count, numbers);
                break;

            case 2:
                printf("Exiting the Hexadecimal Converter. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please select 1 or 2.\n");
                break;
        }
    }
    
    return 0;
}