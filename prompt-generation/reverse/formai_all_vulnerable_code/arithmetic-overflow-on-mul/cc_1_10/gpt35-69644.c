//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

void grayscale(unsigned char* img, int width, int height);
void toASCII(unsigned char* img, int width, int height, char* out);
void writeToFile(const char* filename, char* out);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Error: Invalid arguments\n");
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return -1;
    }

    const char* infile = argv[1];
    const char* outfile = argv[2];

    FILE* f = fopen(infile, "rb");
    if (f == NULL)
    {
        printf("Error: Could not open file %s\n", infile);
        return -1;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int size = 3 * width * height;
    unsigned char* img = (unsigned char*)malloc(size);

    fread(img, sizeof(unsigned char), size, f);
    fclose(f);

    grayscale(img, width, height);

    char* out = (char*)malloc(width * height + 1);
    toASCII(img, width, height, out);
    writeToFile(outfile, out);

    free(img);
    free(out);

    return 0;
}

void grayscale(unsigned char* img, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pos = (i * width + j) * 3;
            unsigned char r = img[pos];
            unsigned char g = img[pos + 1];
            unsigned char b = img[pos + 2];

            unsigned char gray = (0.3 * r) + (0.59 * g) + (0.11 * b);

            img[pos] = img[pos + 1] = img[pos + 2] = gray;
        }
    }
}

void toASCII(unsigned char* img, int width, int height, char* out)
{
    char ascii_chars[] = " .:-=+*#%@";
    int char_len = strlen(ascii_chars);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pos = i * width + j;
            int index = (int)round((img[pos] / 255.0) * (char_len - 1));

            out[pos] = ascii_chars[index];
        }
    }

    out[width * height] = '\0';
}

void writeToFile(const char* filename, char* out)
{
    FILE* f = fopen(filename, "w");
    fprintf(f, "%s\n", out);
    fclose(f);
}