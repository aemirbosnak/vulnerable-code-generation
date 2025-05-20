//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
/* Simple Image Processing in C
   by Ken Thompson circa 2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int main(int argc, char** argv)
{
    byte* img;
    char* fname = argv[1];
    int w, h, c;
    int row, col;
    int i, j, nw, nh;
    int bright, cont;

    if (argc < 2)
        return EXIT_FAILURE;

    FILE* fp = fopen(fname, "rb");
    if (!fp)
        return EXIT_FAILURE;

    fread(&w, sizeof(w), 1, fp);
    fread(&h, sizeof(h), 1, fp);
    fread(&c, sizeof(c), 1, fp);

    img = malloc(w * h * c);
    if (!img)
        return EXIT_FAILURE;

    fread(img, w * h * c, 1, fp);
    fclose(fp);

    bright = strtol(argv[2], NULL, 10);
    cont = strtol(argv[3], NULL, 10);

    // Apply brightness and contrast
    for (i = 0; i < w * h * c; i++)
    {
        img[i] = (img[i] + bright) * cont / 100;
    }

    // Flip the image horizontally
    nw = w;
    nh = h;
    row = h / 2;
    col = w / 2;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            byte tmp = img[i * nw + j * c];
            img[i * nw + j * c] = img[(nh - i - 1) * nw + (nw - j - 1) * c];
            img[(nh - i - 1) * nw + (nw - j - 1) * c] = tmp;
        }
    }

    // Write the modified image to a new file
    fp = fopen("modified.bmp", "wb");
    fwrite(&w, sizeof(w), 1, fp);
    fwrite(&h, sizeof(h), 1, fp);
    fwrite(&c, sizeof(c), 1, fp);
    fwrite(img, w * h * c, 1, fp);
    fclose(fp);

    free(img);
    return EXIT_SUCCESS;
}