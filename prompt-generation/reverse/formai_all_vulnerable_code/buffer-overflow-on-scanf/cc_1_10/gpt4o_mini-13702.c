//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertRGBtoHex(int r, int g, int b);
void convertHexToRGB(const char *hex);

int main() {
    int choice;
    printf("Welcome, Noble Coder, to the Color Code Converter.\n");
    printf("In this realm, you shall conjure colors from the depths of RGB or the arcane hex.\n");

    do {
        displayMenu();
        printf("Choose thy fate (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int r, g, b;
            printf("Enter the valor of Red (0-255): ");
            scanf("%d", &r);
            printf("Enter the valor of Green (0-255): ");
            scanf("%d", &g);
            printf("Enter the valor of Blue (0-255): ");
            scanf("%d", &b);
            convertRGBtoHex(r, g, b);
        } else if (choice == 2) {
            char hex[8];
            printf("Invoke the hex code (format: #RRGGBB): ");
            scanf("%s", hex);
            convertHexToRGB(hex);
        } else if (choice != 0) {
            printf("Alas! Such a choice is not within the tome of possibilities.\n");
        }
    } while (choice != 0);
    
    printf("Farewell, Noble Coder. May your codes compile without error.\n");
    return 0;
}

void displayMenu() {
    printf("\n--- Color Code Converter ---\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("-----------------------------\n");
}

void convertRGBtoHex(int r, int g, int b) {
    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255) {
        printf("Alas! The colors must be between 0 and 255.\n");
        return;
    }
    
    printf("Behold! RGB( %d, %d, %d ) shall transform into Hex: #", r, g, b);
    printf("%02X%02X%02X\n", r, g, b);
}

void convertHexToRGB(const char *hex) {
    if (hex[0] != '#' || (hex[1] == '\0')) {
        printf("Verily, thy input format is incorrect. Remember to start with '#'.\n");
        return;
    }

    int r, g, b;
    if (sscanf(hex, "#%02X%02X%02X", &r, &g, &b) != 3) {
        printf("Alas! Unable to decipher thy hex code.\n");
        return;
    }

    printf("From the depths of hex: %s, we retrieve RGB( %d, %d, %d )!\n", hex, r, g, b);
}