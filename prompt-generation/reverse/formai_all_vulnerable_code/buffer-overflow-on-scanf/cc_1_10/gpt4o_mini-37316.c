//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold RGB color
typedef struct {
    int r;
    int g;
    int b;
} RGB;

// Function Prototypes
RGB hexToRGB(const char* hex);
char* RGBToHex(RGB rgb);
void displayColor(RGB rgb);
void cleanInput(char* input);

int main() {
    char hexInput[8];
    RGB color;
    char decision = 'Y';

    printf("****************************************\n");
    printf("* Welcome to the Color Converter Tool   *\n");
    printf("* In a world turned to ash and dust...  *\n");
    printf("****************************************\n");
    printf("Convert between Hex and RGB color values.\n");

    while (decision == 'Y' || decision == 'y') {
        printf("\nPlease enter a hex color value (e.g., #FF5733): ");
        fgets(hexInput, sizeof(hexInput), stdin);
        cleanInput(hexInput);
        
        // Remove the '#' from the beginning of the hex string if present
        if (hexInput[0] == '#') {
            memmove(hexInput, hexInput + 1, strlen(hexInput));
        }

        // Convert hex to RGB
        color = hexToRGB(hexInput);

        // Display the RGB values
        printf("Converted RGB: (%d, %d, %d)\n", color.r, color.g, color.b);
        
        // Convert RGB back to Hex to validate
        char* hexOutput = RGBToHex(color);
        printf("Converted back to Hex: #%s\n", hexOutput);
        free(hexOutput);

        // Ask if the user wants to continue
        printf("Do you wish to convert another color? (Y/N): ");
        scanf(" %c", &decision);
        getchar(); // clear the newline character from the buffer
    }

    printf("The wasteland awaits. Farewell...\n");
    return 0;
}

// Function to convert hexadecimal string to RGB structure
RGB hexToRGB(const char* hex) {
    RGB rgb;

    // Assuming the hex string is always 6 characters long.
    if (strlen(hex) != 6) {
        fprintf(stderr, "Invalid hex input. Must be 6 characters long.\n");
        exit(EXIT_FAILURE);
    }

    // Parse the hex string
    sscanf(hex, "%2x%2x%2x", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

// Function to convert RGB structure to hexadecimal string format
char* RGBToHex(RGB rgb) {
    char* hex = (char*)malloc(8 * sizeof(char)); // Allocate space for hex string
    if (!hex) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(hex, "%02X%02X%02X", rgb.r, rgb.g, rgb.b); // Format as hexadecimal
    return hex;
}

// Function to display the RGB color visually in a terminal-supported way
void displayColor(RGB rgb) {
    // Note: Actual display comes out as a textual representation of the RGB values
    printf("Displaying color: R: %d, G: %d, B: %d\n", rgb.r, rgb.g, rgb.b);
}

// Helper function to remove newline or unwanted characters from input
void cleanInput(char* input) {
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}