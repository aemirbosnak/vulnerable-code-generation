//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hexToDecimal(char hex[]) {
    int decimalValue = 0;
    int base = 1;
    int i;
    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimalValue += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimalValue += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimalValue;
}

// Function to convert decimal to hexadecimal
char* decimalToHex(int decimal) {
    char* hex = (char*) malloc(20 * sizeof(char));
    int quotient, remainder;
    int i = 0;

    while (decimal != 0) {
        quotient = decimal / 16;
        remainder = decimal % 16;

        if (remainder < 10) {
            hex[i++] = remainder + 48;
        } else {
            hex[i++] = remainder + 55;
        }
        decimal = quotient;
    }

    // Reverse the string
    char* reversedHex = (char*) malloc(20 * sizeof(char));
    int j;
    for (j = strlen(hex) - 1; j >= 0; j--) {
        reversedHex[strlen(hex) - 1 - j] = hex[j];
    }
    reversedHex[strlen(hex)] = '\0';
    return reversedHex;
}

int main() {
    int choice;
    char value[20];

    do {
        printf("Welcome to the Color Code Converter!\n");
        printf("1. Convert HEX to RGB\n");
        printf("2. Convert RGB to HEX\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter a HEX color code: ");
                scanf("%s", &value);
                if (strlen(value) == 6) {
                    int r = hexToDecimal(value) >> 16;
                    int g = (hexToDecimal(value) >> 8) & 0xFF;
                    int b = hexToDecimal(value) & 0xFF;
                    printf("RGB: (%d, %d, %d)\n", r, g, b);
                } else {
                    printf("Invalid input!\n");
                }
                break;
            }
            case 2: {
                int r, g, b;
                printf("Enter the red value (0-255): ");
                scanf("%d", &r);
                printf("Enter the green value (0-255): ");
                scanf("%d", &g);
                printf("Enter the blue value (0-255): ");
                scanf("%d", &b);
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    printf("Invalid input!\n");
                    break;
                }
                int decimalValue = (r << 16) + (g << 8) + b;
                char* hexValue = decimalToHex(decimalValue);
                printf("HEX: #%s\n", hexValue);
                break;
            }
            case 3: {
                printf("Good bye!");
                exit(0);
            }
            default: {
                printf("Invalid choice!");
                break;
            }
        }

        printf("\n");

    } while (1);
    return 0;
}