//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char hex[7];
    int r, g, b;

    printf("Welcome to the Color Code Converter!\n");
    printf("1. Convert Hexadecimal to RGB\n");
    printf("2. Convert RGB to Hexadecimal\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nYou have chosen to convert hexadecimal to RGB.\n");
            printf("Please enter the hexadecimal code (e.g. FF00FF): ");
            scanf("%s", hex);

            if (strlen(hex) != 6)
            {
                printf("\nInvalid hexadecimal code!\n");
                exit(0);
            }

            r = (int)strtol(&hex[0], NULL, 16);
            g = (int)strtol(&hex[2], NULL, 16);
            b = (int)strtol(&hex[4], NULL, 16);

            printf("\nThe RGB code for %s is (%d,%d,%d)\n", hex, r, g, b);
            break;

        case 2:
            printf("\nYou have chosen to convert RGB to hexadecimal.\n");
            printf("Please enter the values for red, green, and blue\n");
            printf("separated by a space (e.g. 255 0 255): ");
            scanf("%d %d %d", &r, &g, &b);

            if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
            {
                printf("\nInvalid RGB values!\n");
                exit(0);
            }

            sprintf(hex, "%02X%02X%02X", r, g, b);

            printf("\nThe hexadecimal code for (%d,%d,%d) is %s\n", r, g, b, hex);
            break;

        default:
            printf("\nInvalid choice!\n");
            exit(0);
    }

    return 0;
}