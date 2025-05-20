//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to retrieve a pixel value from an image
int get_pixel(unsigned char *img_data, int width, int height, int x, int y)
{
    int index = (x + y * width) * 3;
    
    return (img_data[index] + img_data[index + 1] + img_data[index + 2]) / 3;
}

// Function to set a pixel value in an image
void set_pixel(unsigned char *img_data, int width, int height, int x, int y, int value)
{
    int index = (x + y * width) * 3;
    
    img_data[index]     = value;
    img_data[index + 1] = value;
    img_data[index + 2] = value;
}

// Function to add a digital watermark to an image
void add_watermark(unsigned char *img_data, int width, int height, char *watermark)
{
    int watermark_length = strlen(watermark), watermark_index = 0;
    int x, y, pixel_value, bit_value, count = 0;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            pixel_value = get_pixel(img_data, width, height, x, y);
            bit_value   = (watermark_index < watermark_length ? watermark[watermark_index++] : (rand() % 2));
            
            if (bit_value)
            {
                if (pixel_value < 128)
                    pixel_value += 128;
                else
                    pixel_value -= 128;
            }
            
            set_pixel(img_data, width, height, x, y, pixel_value);
            
            if (++count == watermark_length + 8) // 8 bits for marker
                return;
        }
    }
}

int main()
{
    char watermark[] = "This is a digital watermark!";
    
    // Load the image
    FILE *image_file = fopen("image.bmp", "rb");
    if (!image_file)
    {
        printf("Failed to open image file!\n");
        return 1;
    }
    
    // Read the image width and height
    fseek(image_file, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, image_file);
    fread(&height, 4, 1, image_file);
    
    // Skip over the image header
    fseek(image_file, 54, SEEK_SET);
    
    // Allocate memory for the image data
    unsigned char *img_data = malloc(width * height * 3);
    
    // Read in the image data
    fread(img_data, width * height * 3, 1, image_file);
    fclose(image_file);
    
    // Add the digital watermark to the image data
    add_watermark(img_data, width, height, watermark);
    
    // Save the watermarked image
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (!watermarked_image_file)
    {
        printf("Failed to create watermarked image file!\n");
        return 1;
    }
    
    // Write the image header
    unsigned char header[] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    width *= 3;
    fwrite(header, 1, 30, watermarked_image_file);
    fwrite(&width, 4, 1, watermarked_image_file);
    fwrite(&height, 4, 1, watermarked_image_file);
    fwrite(header + 34, 1, 20, watermarked_image_file);
    
    // Write the watermarked image data
    fwrite(img_data, width * height * 3, 1, watermarked_image_file);
    fclose(watermarked_image_file);
    
    printf("Digital watermark added to image successfully!\n");
    
    return 0;
}