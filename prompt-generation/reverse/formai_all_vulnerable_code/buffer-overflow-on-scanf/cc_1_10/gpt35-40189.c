//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXELS 512

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}RGB;

RGB image[MAX_PIXELS][MAX_PIXELS]; // 2D array of RGB pixels

// function to flip the image horizontally
void hflip_image(int width, int height)
{
    RGB temp;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// function to adjust brightness of image
void adjust_brightness(int width, int height, int brightness_value)
{
    int new_value;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            new_value = image[i][j].r + brightness_value;
            image[i][j].r = fmax(0, fmin(255, new_value));

            new_value = image[i][j].g + brightness_value;
            image[i][j].g = fmax(0, fmin(255, new_value));

            new_value = image[i][j].b + brightness_value;
            image[i][j].b = fmax(0, fmin(255, new_value));
        }
    }
}

// function to adjust contrast of image
void adjust_contrast(int width, int height, float contrast_value)
{
    float factor = (259 * (contrast_value + 255)) / (255 * (259 - contrast_value));

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].r = fmax(0, fmin(255, (int)(factor * (image[i][j].r - 128) + 128)));
            image[i][j].g = fmax(0, fmin(255, (int)(factor * (image[i][j].g - 128) + 128)));
            image[i][j].b = fmax(0, fmin(255, (int)(factor * (image[i][j].b - 128) + 128)));
        }
    }
}

int main()
{
    FILE *in_file;
    FILE *out_file;
    char input_file[50];
    char output_file[50];
    int width, height;
    int brightness_value;
    float contrast_value;

    // ask user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // open input file for reading
    in_file = fopen(input_file, "rb");
    if(in_file == NULL)
    {
        printf("Error opening input file!");
        return -1;
    }

    // read P6 header (RGB binary image format)
    char header[3];
    fgets(header, sizeof(header), in_file);
    if(strcmp(header, "P6\n") != 0)
    {
        printf("Invalid input file format!");
        fclose(in_file);
        return -1;
    }

    // read image width and height
    fscanf(in_file, "%d %d\n", &width, &height);

    // read maximum pixel value (255)
    int max_pixel_value;
    fscanf(in_file, "%d\n", &max_pixel_value);

    // read RGB pixel values and store in array
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            fread(&image[i][j], sizeof(RGB), 1, in_file);
        }
    }

    // close input file
    fclose(in_file);

    // ask user for task to perform
    int task;
    printf("\nSelect task to perform:\n");
    printf("1) Flip image horizontally\n");
    printf("2) Adjust brightness\n");
    printf("3) Adjust contrast\n");
    printf("Enter task number: ");
    scanf("%d", &task);

    switch(task)
    {
        case 1:
            // flip image horizontally
            hflip_image(width, height);
            strcpy(output_file, "hflipped.ppm");
            break;

        case 2:
            // adjust brightness
            printf("Enter brightness value (-255 to 255): ");
            scanf("%d", &brightness_value);
            adjust_brightness(width, height, brightness_value);
            sprintf(output_file, "bright%d.ppm", brightness_value);
            break;

        case 3:
            // adjust contrast
            printf("Enter contrast value (0.1 to 10.0): ");
            scanf("%f", &contrast_value);
            adjust_contrast(width, height, contrast_value);
            sprintf(output_file, "cont%.1f.ppm", contrast_value);
            break;

        default:
            printf("Invalid task number!");
            return -1;
    }

    // open output file for writing
    out_file = fopen(output_file, "wb");
    if(out_file == NULL)
    {
        printf("Error opening output file!");
        return -1;
    }

    // write P6 header to output file
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_pixel_value);

    // write RGB pixel values to output file
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            fwrite(&image[i][j], sizeof(RGB), 1, out_file);
        }
    }

    // close output file
    fclose(out_file);

    printf("\nTask completed successfully! Output file: %s", output_file);

    return 0;
}