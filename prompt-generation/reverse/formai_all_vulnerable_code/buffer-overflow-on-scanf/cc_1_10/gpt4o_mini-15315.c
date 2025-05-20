//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n==============================\n");
    printf("   Welcome to Hexadecimal Converter\n");
    printf("==============================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

void convertDecimalToHex(int decimal) {
    char hex[20]; 
    int index = 0;

    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;
        
        // Convert remainder to hexadecimal character
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        
        decimal /= 16; 
    }
    
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]); // Print in reverse order
    }
    printf("\n");
}

void convertHexToDecimal(const char* hex) {
    int decimal = 0;
    
    for (int i = 0; hex[i] != '\0'; i++) {
        char current = hex[i];

        // Handle hexadecimal digits
        if (current >= '0' && current <= '9') {
            decimal = (decimal << 4) | (current - '0'); // Shifting left by 4
        } else if (current >= 'A' && current <= 'F') {
            decimal = (decimal << 4) | (current - 'A' + 10);
        } else if (current >= 'a' && current <= 'f') {
            decimal = (decimal << 4) | (current - 'a' + 10);
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
    }
    
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                convertDecimalToHex(decimal);
                break;
            }
            case 2: {
                char hex[20];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                convertHexToDecimal(hex);
                break;
            }
            case 3:
                printf("Thank you for using the Hexadecimal Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}