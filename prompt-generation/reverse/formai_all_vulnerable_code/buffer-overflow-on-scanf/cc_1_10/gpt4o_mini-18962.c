//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// A structure to represent a color.
typedef struct {
    int r; // Red component
    int g; // Green component
    int b; // Blue component
} Color;

// Function Prototypes
Color hexToRgb(const char *hex);
void rgbToHex(Color color, char *hex);
void displayMenu();
void handleSelection(int choice);
void clearInputBuffer();

// Function to convert hexadecimal color to RGB
Color hexToRgb(const char *hex) {
    Color color;
    if (hex[0] == '#') {
        hex++; // Skip the '#' character
    }
    sscanf(hex, "%02x%02x%02x", &color.r, &color.g, &color.b);
    return color;
}

// Function to convert RGB color to hexadecimal
void rgbToHex(Color color, char *hex) {
    sprintf(hex, "#%02x%02x%02x", color.r, color.g, color.b);
}

// Function to display the main menu
void displayMenu() {
    printf("=================================\n");
    printf("    Welcome to the Color Code   \n");
    printf("    Converter, my dear Watson!  \n");
    printf("=================================\n");
    printf("1. Convert Hex to RGB\n");
    printf("2. Convert RGB to Hex\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

// Main function to run the program
int main() {
    int choice;
    char hexInput[MAX_INPUT_LENGTH];
    Color rgbColor;
    char hexOutput[MAX_INPUT_LENGTH];

    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // To avoid any leftover characters in the buffer

        switch (choice) {
            case 1:
                printf("Enter a Hex color code (e.g., #ff5733): ");
                fgets(hexInput, sizeof(hexInput), stdin);
                hexInput[strcspn(hexInput, "\n")] = 0; // Remove the newline character

                rgbColor = hexToRgb(hexInput);
                printf("RGB Color: (%d, %d, %d)\n", rgbColor.r, rgbColor.g, rgbColor.b);
                break;

            case 2:
                printf("Enter RGB values (e.g., 255 87 51): ");
                int r, g, b;
                scanf("%d %d %d", &r, &g, &b);
                
                // Check if the values are within the valid range
                if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)) {
                    printf("Invalid RGB values! They must be between 0 and 255.\n");
                } else {
                    rgbColor.r = r;
                    rgbColor.g = g;
                    rgbColor.b = b;

                    rgbToHex(rgbColor, hexOutput);
                    printf("Hex Color Code: %s\n", hexOutput);
                }
                break;

            case 3:
                printf("Thank you for using the Color Code Converter, my dear Watson. Exiting...\n");
                break;

            default:
                printf("Select a valid option (1-3).\n");
                break;
        }

        printf("\n"); // For better readability

    } while (choice != 3);

    return 0;
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n'); // Discard the rest of the line
}