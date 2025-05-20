//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
/* Ken Thompson Style Color Code Converter */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, hex, r, g, b;
    float R, G, B;

    // Display menu
    printf("Color Code Converter\n");
    printf("1. Convert hex code to RGB\n");
    printf("2. Convert RGB code to hex\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // hex to RGB conversion
            printf("Enter hex code (without # prefix): ");
            scanf("%X", &hex);
            
            // Extract R, G, B values from hex code
            r = (hex >> 16) & 0xFF;
            g = (hex >> 8) & 0xFF;
            b = hex & 0xFF;

            // Print RGB values
            printf("RGB values: %d, %d, %d\n", r, g, b);
            break;

        case 2: // RGB to hex conversion
            printf("Enter RGB values (0-255):\n");
            printf("R: ");
            scanf("%f", &R);
            printf("G: ");
            scanf("%f", &G);
            printf("B: ");
            scanf("%f", &B);

            // Convert RGB to hex code
            hex = ((int)R << 16) | ((int)G << 8) | (int)B;

            // Print hex code
            printf("Hex code: #%06X\n", hex);
            break;

        default: // Invalid choice
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}