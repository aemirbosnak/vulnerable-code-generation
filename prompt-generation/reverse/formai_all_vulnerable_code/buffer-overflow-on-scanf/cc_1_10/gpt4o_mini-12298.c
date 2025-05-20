//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("Welcome to the Color Code Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("3. Exit\n");
}

void rgbToHex(int r, int g, int b) {
    printf("RGB (%d, %d, %d) to Hex: #%02X%02X%02X\n", r, g, b, r, g, b);
}

void hexToRgb(const char* hex) {
    if (hex[0] == '#') hex++;  // Skip the '#' character
    int r, g, b;
    sscanf(hex, "%2x%2x%2x", &r, &g, &b);
    printf("Hex #%s to RGB: (%d, %d, %d)\n", hex, r, g, b);
}

void handleConversions() {
    int choice = 0;

    while (choice != 3) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int r, g, b;
            printf("Enter RGB values (0-255), separated by spaces: ");
            scanf("%d %d %d", &r, &g, &b);
            
            if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
                rgbToHex(r, g, b);
            } else {
                printf("Invalid RGB values! Please enter values between 0-255.\n");
            }
        } else if (choice == 2) {
            char hex[8];
            printf("Enter a Hex color code (e.g. #RRGGBB): ");
            scanf("%s", hex);
            
            if (strnlen(hex, 8) == 7 || strnlen(hex, 8) == 6) {
                hexToRgb(hex);
            } else {
                printf("Invalid Hex format! Please use #RRGGBB or RRGGBB.\n");
            }
        } else if (choice == 3) {
            printf("Exiting the converter. Goodbye!\n");
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    handleConversions();
    return 0;
}