//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

int image_to_ascii(char *filename, char *output)
{
    FILE *f;
    int width, height, i, j, k, x, y, c, d, e;
    char *buffer;
    unsigned char *bmp;

    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(f, 18, SEEK_SET);
    fread(&width, 4, 1, f);
    fread(&height, 4, 1, f);

    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        printf("Error: Image is too large\n");
        fclose(f);
        return 1;
    }

    bmp = (unsigned char *) malloc(width * height * 3);
    fread(bmp, width * height * 3, 1, f);
    fclose(f);

    buffer = (char *) malloc(width * height * 6);

    for (i = 0, y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            c = (int) bmp[(y * width + x) * 3];
            d = (int) bmp[(y * width + x) * 3 + 1];
            e = (int) bmp[(y * width + x) * 3 + 2];

            if (c == d && d == e)
            {
                strcat(buffer, " ");
            }
            else if (c == d)
            {
                strcat(buffer, ".");
            }
            else if (c == e)
            {
                strcat(buffer, "-");
            }
            else if (d == e)
            {
                strcat(buffer, "+");
            }
            else
            {
                strcat(buffer, "*");
            }
        }
        strcat(buffer, "\n");
    }

    strcpy(output, buffer);

    free(buffer);
    free(bmp);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc!= 4)
    {
        printf("Usage: %s <input_image> <output_text>\n", argv[0]);
        return 1;
    }

    image_to_ascii(argv[1], argv[2]);

    return 0;
}