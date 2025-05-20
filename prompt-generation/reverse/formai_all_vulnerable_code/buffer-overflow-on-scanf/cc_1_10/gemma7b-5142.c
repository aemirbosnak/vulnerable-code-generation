//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 10

typedef struct ColorCode
{
    char red;
    char green;
    char blue;
    char alpha;
} ColorCode;

ColorCode convert_color_code(char *color_code)
{
    ColorCode color_code_obj;

    // Validate the color code
    if (strlen(color_code) != MAX_COLOR_CODE)
    {
        printf("Error: Invalid color code.\n");
        exit(1);
    }

    // Convert the color code into a ColorCode structure
    color_code_obj.red = color_code[0];
    color_code_obj.green = color_code[1];
    color_code_obj.blue = color_code[2];
    color_code_obj.alpha = color_code[3];

    return color_code_obj;
}

int main()
{
    char color_code[MAX_COLOR_CODE];

    // Get the color code from the user
    printf("Enter the color code: ");
    scanf("%s", color_code);

    // Convert the color code into a ColorCode structure
    ColorCode color_code_obj = convert_color_code(color_code);

    // Print the color code in the format R, G, B, A
    printf("Color code: R %c, G %c, B %c, A %c\n", color_code_obj.red, color_code_obj.green, color_code_obj.blue, color_code_obj.alpha);

    return 0;
}