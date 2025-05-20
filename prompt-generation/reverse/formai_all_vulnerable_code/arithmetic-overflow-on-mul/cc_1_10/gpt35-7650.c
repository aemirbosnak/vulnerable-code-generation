//FormAI DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char original_image[] = "original_image.bmp"; // Path of the original image
    char output_image[] = "modified_image.bmp"; // Path of the modified image
    char secret_message[] = "Secret message hidden in the image"; // Secret message to be hidden in the image
    FILE *fp_original_image, *fp_output_image;

    // Open the original image
    if((fp_original_image = fopen(original_image, "rb")) == NULL)
    {
        printf("Unable to open the original image file!\n");
        exit(1);
    }

    // Open the output image
    if((fp_output_image = fopen(output_image, "wb")) == NULL)
    {
        printf("Unable to open the output image file!\n");
        exit(1);
    }

    // Copy the header of the original image to the output image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_original_image);
    fwrite(header, sizeof(unsigned char), 54, fp_output_image);

    // Read the pixel values of the original image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = 3 * width * height;
    unsigned char pixels[size];
    fread(pixels, sizeof(unsigned char), size, fp_original_image);

    // Hide the secret message in the pixel values
    int message_length = strlen(secret_message);
    int pixel_index = 0;
    for(int i = 0; i < message_length; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((secret_message[i] >> (7 - j)) & 1)
                pixels[pixel_index] |= 1;
            else
                pixels[pixel_index] &= 0xFE;
            pixel_index++;
        }
    }

    // Write the modified pixel values to the output image
    fwrite(pixels, sizeof(unsigned char), size, fp_output_image);

    printf("Secret message hidden in the image successfully!\n");

    // Close the image files
    fclose(fp_original_image);
    fclose(fp_output_image);

    return 0;
}