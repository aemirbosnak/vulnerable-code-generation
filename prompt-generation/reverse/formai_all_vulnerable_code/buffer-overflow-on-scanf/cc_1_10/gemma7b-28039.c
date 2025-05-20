//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char color_name[20];
    int red, green, blue, yellow, orange, pink;

    printf("Well, dear reader, I have a mystery for you: a color code converter. Please provide me with the color name and I shall reveal its secret.\n");

    scanf("%s", color_name);

    // Crack the code based on the color name
    if (strcmp(color_name, "red") == 0)
    {
        red = 255;
        green = 0;
        blue = 0;
    }
    else if (strcmp(color_name, "green") == 0)
    {
        red = 0;
        green = 255;
        blue = 0;
    }
    else if (strcmp(color_name, "blue") == 0)
    {
        red = 0;
        green = 0;
        blue = 255;
    }
    else if (strcmp(color_name, "yellow") == 0)
    {
        red = 255;
        green = 255;
        blue = 0;
    }
    else if (strcmp(color_name, "orange") == 0)
    {
        red = 255;
        green = 165;
        blue = 0;
    }
    else if (strcmp(color_name, "pink") == 0)
    {
        red = 255;
        green = 192;
        blue = 203;
    }
    else
    {
        printf("I'm afraid I cannot crack that code, dear reader.\n");
    }

    // Print the color values
    printf("So, the color code for %s is: Red: %d, Green: %d, Blue: %d.\n", color_name, red, green, blue);

    return 0;
}