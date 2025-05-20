//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n***************************************\n");
    printf("   WELCOME TO THE COLOR CODE CONVERTER  \n");
    printf("***************************************\n");
    printf("Choose an option:\n");
    printf("1. Convert RGB to Hex Color Code\n");
    printf("2. Convert Hex Color Code to RGB\n");
    printf("3. Exit\n");
    printf("***************************************\n");
}

void rgbToHex() {
    int r, g, b;
    char hexColor[8];
    
    printf("Enter Red (0-255): ");
    scanf("%d", &r);
    printf("Enter Green (0-255): ");
    scanf("%d", &g);
    printf("Enter Blue (0-255): ");
    scanf("%d", &b);
    
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("\nERROR: Invalid RGB values! Must be between 0 and 255.\n");
        return;
    }
    
    snprintf(hexColor, sizeof(hexColor), "#%02X%02X%02X", r, g, b);
    printf("\nThe Hex color code for RGB(%d, %d, %d) is: %s\n", r, g, b, hexColor);
}

void hexToRgb() {
    char hexColor[7];
    int r, g, b;
    
    printf("Enter a Hex color code (without #, e.g., FF5733): ");
    scanf("%s", hexColor);

    // Check if the hex color input is 6 characters long
    if (strlen(hexColor) != 6) {
        printf("\nERROR: Invalid Hex color code! Must be 6 characters long.\n");
        return;
    }
    
    // Convert hex to RGB
    sscanf(hexColor, "%02X%02X%02X", &r, &g, &b);
    printf("\nThe RGB values for Hex #%s are: R(%d), G(%d), B(%d)\n", hexColor, r, g, b);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nConverting RGB to Hex...\n");
            rgbToHex();
        } else if (choice == 2) {
            printf("\nConverting Hex to RGB...\n");
            hexToRgb();
        } else if (choice == 3) {
            printf("\nExiting the Color Code Converter. Bye!\n");
            exit(0);
        } else {
            printf("\nERROR: Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}