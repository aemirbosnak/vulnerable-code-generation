//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLORS 256

// Function prototypes
void generate_color_codes(char* color_name, int* r, int* g, int* b);
void print_color_codes(int r, int g, int b);

int main() {
    char color_name[20];
    int r, g, b;

    // Get user input for color name
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Generate RGB color codes
    generate_color_codes(color_name, &r, &g, &b);

    // Print color codes in various formats
    printf("RGB color code: %d, %d, %d\n", r, g, b);
    printf("Hexadecimal color code: #%02X%02X%02X\n", r, g, b);
    printf("HSL color code: %d, %d%, %d%s\n", r, g, b, "%");

    // Convert color codes to grayscale
    int gray = (r + g + b) / 3;
    printf("Grayscale color code: %d\n", gray);

    return 0;
}

// Function to generate RGB color codes based on color name
void generate_color_codes(char* color_name, int* r, int* g, int* b) {
    int hash = 0;

    // Convert color name to lowercase
    for (int i = 0; i < strlen(color_name); i++) {
        color_name[i] = tolower(color_name[i]);
    }

    // Calculate hash of color name
    for (int i = 0; i < strlen(color_name); i++) {
        hash = (hash * 31) + color_name[i];
    }

    // Convert hash to RGB color codes
    *r = (int) (hash % MAX_COLORS / (MAX_COLORS / 256));
    *g = (int) (hash % MAX_COLORS / (MAX_COLORS / 256));
    *b = (int) (hash % MAX_COLORS / (MAX_COLORS / 256));
}

// Function to print color codes in various formats
void print_color_codes(int r, int g, int b) {
    printf("RGB color code: %d, %d, %d\n", r, g, b);
    printf("Hexadecimal color code: #%02X%02X%02X\n", r, g, b);
    printf("HSL color code: %d, %d%, %d%s\n", r, g, b, "%");
}