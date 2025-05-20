//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a color structure
typedef struct Color {
    int r;
    int g;
    int b;
} Color;

// Function to convert RGB values to Hex Code
char *rgb_to_hex(int r, int g, int b)
{
    char *hex_code = (char *)malloc(sizeof(char) * 7);
    sprintf(hex_code, "#%02x%02x%02x", r, g, b);
    return hex_code;
}

// Function to convert Hex Code to RGB values
Color *hex_to_rgb(char *hex_code)
{
    Color *rgb = (Color *)malloc(sizeof(Color));
    int r, g, b;
    sscanf(hex_code, "#%02x%02x%02x", &r, &g, &b);
    rgb->r = r;
    rgb->g = g;
    rgb->b = b;
    return rgb;
}

int main()
{
    int choice;
    char hex[7];
    Color *rgb;

    printf("Welcome to the Color Converter program!\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Convert RGB values to Hex Code\n");
        printf("2. Convert Hex Code to RGB values\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter RGB values (separate with spaces): ");
                int r, g, b;
                scanf("%d %d %d", &r, &g, &b);

                char *hex_code = rgb_to_hex(r, g, b);
                printf("\nHex Code: %s\n\n", hex_code);
                free(hex_code);

                break;

            case 2:
                printf("\nEnter Hex Code: ");
                scanf("%s", hex);

                // Remove any '#' prefix
                if (hex[0] == '#') {
                    memmove(hex, hex + 1, strlen(hex));
                }

                rgb = hex_to_rgb(hex);
                printf("\nRGB values: %d %d %d\n\n", rgb->r, rgb->g, rgb->b);
                free(rgb);

                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice, try again.\n\n");
                break;
        }
    }

    return 0;
}