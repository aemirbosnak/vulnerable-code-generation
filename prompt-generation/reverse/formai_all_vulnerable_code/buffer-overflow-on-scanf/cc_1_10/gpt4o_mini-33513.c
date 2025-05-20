//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void decToHex(int decimal, char hex[]) {
    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index] = remainder + '0';
        } else {
            hex[index] = remainder - 10 + 'A';
        }
        decimal /= 16;
        index++;
    }
    hex[index] = '\0';

    // Reverse the hex string
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void hexToDec(char hex[], int *decimal) {
    *decimal = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        *decimal *= 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            *decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            *decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            *decimal += hex[i] - 'a' + 10;
        }
    }
}

void rgbToHex(int r, int g, int b, char hex[]) {
    char rHex[3], gHex[3], bHex[3];
    decToHex(r, rHex);
    decToHex(g, gHex);
    decToHex(b, bHex);
    sprintf(hex, "#%s%s%s", rHex, gHex, bHex);
}

void hexToRgb(char hex[], int *r, int *g, int *b) {
    int decimal;
    
    // Extracting red component
    char rHex[3] = {hex[1], hex[2], '\0'};
    hexToDec(rHex, &decimal);
    *r = decimal;

    // Extracting green component
    char gHex[3] = {hex[3], hex[4], '\0'};
    hexToDec(gHex, &decimal);
    *g = decimal;

    // Extracting blue component
    char bHex[3] = {hex[5], hex[6], '\0'};
    hexToDec(bHex, &decimal);
    *b = decimal;
}

void displayMenu() {
    printf("Color Code Converter\n");
    printf("1. RGB to Hex\n");
    printf("2. Hex to RGB\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int r, g, b;
            char hex[8]; // Max length for a hex color code including '#'
            printf("Enter the red component (0-255): ");
            scanf("%d", &r);
            printf("Enter the green component (0-255): ");
            scanf("%d", &g);
            printf("Enter the blue component (0-255): ");
            scanf("%d", &b);

            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                printf("Error: RGB values must be between 0 and 255.\n");
            } else {
                rgbToHex(r, g, b, hex);
                printf("Hexadecimal Color Code: %s\n", hex);
            }
        } else if (choice == 2) {
            char hex[8];
            int r, g, b;
            printf("Enter the hexadecimal color code (e.g., #FF5733): ");
            scanf("%s", hex);

            if (hex[0] != '#' || strlen(hex) != 7) {
                printf("Error: Invalid hex color code format.\n");
            } else {
                hexToRgb(hex, &r, &g, &b);
                printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);
            }
        } else if (choice != 3) {
            printf("Invalid choice, please try again.\n");
        }

    } while (choice != 3);

    printf("Exiting the Color Code Converter. Goodbye!\n");
    return 0;
}