//FormAI DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Image Editor!\n\n");
    printf("Please enter the name of the image file you want to edit: ");
    
    char filename[50];
    scanf("%s", filename);
    
    FILE *image = fopen(filename, "rb");
    
    // Check if file exists
    if(image == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }
    
    // Get image dimensions
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Print image info
    printf("\nImage info:\n");
    printf("   File name: %s\n", filename);
    printf("   Width: %d pixels\n", width);
    printf("   Height: %d pixels\n", height);
    
    printf("\nAvailable editing options:\n");
    printf("1. Grayscale\n");
    printf("2. Invert colors\n");
    printf("3. Sepia tone\n");
    printf("4. Blur\n");
    printf("5. Rotate 90 degrees\n");
    printf("Please enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    // Create new file for edited image
    char new_filename[50];
    sprintf(new_filename, "edited_%s", filename);
    FILE *new_image = fopen(new_filename, "wb");
    
    // Write header to new image file
    fwrite(header, sizeof(unsigned char), 54, new_image);
    
    // Apply chosen edit to image
    switch(choice)
    {
        case 1:
        {
            printf("\nApplying grayscale filter...\n");
            unsigned char pixel[3];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    fread(pixel, sizeof(unsigned char), 3, image);
                    unsigned char grayscale = 0.2126 * pixel[2] + 0.7152 * pixel[1] + 0.0722 * pixel[0];
                    fwrite(&grayscale, sizeof(unsigned char), 1, new_image);
                    fwrite(&grayscale, sizeof(unsigned char), 1, new_image);
                    fwrite(&grayscale, sizeof(unsigned char), 1, new_image);
                }
            }
            printf("Grayscale filter applied!\n");
            break;
        }
        
        case 2:
        {
            printf("\nInverting colors...\n");
            unsigned char pixel[3];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    fread(pixel, sizeof(unsigned char), 3, image);
                    pixel[0] = 255 - pixel[0];
                    pixel[1] = 255 - pixel[1];
                    pixel[2] = 255 - pixel[2];
                    fwrite(pixel, sizeof(unsigned char), 3, new_image);
                }
            }
            printf("Colors inverted!\n");
            break;
        }
        
        case 3:
        {
            printf("\nApplying sepia tone...\n");
            unsigned char pixel[3];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    fread(pixel, sizeof(unsigned char), 3, image);
                    unsigned char sepia_red = 0.393 * pixel[2] + 0.769 * pixel[1] + 0.189 * pixel[0];
                    unsigned char sepia_green = 0.349 * pixel[2] + 0.686 * pixel[1] + 0.168 * pixel[0];
                    unsigned char sepia_blue = 0.272 * pixel[2] + 0.534 * pixel[1] + 0.131 * pixel[0];
                    if(sepia_red > 255) sepia_red = 255;
                    if(sepia_green > 255) sepia_green = 255;
                    if(sepia_blue > 255) sepia_blue = 255;
                    fwrite(&sepia_red, sizeof(unsigned char), 1, new_image);
                    fwrite(&sepia_green, sizeof(unsigned char), 1, new_image);
                    fwrite(&sepia_blue, sizeof(unsigned char), 1, new_image);
                }
            }
            printf("Sepia tone applied!\n");
            break;
        }
        
        case 4:
        {
            printf("\nApplying blur...\n");
            unsigned char pixel[3];
            for(int i = 1; i < height - 1; i++)
            {
                for(int j = 1; j < width - 1; j++)
                {
                    // Average color values of surrounding pixels
                    int red = 0, green = 0, blue = 0;
                    for(int k = -1; k <= 1; k++)
                    {
                        for(int l = -1; l <= 1; l++)
                        {
                            fread(pixel, sizeof(unsigned char), 3, image);
                            red += pixel[0];
                            green += pixel[1];
                            blue += pixel[2];
                        }
                        fseek(image, -3 * sizeof(unsigned char), SEEK_CUR); // Move file pointer back
                    }
                    pixel[0] = red / 9;
                    pixel[1] = green / 9;
                    pixel[2] = blue / 9;
                    fwrite(pixel, sizeof(unsigned char), 3, new_image);
                    fseek(image, sizeof(unsigned char), SEEK_CUR); // Move file pointer forward to avoid processing same pixel twice
                }
                fseek(image, sizeof(unsigned char) * 6, SEEK_CUR); // Move file pointer to next row
            }
            printf("Blur applied!\n");
            break;
        }
        
        case 5:
        {
            printf("\nRotating image 90 degrees...\n");
            // Write rotated image dimensions to header
            unsigned char rotated_header[54];
            for(int i = 0; i < 54; i++)
            {
                rotated_header[i] = header[(i + 18) % 54];
            }
            *(int*)&rotated_header[18] = height;
            *(int*)&rotated_header[22] = width;
            fwrite(rotated_header, sizeof(unsigned char), 54, new_image);
            
            unsigned char pixel[3];
            for(int i = 0; i < width; i++)
            {
                for(int j = height - 1; j >= 0; j--)
                {
                    fseek(image, (j * width + i) * sizeof(unsigned char) * 3 + 54, SEEK_SET); // Move file pointer to pixel location
                    fread(pixel, sizeof(unsigned char), 3, image);
                    fwrite(pixel, sizeof(unsigned char), 3, new_image);
                }
            }
            printf("Image rotated 90 degrees!\n");
            break;
        }
        
        default:
            printf("Invalid choice.\n");
    }
    
    fclose(image);
    fclose(new_image);
    
    printf("\nEdited image saved as %s. Thank you for using the C Image Editor!\n", new_filename);
    
    return 0;
}