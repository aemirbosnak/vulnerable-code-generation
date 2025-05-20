//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

// Introduction

printf("Greetings, Watson. Today we shall delve into the fascinating world of color code conversion.\n");
printf("As you are well aware, colors can be represented in different ways, including RGB, HEX, and CMYK.\n");
printf("Our objective is to create a program that can convert color codes from one format to another.\n");
printf("Let us begin our investigation.\n");

// Get user input

char input_format[4];
char output_format[4];
int red, green, blue, cyan, magenta, yellow, key;

printf("Please enter the format of the input color code (RGB, HEX, CMYK): ");
scanf("%s", input_format);

// Analyze input format

if (strcmp(input_format, "RGB") == 0) {
    printf("Please enter the value of red (0-255): ");
    scanf("%d", &red);
    printf("Please enter the value of green (0-255): ");
    scanf("%d", &green);
    printf("Please enter the value of blue (0-255): ");
    scanf("%d", &blue);
} else if (strcmp(input_format, "HEX") == 0) {
    printf("Please enter the value of the color code in HEX format: ");
    char hex[7];
    scanf("%s", hex);
    sscanf(hex, "%02x%02x%02x", &red, &green, &blue);
} else if (strcmp(input_format, "CMYK") == 0) {
    printf("Please enter the value of cyan (0-100): ");
    scanf("%d", &cyan);
    printf("Please enter the value of magenta (0-100): ");
    scanf("%d", &magenta);
    printf("Please enter the value of yellow (0-100): ");
    scanf("%d", &yellow);
    printf("Please enter the value of key (0-100): ");
    scanf("%d", &key);
}

// Get desired output format

printf("Please enter the format of the output color code (RGB, HEX, CMYK): ");
scanf("%s", output_format);

// Analyze output format

if (strcmp(output_format, "RGB") == 0) {
    if (strcmp(input_format, "RGB") == 0) {
        printf("The input color code is already in RGB format.\n");
    } else if (strcmp(input_format, "HEX") == 0) {
        printf("The RGB representation of the input color code is (%d, %d, %d).\n", red, green, blue);
    } else if (strcmp(input_format, "CMYK") == 0) {
        int r = 255 * (1 - (cyan / 100.0)) * (1 - (key / 100.0));
        int g = 255 * (1 - (magenta / 100.0)) * (1 - (key / 100.0));
        int b = 255 * (1 - (yellow / 100.0)) * (1 - (key / 100.0));
        printf("The RGB representation of the input color code is (%d, %d, %d).\n", r, g, b);
    }
} else if (strcmp(output_format, "HEX") == 0) {
    if (strcmp(input_format, "RGB") == 0) {
        printf("The HEX representation of the input color code is #%02x%02x%02x.\n", red, green, blue);
    } else if (strcmp(input_format, "HEX") == 0) {
        printf("The input color code is already in HEX format.\n");
    } else if (strcmp(input_format, "CMYK") == 0) {
        int r = 255 * (1 - (cyan / 100.0)) * (1 - (key / 100.0));
        int g = 255 * (1 - (magenta / 100.0)) * (1 - (key / 100.0));
        int b = 255 * (1 - (yellow / 100.0)) * (1 - (key / 100.0));
        printf("The HEX representation of the input color code is #%02x%02x%02x.\n", r, g, b);
    }
} else if (strcmp(output_format, "CMYK") == 0) {
    if (strcmp(input_format, "RGB") == 0) {
        float c = 1 - (red / 255.0);
        float m = 1 - (green / 255.0);
        float y = 1 - (blue / 255.0);
        float k = fmin(c, fmin(m, y));
        if (k == 1) {
            c = m = y = 0;
        } else {
            c = (c - k) / (1 - k);
            m = (m - k) / (1 - k);
            y = (y - k) / (1 - k);
        }
        printf("The CMYK representation of the input color code is (%d%%, %d%%, %d%%, %d%%).\n", (int)(c * 100), (int)(m * 100), (int)(y * 100), (int)(k * 100));
    } else if (strcmp(input_format, "HEX") == 0) {
        int r = red;
        int g = green;
        int b = blue;
        float c = 1 - (r / 255.0);
        float m = 1 - (g / 255.0);
        float y = 1 - (b / 255.0);
        float k = fmin(c, fmin(m, y));
        if (k == 1) {
            c = m = y = 0;
        } else {
            c = (c - k) / (1 - k);
            m = (m - k) / (1 - k);
            y = (y - k) / (1 - k);
        }
        printf("The CMYK representation of the input color code is (%d%%, %d%%, %d%%, %d%%).\n", (int)(c * 100), (int)(m * 100), (int)(y * 100), (int)(k * 100));
    } else if (strcmp(input_format, "CMYK") == 0) {
        printf("The input color code is already in CMYK format.\n");
    }
}

printf("Thank you for using our color code converter, Watson. The case is now closed.\n");

return 0;

}