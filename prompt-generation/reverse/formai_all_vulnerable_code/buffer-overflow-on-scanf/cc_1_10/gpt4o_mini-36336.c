//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void hexToRGB(const char *hex);
void rgbToHex(int r, int g, int b);
void displayMenu();
char* trimWhitespace(char* str);

int main() {
    int choice;
    char hexColor[8];
    int r, g, b;

    printf("Welcome to the Futuristic Color Code Converter!\n");
    printf("===============================================\n");

    do {
        displayMenu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("Enter hex color code (e.g. #FF5733): ");
                fgets(hexColor, sizeof(hexColor), stdin);
                trimWhitespace(hexColor);
                hexToRGB(hexColor);
                break;
            case 2:
                printf("Enter RGB values (R G B): ");
                scanf("%d %d %d", &r, &g, &b);
                rgbToHex(r, g, b);
                break;
            case 3:
                printf("Exiting the color converter. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to convert HEX to RGB
void hexToRGB(const char *hex) {
    int r, g, b;
    // Check for invalid hex format
    if (hex[0] != '#' || strlen(hex) != 7) {
        printf("Invalid hexadecimal color code format!\n");
        return;
    }
    // Convert hex to RGB
    sscanf(hex + 1, "%02x%02x%02x", &r, &g, &b);
    printf("RGB Color: (%d, %d, %d)\n", r, g, b);
}

// Function to convert RGB to HEX
void rgbToHex(int r, int g, int b) {
    // Validate RGB values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("RGB values must be between 0 and 255!\n");
        return;
    }
    printf("Hex Color: #%02X%02X%02X\n", r, g, b);
}

// Display menu options
void displayMenu() {
    printf("Menu:\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("3. Exit\n");
}

// Trim whitespace from a string
char* trimWhitespace(char* str) {
    char *end;
    // Trim leading space
    while (isspace((unsigned char)*str)) str++;
    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}