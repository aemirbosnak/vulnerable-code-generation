//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("========================================\n");
    printf("       RGB to Hex Color Converter       \n");
    printf("========================================\n");
    printf("Please enter the RGB values to convert:\n");
    printf("1. RGB\n");
    printf("2. Exit\n");
}

void rgbToHex(int r, int g, int b, char *hexColor) {
    sprintf(hexColor, "#%02X%02X%02X", r, g, b);
}

int main() {
    int r, g, b;
    char hexColor[8];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting the converter. Thank you!\n");
            break;
        } else if (choice == 1) {
            printf("Enter the Red (0-255): ");
            scanf("%d", &r);
            if (r < 0 || r > 255) {
                printf("Invalid input! Please enter a value between 0 and 255.\n");
                continue;
            }
            
            printf("Enter the Green (0-255): ");
            scanf("%d", &g);
            if (g < 0 || g > 255) {
                printf("Invalid input! Please enter a value between 0 and 255.\n");
                continue;
            }

            printf("Enter the Blue (0-255): ");
            scanf("%d", &b);
            if (b < 0 || b > 255) {
                printf("Invalid input! Please enter a value between 0 and 255.\n");
                continue;
            }

            rgbToHex(r, g, b, hexColor);
            printf("The Hexadecimal color code for RGB(%d, %d, %d) is: %s\n", r, g, b, hexColor);
        } else {
            printf("Invalid choice! Please select 1 or 2.\n");
        }
    }

    return 0;
}