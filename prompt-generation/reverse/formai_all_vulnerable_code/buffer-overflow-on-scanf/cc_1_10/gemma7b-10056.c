//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define neon_red 0xDC143C
#define neon_green 0x2CFF00
#define neon_blue 0x00BFFF

int main()
{
    char input[256];
    int r, g, b;

    printf("Enter the color code (e.g. rgb, hex): ");
    scanf("%s", input);

    // Convert RGB
    if (strcmp(input, "rgb") == 0)
    {
        printf("Enter the red value (0-255): ");
        scanf("%d", &r);
        printf("Enter the green value (0-255): ");
        scanf("%d", &g);
        printf("Enter the blue value (0-255): ");
        scanf("%d", &b);

        printf("Color code: rgb %d, %d, %d\n", r, g, b);
        printf("Equivalent hex code: #%02x%02x%02x\n", r, g, b);
        printf("Neon equivalent code: ");
        if (r == neon_red)
            printf("neon_red\n");
        else if (g == neon_green)
            printf("neon_green\n");
        else if (b == neon_blue)
            printf("neon_blue\n");
    }

    // Convert Hex
    else if (strcmp(input, "hex") == 0)
    {
        printf("Enter the hex code (e.g. #ff00ff): ");
        scanf("%s", input);

        r = strtol(input, NULL, 16);
        g = strtol(input + 1, NULL, 16);
        b = strtol(input + 3, NULL, 16);

        printf("Color code: rgb %d, %d, %d\n", r, g, b);
        printf("Equivalent hex code: #%02x%02x%02x\n", r, g, b);
        printf("Neon equivalent code: ");
        if (r == neon_red)
            printf("neon_red\n");
        else if (g == neon_green)
            printf("neon_green\n");
        else if (b == neon_blue)
            printf("neon_blue\n");
    }

    else
    {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}