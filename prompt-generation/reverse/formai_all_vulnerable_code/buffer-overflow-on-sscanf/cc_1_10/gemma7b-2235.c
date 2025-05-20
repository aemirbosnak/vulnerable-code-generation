//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 255

void convert_color_code(char **code)
{
    int r, g, b, a;
    char temp[MAX_COLOR_CODE];

    // Extract the RGB values from the code
    sscanf(*code, "%d, %d, %d, %d", &r, &g, &b, &a);

    // Check if the values are valid
    if (r < 0 || r > MAX_COLOR_CODE)
    {
        return;
    }
    if (g < 0 || g > MAX_COLOR_CODE)
    {
        return;
    }
    if (b < 0 || b > MAX_COLOR_CODE)
    {
        return;
    }
    if (a < 0 || a > MAX_COLOR_CODE)
    {
        return;
    }

    // Create a temporary string with the RGB values
    sprintf(temp, "RGB (%d, %d, %d)", r, g, b);

    // Replace the old code with the new temporary code
    free(*code);
    *code = strdup(temp);
}

int main()
{
    char *code = NULL;

    // Get the color code from the user
    printf("Enter a color code: ");
    getline(stdin, code, MAX_COLOR_CODE);

    // Convert the color code
    convert_color_code(&code);

    // Print the converted color code
    printf("Converted color code: %s\n", code);

    // Free the memory allocated for the code
    free(code);

    return 0;
}