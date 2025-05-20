//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = (remainder - 10) + 'A';
        }
        decimal = decimal / 16;
        i++;
    }
    hex[i] = '\0';

    // Reversing the string to get the correct hexadecimal representation
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexToDecimal(const char *hex) {
    int decimal = 0;
    int base = 1;
    int length = strlen(hex);

    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}

// Main function
int main() {
    int choice;
    int number;
    char hex[20];

    printf("***********************************************\n");
    printf("          Welcome to Hexadecimal Converter!\n");
    printf("***********************************************\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Decimal to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToHex(number, hex);
                printf("Decimal %d in hexadecimal is %s\n", number, hex);
                break;

            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                number = hexToDecimal(hex);
                printf("Hexadecimal %s in decimal is %d\n", hex, number);
                break;

            case 3:
                printf("Thank you for using the Hexadecimal Converter!\n");
                printf("Goodbye! Have a great day!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("***********************************************\n");
    }
    return 0;
}