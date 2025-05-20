//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void color_code_converter(char **color_code)
{
    char red[10], green[10], blue[10], alpha[10];
    int red_val, green_val, blue_val, alpha_val;

    printf("Enter the red value (0-255): ");
    scanf("%d", &red_val);

    printf("Enter the green value (0-255): ");
    scanf("%d", &green_val);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &blue_val);

    printf("Enter the alpha value (0-255): ");
    scanf("%d", &alpha_val);

    sprintf(red, "%d", red_val);
    sprintf(green, "%d", green_val);
    sprintf(blue, "%d", blue_val);
    sprintf(alpha, "%d", alpha_val);

    *color_code = malloc(20);
    strcpy(*color_code, "rgb(");
    strcat(*color_code, red);
    strcat(*color_code, ", ");
    strcat(*color_code, green);
    strcat(*color_code, ", ");
    strcat(*color_code, blue);
    strcat(*color_code, ", ");
    strcat(*color_code, alpha);
    strcat(*color_code, ")");

    printf("Your color code is: %s\n", *color_code);
}

int main()
{
    char *color_code;

    color_code_converter(&color_code);

    free(color_code);

    return 0;
}