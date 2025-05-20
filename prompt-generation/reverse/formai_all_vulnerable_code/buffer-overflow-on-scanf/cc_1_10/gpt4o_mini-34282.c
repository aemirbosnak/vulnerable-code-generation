//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("===================================\n");
    printf("  Surprise! Hexadecimal Converter   \n");
    printf("===================================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("===================================\n");
    printf("Choose an option (1-3): ");
}

void decimalToHexadecimal() {
    int decimal;
    char hex[20]; // Buffer for hexadecimal representation
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    // Surprising conversion
    sprintf(hex, "%X", decimal); // Convert decimal to hex using sprintf
    printf("Wow! The hexadecimal representation of %d is: %s\n", decimal, hex);
}

void hexadecimalToDecimal() {
    char hex[20];
    unsigned long decimal;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    // Surprising conversion
    decimal = strtoul(hex, NULL, 16); // Convert hex to decimal
    printf("Amazing! The decimal representation of %s is: %lu\n", hex, decimal);
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                decimalToHexadecimal();
                break;
            case 2:
                hexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting... \n");
                printf("Thank you for using the Surprise Hexadecimal Converter!\n");
                break;
            default:
                printf("Oops! That's an invalid choice, please select again!\n");
                break;
        }
        printf("\n");
    } while (choice != 3); // Loop until the user chooses to exit

    return 0;
}