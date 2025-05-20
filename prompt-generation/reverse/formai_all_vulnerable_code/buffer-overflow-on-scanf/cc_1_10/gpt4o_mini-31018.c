//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void rgbToHex(int r, int g, int b);
void hexToRgb(const char *hex);
void displayMenu();
void clearInputBuffer();

int main() {
    int choice, r, g, b;
    char hex[8]; // To store the hex value as a string

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter RGB values (0-255) separated by space (r g b): ");
                scanf("%d %d %d", &r, &g, &b);
                clearInputBuffer();
                if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
                    rgbToHex(r, g, b);
                } else {
                    printf("Invalid RGB values. Please enter values in the range [0, 255].\n");
                }
                break;
            
            case 2:
                printf("Enter HEX value (e.g., #FFAABB): ");
                fgets(hex, sizeof(hex), stdin);
                if (hex[0] == '#') {
                    hexToRgb(hex);
                } else {
                    printf("Invalid HEX format. Make sure to start with #.\n");
                }
                break;
            
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
    return 0;
}

void rgbToHex(int r, int g, int b) {
    printf("Hex Code: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex, "#%02x%02x%02x", &r, &g, &b) == 3) {
        printf("RGB Values: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Error converting HEX to RGB. Please check the format.\n");
    }
}

void displayMenu() {
    printf("\n--- Color Code Converter ---\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("3. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}