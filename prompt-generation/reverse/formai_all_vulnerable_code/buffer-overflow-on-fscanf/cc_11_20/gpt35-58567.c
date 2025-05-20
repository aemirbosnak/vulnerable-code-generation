//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    // Opening the input image 
    FILE *input_image = fopen("input_image.ppm", "rb");
    if(input_image == NULL)
    {
        printf("Error: Unable to open the input image.\n");
        return -1;
    }

    // Reading the image format(should be P6)
    char format[3];
    fscanf(input_image, "%s", format);
    if(strcmp(format, "P6"))
    {
        printf("Error: Unsupported image format\n");
        return -1;
    }

    // Skip over image comments
    char comment = getc(input_image);
    while(comment == '#')
    {
        while(getc(input_image) != '\n');
        comment = getc(input_image);
    }

    // Reading the image dimensions
    int width, height;
    ungetc(comment, input_image);
    fscanf(input_image, "%d%d", &width, &height);

    // Reading the maximum color value (should be 255)
    int max_color_val;
    fscanf(input_image, "%d", &max_color_val);
    if(max_color_val > 255)
    {
        printf("Error: Unsupported maximum color value\n");
        return -1;
    }

    // Creating an output image file
    FILE *output_image = fopen("output_image.ppm", "wb");
    fprintf(output_image, "P6\n%d %d\n%d\n", width, height, max_color_val);

    // Reading and processing the image data
    unsigned char *image_data = malloc(3 * width * height);
    fread(image_data, 1, 3 * width * height, input_image);

    // To flip the image horizontally,
    // we need to swap the values of each row separately
    for(int h = 0; h < height; h++)
    {
        int row_start = h * 3 * width;
        int row_end = row_start + 3 * (width - 1);
        for(int i = row_start; i < row_end; i += 3, row_end -= 3)
        {
            unsigned char tmp_r = image_data[i];
            unsigned char tmp_g = image_data[i+1];
            unsigned char tmp_b = image_data[i+2];

            image_data[i] = image_data[row_end];
            image_data[i+1] = image_data[row_end+1];
            image_data[i+2] = image_data[row_end+2];

            image_data[row_end] = tmp_r;
            image_data[row_end+1] = tmp_g;
            image_data[row_end+2] = tmp_b;
        }
    }

    // To increase the brightness, we just add a constant value to each color value
    int brightness = 50;
    for(int i = 0; i < 3 * width * height; i++)
    {
        int val = (int)image_data[i] + brightness;
        image_data[i] = val > max_color_val ? max_color_val : (unsigned char)val;
    }

    // To change the contrast, we first calculate the average value
    // of each color channel and then multiply each value by a
    // scaling factor that depends on the desired contrast level
    float contrast = 1.5;
    float r_sum = 0, g_sum = 0, b_sum = 0;
    for(int i = 0; i < 3 * width * height; i += 3)
    {
        r_sum += image_data[i];
        g_sum += image_data[i+1];
        b_sum += image_data[i+2];
    }
    float r_avg = r_sum / (width * height);
    float g_avg = g_sum / (width * height);
    float b_avg = b_sum / (width * height);

    float r_scale = contrast * max_color_val / (max_color_val - 2.0 * r_avg);
    float g_scale = contrast * max_color_val / (max_color_val - 2.0 * g_avg);
    float b_scale = contrast * max_color_val / (max_color_val - 2.0 * b_avg);

    for(int i = 0; i < 3 * width * height; i += 3)
    {
        image_data[i] = r_scale * ((float)image_data[i] - r_avg);
        image_data[i+1] = g_scale * ((float)image_data[i+1] - g_avg);
        image_data[i+2] = b_scale * ((float)image_data[i+2] - b_avg);
    }

    // Writing the processed image data to the output image file
    fwrite(image_data, 1, 3 * width * height, output_image);

    // Closing the input and output files
    fclose(input_image);
    fclose(output_image);

    // Freeing the allocated memory
    free(image_data);

    printf("Image processing successful!\n");

    return 0;
}