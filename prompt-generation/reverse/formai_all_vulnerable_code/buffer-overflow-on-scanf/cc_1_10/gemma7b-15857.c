//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int num, char *str)
{
    int i = 0;
    char n[10];
    sprintf(n, "%d", num);
    while (n[i] != '\0')
    {
        str[i] = n[i];
        i++;
    }
    str[i] = '\0';
}

void main()
{
    int r, g, b;
    char img[1024];
    char ascii_img[1024];

    printf("Enter the red, green, and blue values (separated by commas): ");
    scanf("%d, %d, %d", &r, &g, &b);

    // Convert the RGB values to a hexadecimal color code
    char hex_color[7];
    itoa(r, hex_color);
    strcat(hex_color, "-");
    itoa(g, hex_color);
    strcat(hex_color, "-");
    itoa(b, hex_color);
    strcat(hex_color, ")");

    // Get the image file
    printf("Enter the image file name: ");
    scanf("%s", img);

    // Read the image file
    FILE *fp = fopen(img, "r");
    if (fp == NULL)
    {
        printf("Error reading image file.\n");
        return;
    }

    // Convert the image file to ASCII art
    int w, h;
    fscanf(fp, "%d %d", &w, &h);
    fread(ascii_img, w * h, 1, fp);

    // Print the ASCII art
    printf("ASCII art:\n\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            switch (ascii_img[i * w + j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }

    // Close the image file
    fclose(fp);

    // Print the hexadecimal color code
    printf("Hex color code: %s\n", hex_color);
}