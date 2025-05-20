//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ASCII_CHARS 70
#define MAX_IMAGE_WIDTH 800
#define MAX_IMAGE_HEIGHT 800
#define MAX_LINE_LENGTH 1024

// Configurable options
char ascii_chars[MAX_ASCII_CHARS+1] = {'@', '#', 'S', '%', '*', '+', '-', ':', '.', ' '};
int num_chars = 10; // number of ascii characters used
int char_width = 6; // width of each ascii character in pixels
int char_height = 9; // height of each ascii character in pixels
int contrast_adjustment = 0; // adjust ascii character contrast, -255 to 255
int gamma_correction = 100; // adjust gamma correction, 1 to 100

int image_width, image_height;
unsigned char image[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];

void load_image(char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Error: failed to open image file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp);

    int offset = 0;
    while(line[0] == '#')
    {
        offset += strlen(line);
        fgets(line, MAX_LINE_LENGTH, fp);
    }

    sscanf(line, "%d %d", &image_width, &image_height);
    offset += strlen(line);

    fgets(line, MAX_LINE_LENGTH, fp);
    offset += strlen(line);

    int num_bytes = image_width * image_height;
    for(int i=0; i<num_bytes; i++)
    {
        fread(&image[i/image_width][i%image_width], 1, 1, fp);
    }

    fclose(fp);
}

void adjust_contrast()
{
    for(int y=0; y<image_height; y++)
    {
        for(int x=0; x<image_width; x++)
        {
            int intensity = (int)image[y][x];
            intensity += contrast_adjustment;
            if(intensity > 255) intensity = 255;
            if(intensity < 0) intensity = 0;
            image[y][x] = (unsigned char)intensity;
        }
    }
}

void adjust_gamma()
{
    float gamma = (float)gamma_correction / 100.0f;
    unsigned char gamma_table[256];
    for(int i=0; i<256; i++)
    {
        gamma_table[i] = (unsigned char)(pow((float)i / 255.0f, gamma) * 255.0f);
    }

    for(int y=0; y<image_height; y++)
    {
        for(int x=0; x<image_width; x++)
        {
            image[y][x] = gamma_table[image[y][x]];
        }
    }
}

char get_ascii_char(int intensity)
{
    int char_int = (intensity * num_chars) / 256;
    if(char_int >= num_chars) char_int = num_chars - 1;
    return ascii_chars[char_int];
}

void convert_image_to_ascii(char* output_filename)
{
    FILE* fp = fopen(output_filename, "w");
    if(fp == NULL)
    {
        printf("Error: failed to open output file.\n");
        exit(1);
    }

    int num_chars_x = image_width / char_width;
    int num_chars_y = image_height / char_height;

    for(int y=0; y<num_chars_y; y++)
    {
        for(int x=0; x<num_chars_x; x++)
        {
            int avg_intensity = 0;
            for(int i=y*char_height; i<(y+1)*char_height; i++)
            {
                for(int j=x*char_width; j<(x+1)*char_width; j++)
                {
                    avg_intensity += (int)image[i][j];
                }
            }
            avg_intensity /= (char_width * char_height);

            char ascii_char = get_ascii_char(avg_intensity);
            fputc(ascii_char, fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: ascii_converter <filename>\n");
        return 0;
    }

    load_image(argv[1]);

    adjust_contrast();

    adjust_gamma();

    convert_image_to_ascii("output.txt");

    return 0;
}