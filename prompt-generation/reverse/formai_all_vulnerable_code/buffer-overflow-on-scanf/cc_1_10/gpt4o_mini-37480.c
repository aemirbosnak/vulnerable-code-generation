//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void convertToHex(int number);
void convertToDecimal(const char *hexString);
void displayMenu();
void flushStdin();

int main() {
    int choice;
    char hexString[BUFFER_SIZE];
    int number;

    while (1) {
        displayMenu();
        
        printf("Please enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a numeric choice.\n");
            flushStdin();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid input. Please enter a valid decimal number.\n");
                    flushStdin();
                    continue;
                }
                convertToHex(number);
                break;
            case 2:
                printf("Enter a hexadecimal string: ");
                flushStdin(); // Clear input buffer
                fgets(hexString, BUFFER_SIZE, stdin);
                hexString[strcspn(hexString, "\n")] = 0; // Remove newline
                convertToDecimal(hexString);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}

void convertToHex(int number) {
    printf("Decimal: %d\n", number);
    printf("Hexadecimal: %X\n", number);
}

void convertToDecimal(const char *hexString) {
    char *endPtr;
    long int decimalValue = strtol(hexString, &endPtr, 16);
    
    if (*endPtr != '\0') {
        printf("Invalid hexadecimal string: %s\n", hexString);
    } else {
        printf("Hexadecimal: %s\n", hexString);
        printf("Decimal: %ld\n", decimalValue);
    }
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
}

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}