//FormAI DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hex_to_ascii(char c)
{
    char hex_value[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char ascii_value[] = {'10', '11', '12', '13', '14', '15'};
    int i;

    for (i = 0; i < 6; i++)
    {
        if (c == hex_value[i])
        {
            return ascii_value[i];
        }
    }

    return c;
}

char ascii_to_hex(char c)
{
    char ascii_value[] = {'10', '11', '12', '13', '14', '15'};
    char hex_value[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int i;

    for (i = 0; i < 6; i++)
    {
        if (c == ascii_value[i])
        {
            return hex_value[i];
        }
    }

    return c;
}

void hex_to_rgb(char *hex, int *r, int *g, int *b)
{
    char r_hex[3], g_hex[3], b_hex[3];
    strncpy(r_hex, hex, 2);
    strncpy(g_hex, hex + 2, 2);
    strncpy(b_hex, hex + 4, 2);
    r_hex[2] = '\0';
    g_hex[2] = '\0';
    b_hex[2] = '\0';
    *r = strtol(r_hex, NULL, 16);
    *g = strtol(g_hex, NULL, 16);
    *b = strtol(b_hex, NULL, 16);
}

void rgb_to_hex(int r, int g, int b, char *hex)
{
    char r_hex[3], g_hex[3], b_hex[3];
    sprintf(r_hex, "%02X", r);
    sprintf(g_hex, "%02X", g);
    sprintf(b_hex, "%02X", b);
    sprintf(hex, "%s%s%s", r_hex, g_hex, b_hex);
}

void convert_color(char *color, char *output_format)
{
    char hex[7];
    int r, g, b;

    if (output_format == "hex")
    {
        hex_to_rgb(color, &r, &g, &b);
        rgb_to_hex(r, g, b, hex);
        printf("The equivalent Hex code is #%s\n", hex);
    }
    else if (output_format == "RGB")
    {
        hex_to_rgb(color, &r, &g, &b);
        printf("The equivalent RGB value is (%d, %d, %d)\n", r, g, b);
    }
    else if (output_format == "CMYK")
    {
        hex_to_rgb(color, &r, &g, &b);
        printf("The equivalent CMYK value is: %d %d %d %d\n", (255 - r) * 100 / 255, (255 - g) * 100 / 255, (255 - b) * 100 / 255, 0);
    }
    else
    {
        printf("Invalid format specified.\n");
    }
}

int main()
{
    char input_format[10], output_format[10], color[7], input_string[50];
    int i;

    printf("Enter the color code (with or without #): ");
    fgets(input_string, 50, stdin);
    sscanf(input_string, "%s", color);

    if (strlen(color) == 6)
    {
        printf("Valid color code entered!\n");
    }
    else
    {
        printf("Invalid color code entered, terminating program.\n");
        return 0;
    }

    printf("Enter the input format (RGB, hex): ");
    fgets(input_format, 5, stdin);

    for (i = 0; i < strlen(input_format); i++)
    {
        input_format[i] = toupper(input_format[i]);
    }

    printf("Enter the output format (RGB, hex, CMYK): ");
    fgets(output_format, 5, stdin);

    for (i = 0; i < strlen(output_format); i++)
    {
        output_format[i] = toupper(output_format[i]);
    }

    printf("Input color code: #%s in %s format.\n", color, input_format);
    convert_color(color, output_format);

    return 0;
}