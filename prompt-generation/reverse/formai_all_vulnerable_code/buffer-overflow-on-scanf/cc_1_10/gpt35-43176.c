//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(FILE *image_file, FILE *secret_file, FILE *output_file);
void decode(FILE *image_file, FILE *output_file);

int main(int argc, char *argv[])
{
    // Check if user has entered valid arguments
    if (argc < 3)
    {
        printf("Usage: %s <image_file> <secret_file>\n", argv[0]);
        return 1;
    }

    char operation = '0';

    // Prompt user to either hide or unhide data
    while (operation != 'e' && operation != 'd')
    {
        printf("Enter 'e' to hide data or 'd' to unhide data: ");
        scanf(" %c", &operation);

        if (operation != 'e' && operation != 'd')
        {
            printf("Invalid option, please try again\n");
        }
    }

    FILE *image_file = fopen(argv[1], "rb");
    FILE *output_file = fopen("output.bmp", "wb");

    if (image_file == NULL || output_file == NULL)
    {
        printf("Error opening file\n");
        fclose(image_file);
        fclose(output_file);
        return 1;
    }

    if (operation == 'e')
    {
        FILE *secret_file = fopen(argv[2], "rb");

        if (secret_file == NULL)
        {
            printf("Error opening file\n");
            fclose(secret_file);
            fclose(image_file);
            fclose(output_file);
            return 1;
        }

        printf("Encoding...\n");
        encode(image_file, secret_file, output_file);
        printf("Data hidden successfully!\n");

        fclose(secret_file);
    }
    else if (operation == 'd')
    {
        printf("Decoding...\n");
        decode(image_file, output_file);
        printf("Data retrieved successfully!\n");
    }

    fclose(image_file);
    fclose(output_file);

    return 0;
}

void encode(FILE *image_file, FILE *secret_file, FILE *output_file)
{
    unsigned char bmp_header[54];
    unsigned char secret_buffer[99999];

    // Extract BMP header from image file
    fread(bmp_header, sizeof(unsigned char), 54, image_file);

    // Write BMP header to output file
    fwrite(bmp_header, sizeof(unsigned char), 54, output_file);

    // Copy contents of secret file to buffer
    fread(secret_buffer, sizeof(unsigned char), 99999, secret_file);

    int buffer_position = 0;
    int secret_size = strlen(secret_buffer);

    // Iterate through the pixels of image file and modify LSB of each color channel to hide secret data
    for (int i = 54; i < 1228804 && buffer_position < secret_size; i += 3)
    {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image_file);

        // Modify LSB of red channel
        pixel[2] &= 0xfe; // 0xfe = 11111110 - sets the least significant bit to zero
        pixel[2] |= (secret_buffer[buffer_position] & 0x01); // Write the bit from the secret data to the least significant bit of the red channel

        // Modify LSB of green channel
        pixel[1] &= 0xfe;
        pixel[1] |= ((secret_buffer[buffer_position] >> 1) & 0x01);

        // Modify LSB of blue channel
        pixel[0] &= 0xfe;
        pixel[0] |= ((secret_buffer[buffer_position] >> 2) & 0x01);

        // Write modified pixel to output file
        fwrite(pixel, sizeof(unsigned char), 3, output_file);

        buffer_position++;
    }

    // Copy remaining pixels from image file to output file
    unsigned char buffer[4096];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), 4096, image_file)) > 0)
    {
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
    }
}

void decode(FILE *image_file, FILE *output_file)
{
    unsigned char bmp_header[54];
    unsigned char secret_buffer[99999];

    // Extract BMP header from image file
    fread(bmp_header, sizeof(unsigned char), 54, image_file);

    int buffer_position = 0;
    int secret_size = 0;

    // Iterate through the pixels of image file and retrieve LSB of each color channel to retrieve hidden data
    for (int i = 54; i < 1228804; i += 3)
    {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image_file);

        // Retrieve LSB of red channel
        secret_buffer[buffer_position] |= (pixel[2] & 0x01);

        // Retrieve LSB of green channel
        secret_buffer[buffer_position] |= ((pixel[1] & 0x01) << 1);

        // Retrieve LSB of blue channel
        secret_buffer[buffer_position] |= ((pixel[0] & 0x01) << 2);

        buffer_position++;

        if (buffer_position >= 99999)
        {
            printf("Error: secret file size exceeds maximum limit of 99999 bytes\n");
            return;
        }

        // Check if end of secret message has been reached
        if (pixel[0] == 255 && pixel[1] == 255 && pixel[2] == 255)
        {
            break;
        }
    }

    secret_size = strlen(secret_buffer);
    secret_buffer[secret_size - 1] = '\0';

    // Write retrieved data to output file
    fwrite(secret_buffer, sizeof(unsigned char), secret_size, output_file);
}