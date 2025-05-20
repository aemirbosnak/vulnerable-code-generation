//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToRGB(const char* hex, int* r, int* g, int* b) {
    if (strlen(hex) != 7 || hex[0] != '#') {
        fprintf(stderr, "Error: Invalid hex format! It should be like #RRGGBB.\n");
        exit(EXIT_FAILURE);
    }
    
    *r = (int)strtol(hex + 1, NULL, 16);
    *g = (int)strtol(hex + 3, NULL, 16);
    *b = (int)strtol(hex + 5, NULL, 16);
}

void rgbToHex(int r, int g, int b, char* hex) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        fprintf(stderr, "Error: RGB values should be between 0 and 255!\n");
        exit(EXIT_FAILURE);
    }
    
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

void showMenu() {
    printf("===================================\n");
    printf("      Shocked Color Converter      \n");
    printf("===================================\n");
    printf("1. Convert Hex to RGB\n");
    printf("2. Convert RGB to Hex\n");
    printf("3. Exit\n");
    printf("===================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char hex[8];
    int r, g, b;
    char hexOutput[8];

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a hex color (e.g., #FF5733): ");
                scanf("%s", hex);
                hexToRGB(hex, &r, &g, &b);
                printf("SHOCKED! The RGB value is: (%d, %d, %d)\n", r, g, b);
                break;

            case 2:
                printf("Enter RGB values separated by spaces (e.g., 255 87 51): ");
                scanf("%d %d %d", &r, &g, &b);
                rgbToHex(r, g, b, hexOutput);
                printf("WOW! The Hex value is: %s\n", hexOutput);
                break;
            
            case 3:
                printf("Exiting... SHOCKINGLY!\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear the buffer
        getchar(); // Wait for user to press Enter
    }

    return 0;
}