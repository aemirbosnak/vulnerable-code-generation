//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 7
#define MAX_RGB_LENGTH 16

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

RGB hexToRGB(const char *hex) {
    RGB color = {0, 0, 0};
    if (hex[0] == '#') {
        hex++; // Skip the '#' character
    }

    sscanf(hex, "%2hhx%2hhx%2hhx", &color.r, &color.g, &color.b);
    
    return color;
}

void rgbToHex(RGB color, char *hex) {
    sprintf(hex, "#%02x%02x%02x", color.r, color.g, color.b);
}

void displayMenu() {
    printf("Color Code Converter\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char hex[MAX_HEX_LENGTH];
    RGB color;
    char hexOutput[MAX_HEX_LENGTH];
    
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a HEX color code (e.g., #ff5733): ");
                scanf("%s", hex);
                
                if (strlen(hex) < 7 || strlen(hex) > 7) {
                    printf("Error: Invalid HEX length. Ensure it includes '#' and is 7 characters long.\n");
                    break;
                }
                
                color = hexToRGB(hex);
                printf("RGB: (%d, %d, %d)\n", color.r, color.g, color.b);
                break;

            case 2:
                printf("Enter RGB values (0-255):\n");
                printf("Red: ");
                scanf("%hhu", &color.r);
                printf("Green: ");
                scanf("%hhu", &color.g);
                printf("Blue: ");
                scanf("%hhu", &color.b);
                
                rgbToHex(color, hexOutput);
                printf("HEX: %s\n", hexOutput);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
        }
        printf("\n");

    } while (choice != 3);
    
    return 0;
}