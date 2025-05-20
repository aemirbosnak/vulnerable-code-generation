//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>

/* Romeo and Juliet Image Editor */

int main()
{
    printf("Welcome to the Romeo and Juliet Image Editor!\n");
    printf("Enter the name of the image file you want to edit: ");
    char filename[100];
    scanf("%s", filename);
    printf("Opening image file %s...\n", filename);
    
    FILE *file_in = fopen(filename, "rb");
    if (file_in == NULL)
    {
        printf("Error: Unable to open %s\n", filename);
        return 1;
    }

    printf("Reading image data...\n");
    
    unsigned char image_data[1000000];
    int num_pixels; // total number of pixels in the image
    int width, height; // width and height of the image
    
    /* Code to read the image data and get width, height, and num_pixels */
    /* For example: */
    fread(&width, sizeof(int), 1, file_in);
    fread(&height, sizeof(int), 1, file_in);
    num_pixels = width * height;
    fread(image_data, sizeof(unsigned char), num_pixels * 3, file_in); // read RGB values for each pixel

    printf("Image dimensions: %d x %d\n", width, height);
    
    /* Code to modify the image data */
    /* For example: */
    for (int i = 0; i < num_pixels * 3; i++)
    {
        if (image_data[i] < 128)
            image_data[i] *= 2;
        else
            image_data[i] = 255 - image_data[i];
    }

    printf("Enter the name of the output file: ");
    char output_filename[100];
    scanf("%s", output_filename);

    printf("Saving image data to %s...\n", output_filename);

    FILE *file_out = fopen(output_filename, "wb");
    if (file_out == NULL)
    {
        printf("Error: Unable to create %s\n", output_filename);
        return 1;
    }

    /* Code to write the modified image data to the output file */
    /* For example: */
    fwrite(&width, sizeof(int), 1, file_out);
    fwrite(&height, sizeof(int), 1, file_out);
    fwrite(image_data, sizeof(unsigned char), num_pixels * 3, file_out);

    printf("Done editing image!\n");

    fclose(file_in);
    fclose(file_out);

    return 0;
}