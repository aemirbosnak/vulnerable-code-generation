//FormAI DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_MESSAGE_SIZE 256
#define PIXEL_SIZE 3

/*
  Steganography is the art and science of hiding a message inside an image.
  In this example, we will be hiding a message in the least significant bit of the blue channel of each pixel in the image.
  To do this, we will iterate over each pixel in the image, read the blue channel value and replace the least significant bit
  with a bit from our message. Once we have replaced all the necessary bits, we will write the modified pixel data back to the image file.
*/

// Function to read a BMP file and store it into a 2D array
void read_image(char* filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][PIXEL_SIZE], int* width, int* height)
{
    FILE* infile = fopen(filename, "rb");

    // The first 54 bytes of a BMP file contain the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, infile);

    // Extract the image width and height from the header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Read the pixel data into the 2D array
    int padding = 0;
    while (*width % 4 != 0)
        padding++, *width++;
    unsigned char pixel_data[*height][*width * PIXEL_SIZE + padding];
    fread(pixel_data, sizeof(unsigned char), *height * (*width * PIXEL_SIZE + padding), infile);

    // Copy the pixel data into the 3D array
    for (int i = 0; i < *height; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            image[i][j][2] = pixel_data[i][j * PIXEL_SIZE + 2];
            image[i][j][1] = pixel_data[i][j * PIXEL_SIZE + 1];
            image[i][j][0] = pixel_data[i][j * PIXEL_SIZE];
        }
    }

    fclose(infile);
}

// Function to write the modified image data back to a BMP file
void write_image(char* filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][PIXEL_SIZE], int width, int height)
{
    FILE* outfile = fopen(filename, "wb");

    // Write the header information to the output file
    unsigned char header[54] =
    {
        0x42, 0x4d, 0x36, 0x00, 0x0c, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x0c, 0x00, 0x13, 0x0b, 0x00, 0x00,
        0x13, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    };
    *(int*)&header[2] = 54 + height * width * PIXEL_SIZE;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    fwrite(header, sizeof(unsigned char), 54, outfile);

    // Write the pixel data to the output file
    int padding = 0;
    while (width % 4 != 0)
        padding++, width++;
    unsigned char pixel_data[height][width * PIXEL_SIZE + padding];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel_data[i][j * PIXEL_SIZE + 2] = image[i][j][2];
            pixel_data[i][j * PIXEL_SIZE + 1] = image[i][j][1];
            pixel_data[i][j * PIXEL_SIZE] = image[i][j][0];
        }
    }
    fwrite(pixel_data, sizeof(unsigned char), height * (width * PIXEL_SIZE + padding), outfile);

    fclose(outfile);
}

// Function to convert a character to a binary string
void char_to_bin(char c, char* binstr)
{
    for (int i = 0; i < 8; i++)
    {
        if (c & 1 << i)
            binstr[7 - i] = '1';
        else
            binstr[7 - i] = '0';
    }
    binstr[8] = '\0';
}

// Function to convert a binary string to a character
char bin_to_char(char* binstr)
{
    char c = 0;
    for (int i = 0; i < 8; i++)
    {
        if (binstr[7 - i] == '1')
            c |= 1 << i;
        else
            c &= ~(1 << i);
    }
    return c;
}

// Function to hide a message in an image
void hide_message(char* message, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][PIXEL_SIZE], int width, int height)
{
    // Convert the message to binary format
    char message_bin[MAX_MESSAGE_SIZE * 8];
    int len = strlen(message);
    for (int i = 0; i < len; i++)
        char_to_bin(message[i], &message_bin[i * 8]);

    // Hide the message in the image
    int index = 0;
    int x = 0, y = 0;
    while (index < len * 8)
    {
        char bit = message_bin[index];
        image[y][x][2] = (image[y][x][2] & 0xfe) | bit;
        index++;
        if (index % 3 == 0)
        {
            x++;
            if (x == width)
            {
                x = 0;
                y++;
            }
        }
    }
}

// Function to retrieve a message from an image
void retrieve_message(char* message, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][PIXEL_SIZE], int width, int height)
{
    // Retrieve the message from the image
    int index = 0;
    char message_bin[MAX_MESSAGE_SIZE * 8];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            message_bin[index++] = image[y][x][2] & 0x01;
            if (index >= MAX_MESSAGE_SIZE * 8)
                break;
        }
        if (index >= MAX_MESSAGE_SIZE * 8)
            break;
    }

    // Convert the binary message to text format
    for (int i = 0; i < MAX_MESSAGE_SIZE; i++)
    {
        char binstr[9];
        strncpy(binstr, &message_bin[i * 8], 8);
        message[i] = bin_to_char(binstr);
        if (message[i] == '\0')
            break;
    }
}

int main()
{
    unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][PIXEL_SIZE];
    char message[MAX_MESSAGE_SIZE];

    // Read the image file
    int width, height;
    read_image("input.bmp", image, &width, &height);

    // Hide a message in the image
    printf("Enter message to hide in image: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    hide_message(message, image, width, height);
    write_image("output.bmp", image, width, height);
    printf("Message hidden successfully!\n");

    // Retrieve the message from the image
    read_image("output.bmp", image, &width, &height);
    retrieve_message(message, image, width, height);
    printf("\nRetrieved message: %s\n", message);

    return 0;
}