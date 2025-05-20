//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that converts a hexadecimal value to decimal
int hexToDecimal(char hex[]) {
    int decimal = 0;
    int len = strlen(hex);

    for (int i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * pow(16, len-i-1);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * pow(16, len-i-1);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * pow(16, len-i-1);
        } else {
            printf("Error: Invalid hex code");
            exit(EXIT_FAILURE);
        }
    }

    return decimal;
}

// Function that converts RGB values to hexadecimal
void rgbToHex(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    printf("RGB code: (%d, %d, %d) -> Hex code: %s\n", red, green, blue, hex);
}

// Function that converts hexadecimal to RGB values
void hexToRgb(char hex[]) {
    int decimal[3];

    for (int i = 0, j = 0; i < strlen(hex); i += 2, j++) {
        char chunk[3] = {hex[i], hex[i+1], '\0'};
        decimal[j] = hexToDecimal(chunk);
    }

    printf("Hex code: %s -> RGB code: (%d, %d, %d)\n", hex, decimal[0], decimal[1], decimal[2]);
}

int main() {
    char choice;
    int red, green, blue;
    char hex[7];

    printf("Welcome to the Color Code Converter!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("3. Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the red value (0-255): ");
                scanf("%d", &red);
                printf("Enter the green value (0-255): ");
                scanf("%d", &green);
                printf("Enter the blue value (0-255): ");
                scanf("%d", &blue);
                rgbToHex(red, green, blue);
                break;
            case '2':
                printf("Enter the hex code (with or without #): ");
                scanf("%s", hex);
                if (hex[0] == '#') {
                    hexToRgb(hex+1);
                } else {
                    hexToRgb(hex);
                }
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                exit(EXIT_FAILURE);
        }
    } while (choice != '3');

    return 0;
}