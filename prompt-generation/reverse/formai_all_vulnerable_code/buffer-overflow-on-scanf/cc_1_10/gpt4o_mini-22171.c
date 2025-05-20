//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>

void rgbToHex(int r, int g, int b, char *hex) {
    // Converting RGB values to Hexadecimal format
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

void getColorComponents(int *r, int *g, int *b) {
    // Getting RGB input from the user
    printf("Enter Red (0-255): ");
    scanf("%d", r);
    
    while (*r < 0 || *r > 255) {
        printf("Invalid input. Please enter a value between 0 and 255 for Red: ");
        scanf("%d", r);
    }
    
    printf("Enter Green (0-255): ");
    scanf("%d", g);
    
    while (*g < 0 || *g > 255) {
        printf("Invalid input. Please enter a value between 0 and 255 for Green: ");
        scanf("%d", g);
    }
    
    printf("Enter Blue (0-255): ");
    scanf("%d", b);
    
    while (*b < 0 || *b > 255) {
        printf("Invalid input. Please enter a value between 0 and 255 for Blue: ");
        scanf("%d", b);
    }
}

int main() {
    int r, g, b;
    char hexColor[8]; // Hex color code can take up to 7 characters (#RRGGBB + '\0')
    
    printf("Welcome to the RGB to Hex Color Converter!\n");
    printf("Please provide the RGB values to get the Hex code.\n");
    
    // Get color components from user
    getColorComponents(&r, &g, &b);
    
    // Convert to Hexadecimal
    rgbToHex(r, g, b, hexColor);
    
    // Display the result
    printf("The Hexadecimal color code for RGB(%d, %d, %d) is: %s\n", r, g, b, hexColor);
    
    // A little fun farewell
    printf("Thank you for using the RGB to Hex Color Converter!\n");
    printf("Have a colorful day ahead! 🌈\n");

    return 0;
}