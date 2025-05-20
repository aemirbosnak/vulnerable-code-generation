//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHexadecimal(int decimal, char* hex) {
    sprintf(hex, "%X", decimal);
}

int hexadecimalToDecimal(const char* hex) {
    return (int)strtol(hex, NULL, 16);
}

void displayMenu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;
    char hex[20];
    int decimal;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                
                decimalToHexadecimal(decimal, hex);
                printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hex);
                break;

            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                
                decimal = hexadecimalToDecimal(hex);
                printf("Hexadecimal: %s -> Decimal: %d\n", hex, decimal);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}