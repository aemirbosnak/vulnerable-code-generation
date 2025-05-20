//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main()
{
    // Get the image file name.
    char image_file_name[MAX_SIZE];
    printf("Enter the image file name: ");
    scanf("%s", image_file_name);

    // Open the image file.
    FILE *image_file = fopen(image_file_name, "rb");
    if (image_file == NULL)
    {
        printf("Error opening the image file.\n");
        return 1;
    }

    // Get the image file size.
    fseek(image_file, 0, SEEK_END);
    long image_file_size = ftell(image_file);
    rewind(image_file);

    // Read the image file into a buffer.
    unsigned char *image_buffer = (unsigned char *)malloc(image_file_size);
    if (image_buffer == NULL)
    {
        printf("Error allocating memory for the image buffer.\n");
        return 1;
    }
    fread(image_buffer, 1, image_file_size, image_file);
    fclose(image_file);

    // Get the message to hide.
    char message[MAX_SIZE];
    printf("Enter the message to hide: ");
    scanf("%s", message);

    // Convert the message to binary.
    int message_length = strlen(message);
    unsigned char *message_binary = (unsigned char *)malloc(message_length * 8);
    if (message_binary == NULL)
    {
        printf("Error allocating memory for the message binary.\n");
        return 1;
    }
    for (int i = 0; i < message_length; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            message_binary[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Hide the message in the image.
    int message_index = 0;
    for (int i = 0; i < image_file_size; i++)
    {
        if (message_index < message_length * 8)
        {
            image_buffer[i] = (image_buffer[i] & 0b11111110) | message_binary[message_index++];
        }
    }

    // Save the stego image.
    char stego_image_file_name[MAX_SIZE];
    printf("Enter the stego image file name: ");
    scanf("%s", stego_image_file_name);

    // Open the stego image file.
    FILE *stego_image_file = fopen(stego_image_file_name, "wb");
    if (stego_image_file == NULL)
    {
        printf("Error opening the stego image file.\n");
        return 1;
    }

    // Write the stego image to file.
    fwrite(image_buffer, 1, image_file_size, stego_image_file);
    fclose(stego_image_file);

    // Free the buffers.
    free(image_buffer);
    free(message_binary);

    printf("Message successfully hidden in the image.\n");

    return 0;
}