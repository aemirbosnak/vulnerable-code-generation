//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define COLOR_NAME_SIZE 20
#define INPUT_SIZE 50

// Function prototypes
void rgbToHex(int r, int g, int b);
void hexToRgb(const char *hex);
int validateRgb(int r, int g, int b);
int validateHex(const char *hex);
void toUpperCase(char *str);

int main() {
    int r, g, b;
    char hex[INPUT_SIZE];

    printf("Color Code Converter: \n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("Choose an option (1 or 2): ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter RGB values (0-255) separated by spaces (e.g., 255 0 0): ");
            scanf("%d %d %d", &r, &g, &b);
            if (validateRgb(r, g, b)) {
                rgbToHex(r, g, b);
            } else {
                fprintf(stderr, "Invalid RGB values. Please enter values between 0 and 255.\n");
            }
            break;

        case 2:
            printf("Enter HEX color code (e.g., #FF5733): ");
            scanf("%s", hex);
            toUpperCase(hex); // Ensuring hex is uppercase for consistency
            if (validateHex(hex)) {
                hexToRgb(hex);
            } else {
                fprintf(stderr, "Invalid HEX code. Please enter a valid HEX format (e.g., #FF5733).\n");
            }
            break;

        default:
            fprintf(stderr, "Invalid option. Please select 1 or 2.\n");
            break;
    }

    return 0;
}

// Convert RGB to HEX
void rgbToHex(int r, int g, int b) {
    printf("HEX color code: #%02X%02X%02X\n", r, g, b);
}

// Convert HEX to RGB
void hexToRgb(const char *hex) {
    int r, g, b;
    sscanf(hex + 1, "%2X%2X%2X", &r, &g, &b);
    printf("RGB color values: (%d, %d, %d)\n", r, g, b);
}

// Validate RGB values
int validateRgb(int r, int g, int b) {
    return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
}

// Validate HEX code
int validateHex(const char *hex) {
    if (hex[0] != '#' || (strlen(hex) != 7)) {
        return 0;
    }
    for (int i = 1; i < 7; i++) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || 
               (hex[i] >= 'A' && hex[i] <= 'F'))) {
            return 0;
        }
    }
    return 1;
}

// Convert string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}