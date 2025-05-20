//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToRGB(char *hexCode) {
    if (hexCode[0] == '#') {
        hexCode++;
    }

    int r, g, b;
    sscanf(hexCode, "%2x%2x%2x", &r, &g, &b);
    printf("RGB: (%d, %d, %d)\n", r, g, b);
}

void rgbToHex(int r, int g, int b) {
    printf("Hex: #%.2X%.2X%.2X\n", r, g, b);
}

void printMenu() {
    printf("\nColor Code Converter\n");
    printf("1. Convert Hex to RGB\n");
    printf("2. Convert RGB to Hex\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            char hexCode[8];
            printf("Enter hex color code (like #FFFFFF or FFFFFF): ");
            scanf("%s", hexCode);
            hexToRGB(hexCode);
        } else if (choice == 2) {
            int r, g, b;
            printf("Enter RGB values (0-255) separated by spaces: ");
            scanf("%d %d %d", &r, &g, &b);

            if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)) {
                printf("RGB values must be in the range 0-255.\n");
            } else {
                rgbToHex(r, g, b);
            }
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}