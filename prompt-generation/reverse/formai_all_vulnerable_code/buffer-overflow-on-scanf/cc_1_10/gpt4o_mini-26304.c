//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 8 // Maximum length for a HEX color code
#define MAX_RGB_LENGTH 20   // Maximum length for RGB representation

// Function prototypes
void hexToRgb(const char* hexColor);
void rgbToHex(int r, int g, int b);
int isHexColorValid(const char* hexColor);

int main() {
    char hexColor[MAX_COLOR_LENGTH];
    int r, g, b;
    int option;
    
    printf("🎨 Welcome to the C Color Code Converter! 🎉\n");
    printf("Choose an option:\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("\nEnter HEX color code (e.g., #FF5733): ");
            scanf("%s", hexColor);
            if (isHexColorValid(hexColor)) {
                hexToRgb(hexColor);
            } else {
                printf("❌ Invalid HEX color code! Please try again.\n");
            }
            break;
        case 2:
            printf("\nEnter RGB values (format: R G B): ");
            scanf("%d %d %d", &r, &g, &b);
            if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
                rgbToHex(r, g, b);
            } else {
                printf("❌ Invalid RGB values! Each value should be between 0 and 255.\n");
            }
            break;
        default:
            printf("❌ Invalid option! Please choose 1 or 2.\n");
            break;
    }
    
    printf("\nThank you for using the C Color Code Converter! 🌈\n");
    return 0;
}

void hexToRgb(const char* hexColor) {
    int r, g, b;
    
    // Skip the '#' character
    if (hexColor[0] == '#') {
        sscanf(hexColor + 1, "%02x%02x%02x", &r, &g, &b);
    } else {
        sscanf(hexColor, "%02x%02x%02x", &r, &g, &b);
    }
    
    printf("🎨 RGB equivalent: R=%d, G=%d, B=%d\n", r, g, b);
}

void rgbToHex(int r, int g, int b) {
    printf("🔵 HEX equivalent: #%02X%02X%02X\n", r, g, b);
}

int isHexColorValid(const char* hexColor) {
    // Check if the length is correct (7 or 4)
    if (strlen(hexColor) != 7 && strlen(hexColor) != 4) {
        return 0; // Invalid length
    }
    
    // Check that the string starts with '#'
    if (hexColor[0] != '#') {
        return 0; // Must start with '#'
    }
    
    // Validate the rest of the HEX string
    const char* validHexChars = "0123456789ABCDEFabcdef";
    for (int i = 1; i < strlen(hexColor); i++) {
        if (!strchr(validHexChars, hexColor[i])) {
            return 0; // Invalid character found
        }
    }
    
    return 1; // Valid HEX color
}