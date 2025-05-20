//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_color[20];
    int red, green, blue, alpha;

    printf("Enter the color code (RGB/Hex): ");
    scanf("%s", input_color);

    // Convert RGB/Hex to integers
    if (strcmp(input_color, "RGB") == 0)
    {
        printf("Enter the red value: ");
        scanf("%d", &red);

        printf("Enter the green value: ");
        scanf("%d", &green);

        printf("Enter the blue value: ");
        scanf("%d", &blue);

        printf("Enter the alpha value (optional): ");
        scanf("%d", &alpha);
    }
    else if (strcmp(input_color, "Hex") == 0)
    {
        printf("Enter the RGB values in Hex (e.g. #RRGGBB): ");
        scanf("%x %x %x", &red, &green, &blue);

        printf("Enter the alpha value (optional): ");
        scanf("%x", &alpha);
    }
    else
    {
        printf("Invalid color code format. Please try again.\n");
        return 1;
    }

    // Convert the color values to a string
    char output_color[20];
    sprintf(output_color, "Color: %d, %d, %d, %d", red, green, blue, alpha);

    // Print the converted color code
    printf("%s\n", output_color);

    return 0;
}