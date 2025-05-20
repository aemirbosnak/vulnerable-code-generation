//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void hexToRgb(char hex[], int *r, int *g, int *b);
void rgbToHex(int r, int g, int b, char hex[]);
void printColor(int r, int g, int b);
void displayMenu();
int isValidHex(char hex[]);
int isValidRgb(int r, int g, int b);

int main() {
    int choice;
    char hexColor[7];
    int r, g, b;
    
    printf("=== C Color Code Converter ===\n");
    
    while(1) {
        displayMenu();
        printf("Enter your choice (1/2/3/4 or 0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for using the C Color Code Converter!\n");
            break;
        }
        
        switch(choice) {
            case 1:
                printf("Enter a hex color code (e.g., #FF5733): ");
                scanf("%6s", hexColor);
                // Check validity of the hex color
                if (isValidHex(hexColor)) {
                    hexToRgb(hexColor, &r, &g, &b);
                    printf("RGB Value: (%d, %d, %d)\n", r, g, b);
                    printColor(r, g, b);
                } else {
                    printf("Invalid hex color code. Please try again.\n");
                }
                break;

            case 2:
                printf("Enter RGB values (0-255) separated by spaces (e.g., 255 87 51): ");
                scanf("%d %d %d", &r, &g, &b);
                // Check validity of RGB values
                if (isValidRgb(r, g, b)) {
                    char hex[7];
                    rgbToHex(r, g, b, hex);
                    printf("Hex Color Code: #%s\n", hex);
                } else {
                    printf("Invalid RGB values. Each value should be between 0 and 255.\n");
                }
                break;

            case 3:
                printf("Displaying the color from the RGB values...\n");
                printColor(r, g, b);
                break;

            case 4:
                printf("Displaying the last selected hex value...\n");
                printf("Hex: #%s\n", hexColor);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void hexToRgb(char hex[], int *r, int *g, int *b) {
    // Convert hex string to RGB values
    char red[3], green[3], blue[3];
    strncpy(red, hex + 1, 2);
    strncpy(green, hex + 3, 2);
    strncpy(blue, hex + 5, 2);
    red[2] = green[2] = blue[2] = '\0';
    
    *r = (int)strtol(red, NULL, 16);
    *g = (int)strtol(green, NULL, 16);
    *b = (int)strtol(blue, NULL, 16);
}

void rgbToHex(int r, int g, int b, char hex[]) {
    // Convert RGB values to hex string
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

void printColor(int r, int g, int b) {
    // This function would typically require a graphical display
    // But for this console application, we will just inform the user
    printf("The color with RGB (%d, %d, %d) is displayed in the console.\n", r, g, b);
}

void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Convert Hex to RGB\n");
    printf("2. Convert RGB to Hex\n");
    printf("3. Display Color from RGB\n");
    printf("4. Display Last Hex Color\n");
}

int isValidHex(char hex[]) {
    return (hex[0] == '#' && strlen(hex) == 7);
}

int isValidRgb(int r, int g, int b) {
    return (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}