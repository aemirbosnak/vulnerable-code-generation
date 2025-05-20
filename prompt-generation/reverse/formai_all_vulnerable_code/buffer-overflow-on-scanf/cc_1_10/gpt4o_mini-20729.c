//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void rgbToHex(int r, int g, int b) {
    printf("HEX Color Code: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%2x%2x%2x", &r, &g, &b) == 3) {
        printf("RGB Color: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid HEX code format.\n");
    }
}

void displayMenu() {
    printf("Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input, please enter a number.\n");
            // Clear invalid input from buffer
            while(getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                int r, g, b;
                printf("Enter RGB values (0-255) separated by spaces: ");
                if (scanf("%d %d %d", &r, &g, &b) != 3 || 
                    r < 0 || r > 255 || 
                    g < 0 || g > 255 || 
                    b < 0 || b > 255) {
                    fprintf(stderr, "Invalid RGB values. Please enter values between 0 and 255.\n");
                    // Clear invalid input from buffer
                    while(getchar() != '\n');
                } else {
                    rgbToHex(r, g, b);
                }
                break;
            }
            case 2: {
                char hex[8]; 
                printf("Enter HEX color code (e.g. #FF5733): ");
                scanf("%s", hex);
                hexToRgb(hex);
                break;
            }
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                fprintf(stderr, "Invalid choice, please select from the menu.\n");
        }
        printf("\n");
    }
    return 0;
}