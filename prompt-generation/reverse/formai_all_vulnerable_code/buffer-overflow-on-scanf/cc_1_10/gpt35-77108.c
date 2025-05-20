//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

/* Function to convert RGB values to hex code */
void RGBtoHex(int r, int g, int b)
{
    /* Compute hex code */
    int hex = (r << 16) | (g << 8) | b;
    
    /* Print hex code */
    printf("#%06X\n", hex);
}

/* Function to convert hex code to RGB values */
void HexToRGB(char *hexCode)
{
    /* Convert hex code to integer */
    int hex = (int) strtol(hexCode + 1, NULL, 16);

    /* Extract RGB values */
    int r = (hex >> 16) & 255;
    int g = (hex >> 8) & 255;
    int b = hex & 255;
    
    /* Print RGB values */
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);
}

int main()
{
    /* Prompt user for input */
    char choice;
    printf("Enter 'H' for hex code to RGB or 'R' for RGB to hex code: ");
    scanf("%c", &choice);
    
    /* Get input and call appropriate function */
    if (choice == 'H') {
        char hex[7];
        printf("Enter hex code (without #): ");
        scanf("%s", hex);
        HexToRGB(hex);
    }
    else if (choice == 'R') {
        int r, g, b;
        printf("Enter red value (0-255): ");
        scanf("%d", &r);
        printf("Enter green value (0-255): ");
        scanf("%d", &g);
        printf("Enter blue value (0-255): ");
        scanf("%d", &b);
        RGBtoHex(r, g, b);
    }
    else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}