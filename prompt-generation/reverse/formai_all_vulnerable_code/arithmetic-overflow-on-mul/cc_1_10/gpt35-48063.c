//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to flip the image
void flipImage(unsigned char *img, int width, int height, int bytesPerPixel)
{
    unsigned char tmp;
    int row, col, bp;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width / 2; col++)
        {
            for (bp = 0; bp < bytesPerPixel; bp++)
            {
                tmp = img[row * width * bytesPerPixel + col * bytesPerPixel + bp];
                img[row * width * bytesPerPixel + col * bytesPerPixel + bp] = img[row * width * bytesPerPixel + (width - col - 1) * bytesPerPixel + bp];
                img[row * width * bytesPerPixel + (width - col - 1) * bytesPerPixel + bp] = tmp;
            }
        }
    }
}

//function to change brightness and contrast of the image
void changeBrightnessContrast(unsigned char *img, int width, int height, int bytesPerPixel, int brightness, float contrast)
{
    unsigned char *p;
    int row, col, bp;
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            p = &img[row * width * bytesPerPixel + col * bytesPerPixel];
            for (bp = 0; bp < bytesPerPixel; bp++)
            {
                *p = (unsigned char)(factor * (*p - 128.0f) + 128.0f + brightness);
                p++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename;
    int width, height, bytesPerPixel;
    unsigned char *img;

    if (argc < 3)
    {
        printf("Usage: %s <input_image_file> <output_image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    else
    {
        filename = argv[1];
    }

    //open input file
    if (!(fp = fopen(filename, "rb")))
    {
        printf("Error: could not open image file %s\n", filename);
        return EXIT_FAILURE;
    }

    //read the header
    char header[54];
    fread(header, sizeof(char), 54, fp);
    width = *(int *)&header[18];
    height = *(int *)&header[22];
    bytesPerPixel = *(int *)&header[28] / 8;

    //allocate memory for image data
    img = (unsigned char *)malloc(width * height * bytesPerPixel);

    //read the image data
    fread(img, sizeof(unsigned char), width * height * bytesPerPixel, fp);

    //close the file
    fclose(fp);

    //flip the image horizontally
    flipImage(img, width, height, bytesPerPixel);

    //increase brightness and contrast
    changeBrightnessContrast(img, width, height, bytesPerPixel, 50, 1.5f);

    //open output file
    if (!(fp = fopen(argv[2], "wb")))
    {
        printf("Error: could not create output file\n");
        return EXIT_FAILURE;
    }

    //write the header
    fwrite(header, sizeof(unsigned char), 54, fp);

    //write the image data
    fwrite(img, sizeof(unsigned char), width * height * bytesPerPixel, fp);

    //close the file
    fclose(fp);

    //free the memory allocated for the image data
    free(img);

    return EXIT_SUCCESS;
}