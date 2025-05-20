//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void hexToRGB(char *hex, int *r, int *g, int *b) {
    if (hex[0] == '#') {
        hex++;
    }

    *r = (int)strtol(hex, NULL, 16);
    *g = (int)strtol(hex + 2, NULL, 16);
    *b = (int)strtol(hex + 4, NULL, 16);
}

void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

void printWelcomeMessage() {
    printf("🎨🌈 Welcome to the Color Code Converter! 🌈🎨\n");
    printf("You can convert between Hexadecimal and RGB color codes.\n\n");
}

void printGoodbyeMessage() {
    printf("🎉 Thank you for using the Color Code Converter! Goodbye! 🎉\n");
}

int main() {
    char hex[8];
    int r, g, b;
    char continueConversion;
    
    printWelcomeMessage();

    do {
        printf("Please enter a hexadecimal color code (e.g., #FF5733): ");
        scanf("%s", hex);

        // Convert hex to RGB
        hexToRGB(hex, &r, &g, &b);
        printf("The RGB equivalent of %s is: R=%d, G=%d, B=%d\n\n", hex, r, g, b);
        
        char hexConvertedBack[8];
        // Convert back to Hex
        rgbToHex(r, g, b, hexConvertedBack);
        printf("And converting back gives us the hex code: %s\n\n", hexConvertedBack);
        
        printf("Would you like to convert another color? (y/n): ");
        scanf(" %c", &continueConversion);
        
        if (continueConversion != 'y' && continueConversion != 'Y') {
            break;
        }
        
    } while (1);

    printGoodbyeMessage();
    return 0;
}