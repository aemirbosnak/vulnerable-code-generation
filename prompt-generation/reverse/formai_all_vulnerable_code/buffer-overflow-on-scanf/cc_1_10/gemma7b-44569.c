//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    printf("Enter a color name: ");
    scanf("%s", input);

    // Create a mapping of color names to their RGB values
    char **color_map = (char**)malloc(sizeof(char*) * 10);
    color_map[0] = "Red";
    color_map[1] = "Green";
    color_map[2] = "Blue";
    color_map[3] = "Yellow";
    color_map[4] = "Orange";
    color_map[5] = "Purple";

    // Check if the input color name is in the map
    int i = 0;
    while (i < 6 && strcmp(input, color_map[i]) != 0)
    {
        i++;
    }

    // If the color name is found, print its RGB values
    if (i < 6)
    {
        printf("RGB values for %s: ", input);
        switch (i)
        {
            case 0:
                printf("R: 255, G: 0, B: 0\n");
                break;
            case 1:
                printf("R: 0, G: 255, B: 0\n");
                break;
            case 2:
                printf("R: 0, G: 0, B: 255\n");
                break;
            case 3:
                printf("R: 255, G: 255, B: 0\n");
                break;
            case 4:
                printf("R: 255, G: 165, B: 0\n");
                break;
            case 5:
                printf("R: 128, G: 0, B: 128\n");
                break;
        }
    }
    else
    {
        printf("Error: Color name not found.\n");
    }

    return 0;
}