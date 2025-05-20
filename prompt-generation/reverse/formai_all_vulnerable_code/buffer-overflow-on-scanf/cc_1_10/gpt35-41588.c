//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBinary(int n, int binary[])
{
    // Size of the binary array to hold the binary digits of decimal number
    int size = 0;
    while (n > 0) {
        binary[size++] = n % 2;
        n /= 2;
    }
    
    // Pad the array with zeroes if necessary
    while (size < 8) {
        binary[size++] = 0;
    }
}

int main()
{
    char file_name[50];
    FILE *fp;
    FILE *fp_out;    
    int binary[8];

    // Ask user for file name
    printf("Enter the name of the file you want to hide text in: ");
    scanf("%s", file_name);

    // Open the file in binary read mode
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file!");
        return -1;
    }

    // Open a new file to write the stegonographed image
    fp_out = fopen("hidden_image.bmp", "wb");

    // Read the BMP header and write it to the new file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    fwrite(header, sizeof(unsigned char), 54, fp_out);

    // Get the image size from the header
    int image_size = *(int*)&header[2];

    // Read and write each pixel to the new file, stegonographing one byte into each pixel
    for (int i = 0; i < image_size; i += 3) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, fp);

        // Get the last bit of each pixel
        int red = pixel[2] & 1;
        int green = pixel[1] & 1;
        int blue = pixel[0] & 1;

        // Get the next byte of text to hide
        int byte = fgetc(stdin);

        // Convert the byte to binary
        decToBinary(byte, binary);

        // Hide each bit of the byte in each pixel
        pixel[2] = (pixel[2] & 0xFE) | binary[0];
        pixel[1] = (pixel[1] & 0xFE) | binary[1];
        pixel[0] = (pixel[0] & 0xFE) | binary[2];
        fwrite(pixel, sizeof(unsigned char), 3, fp_out);

        pixel[2] = (pixel[2] & 0xFE) | binary[3];
        pixel[1] = (pixel[1] & 0xFE) | binary[4];
        pixel[0] = (pixel[0] & 0xFE) | binary[5];
        fwrite(pixel, sizeof(unsigned char), 3, fp_out);

        pixel[2] = (pixel[2] & 0xFE) | binary[6];
        pixel[1] = (pixel[1] & 0xFE) | binary[7];
        pixel[0] = (pixel[0] & 0xFE) | 0;
        fwrite(pixel, sizeof(unsigned char), 3, fp_out);

        if (feof(stdin)) {
            break;
        }
    }

    // If there is still text left, pad with zeroes and print warning
    if (!feof(stdin)) {
        printf("\nWARNING: Not all text could be hidden in the image.\n");
        while (1) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, fp);
            pixel[2] = (pixel[2] & 0xFE);
            pixel[1] = (pixel[1] & 0xFE);
            pixel[0] = (pixel[0] & 0xFE);
            fwrite(pixel, sizeof(unsigned char), 3, fp_out);
            if (feof(fp)) {
                break;
            }
        }
    }

    // Close the files and print success message
    fclose(fp);
    fclose(fp_out);
    printf("\nText hidden successfully in image!\n");

    return 0;
}