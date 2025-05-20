//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayWelcome();
void showMenu();
void rgbToHex();
void hexToRgb();
long hexToDec(const char *hex);
void decToHex(long decimal);
void rgbToDec(int r, int g, int b);

int main() {
    int choice;

    displayWelcome();

    while (1) {
        showMenu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                rgbToHex();
                break;
            case 2:
                hexToRgb();
                break;
            case 3:
                printf("Thank you for using the Color Code Converter! Have a colorful day! 🌈\n");
                exit(0);
            default:
                printf("Uh-oh! Please enter a valid choice (1-3).\n");
        }
    }

    return 0;
}

void displayWelcome() {
    printf("******************************************\n");
    printf("🎨 Welcome to the Color Code Converter! 🎨\n");
    printf("******************************************\n");
}

void showMenu() {
    printf("\nHere are your choices:\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Convert Hexadecimal to RGB\n");
    printf("3. Exit\n");
}

void rgbToHex() {
    int r, g, b;

    printf("Enter the Red value (0-255): ");
    scanf("%d", &r);
    printf("Enter the Green value (0-255): ");
    scanf("%d", &g);
    printf("Enter the Blue value (0-255): ");
    scanf("%d", &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Oops! RGB values must be between 0 and 255. Please try again! 🎈\n");
        return;
    }

    printf("The Hexadecimal color code is: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb() {
    char hex[7];

    printf("Enter the Hexadecimal color code (e.g., #FF5733): ");
    scanf("%s", hex);

    if (hex[0] != '#' || (strlen(hex) != 7 && strlen(hex) != 4)) {
        printf("Oh no! The hex code must start with '#' and be 7 or 4 characters long! 🙈\n");
        return;
    }

    long decimal = hexToDec(hex);

    // Converting to RGB
    int r = (decimal >> 16) & 0xFF;
    int g = (decimal >> 8) & 0xFF;
    int b = decimal & 0xFF;

    printf("The RGB values are: Red = %d, Green = %d, Blue = %d\n", r, g, b);
}

long hexToDec(const char *hex) {
    long decimal = 0;
    for (int i = 1; hex[i] != '\0'; i++) {
        decimal *= 16;

        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else {
            decimal += hex[i] - 'a' + 10;  // Handle lowercase letters
        }
    }
    return decimal;
}

void decToHex(long decimal) {
    char hex[7] = "#000000";
    int r, g, b;

    b = decimal & 0xFF;
    g = (decimal >> 8) & 0xFF;
    r = (decimal >> 16) & 0xFF;

    sprintf(hex, "#%02X%02X%02X", r, g, b);
    printf("Hexadecimal: %s\n", hex);
}

void rgbToDec(int r, int g, int b) {
    long decimal = (r << 16) + (g << 8) + b;
    printf("Decimal representation: %ld\n", decimal);
}