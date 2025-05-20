//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    FILE *fptr;
    char filename[20];
    unsigned char *image;

    // Read image from file
    printf("Enter the filename: ");
    scanf("%s", filename);
    fptr = fopen(filename, "rb");
    if (fptr == NULL)
    {
        printf("Error: Cannot open file\n");
        exit(0);
    }
    fscanf(fptr, "%*s %d %d %*d", &width, &height);
    image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, fptr);
    fclose(fptr);

    // Flip image horizontally
    unsigned char *temp = (unsigned char*)malloc(width * sizeof(unsigned char));
    int i, j, k;
    for (i = 0; i < height; i++)
    {
        k = i * width;
        for (j = 0; j < width/2; j++)
        {
            temp[j] = image[k+j];
            image[k+j] = image[k+width-1-j];
            image[k+width-1-j] = temp[j];
        }
    }
    free(temp);

    // Change brightness and contrast of image
    int brightness = 50;
    float contrast = 1.2;
    for (i = 0; i < height; i++)
    {
        k = i * width;
        for (j = 0; j < width; j++)
        {
            int val = (int)image[k+j] + brightness;
            if (val < 0)
                val = 0;
            if (val > 255)
                val = 255;
            image[k+j] = (unsigned char)val;
            val = (int)(val-128) * contrast + 128;
            if (val < 0)
                val = 0;
            if (val > 255)
                val = 255;
            image[k+j] = (unsigned char)val;
        }
    }

    // Write image to file
    char output_filename[20];
    printf("Enter the output filename: ");
    scanf("%s", output_filename);
    fptr = fopen(output_filename, "w");
    if (fptr == NULL)
    {
        printf("Error: Cannot create file\n");
        exit(0);
    }
    fprintf(fptr, "P5 %d %d 255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, fptr);
    fclose(fptr);

    free(image);
    printf("Image processing successful. Output file created!\n");
    return 0;
}