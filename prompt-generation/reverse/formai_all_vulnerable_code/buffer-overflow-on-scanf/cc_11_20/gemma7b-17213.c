//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char input_color_code[20];
    int red, green, blue, alpha;
    int valid_color_code = 0;

    // Get the input color code from the user
    printf("Enter a valid color code (RRGGBBA): ");
    scanf("%s", input_color_code);

    // Validate the input color code
    if (strlen(input_color_code) == 7)
    {
        // Check if the input color code is numeric
        for (int i = 0; i < 7; i++)
        {
            if (!isdigit(input_color_code[i]))
            {
                valid_color_code = 0;
                break;
            }
        }

        // Check if the input color code is within the valid range
        red = atoi(input_color_code[0] - '0');
        green = atoi(input_color_code[2] - '0');
        blue = atoi(input_color_code[4] - '0');
        alpha = atoi(input_color_code[6] - '0');

        if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0 && blue <= 255 && alpha >= 0 && alpha <= 255)
        {
            valid_color_code = 1;
        }
    }

    // Display the results
    if (valid_color_code)
    {
        printf("The input color code is valid.\n");
        printf("Red: %d\n", red);
        printf("Green: %d\n", green);
        printf("Blue: %d\n", blue);
        printf("Alpha: %d\n", alpha);
    }
    else
    {
        printf("The input color code is invalid.\n");
    }

    return 0;
}