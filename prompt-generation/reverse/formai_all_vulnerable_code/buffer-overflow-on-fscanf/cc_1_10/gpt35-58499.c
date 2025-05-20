//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
} Pixel;

void hide_data_in_image(char* image_path, char* message_path)
{
    FILE* image_file = fopen(image_path, "rb");
    FILE* message_file = fopen(message_path, "r");

    if (image_file == NULL || message_file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read the image data
    int width, height, max_color_value;
    int image_size, bytes_per_pixel;

    fscanf(image_file, "P3\n%d %d\n%d\n", &width, &height, &max_color_value);
    image_size = width * height;
    bytes_per_pixel = 3;

    Pixel* image_data = malloc(image_size * sizeof(Pixel));
    for (int i = 0; i < image_size; i++)
    {
        fscanf(image_file, "%d %d %d", &image_data[i].red, &image_data[i].green, &image_data[i].blue);
    }

    // Read the message data
    fseek(message_file, 0, SEEK_END);
    long message_size = ftell(message_file);
    rewind(message_file);

    char* message_data = malloc(message_size);
    fread(message_data, sizeof(char), message_size, message_file);

    // Hide the message in the image data
    int message_index = 0;
    for (int i = 0; i < image_size; i++)
    {
        if (message_index >= message_size)
        {
            break;
        }

        // Store the message bits in the least significant bits of each pixel color value
        image_data[i].red = (image_data[i].red & 0b11111110) | (message_data[message_index] & 0b00000001);
        image_data[i].green = (image_data[i].green & 0b11111110) | (message_data[message_index] >> 1 & 0b00000001);
        image_data[i].blue = (image_data[i].blue & 0b11111110) | (message_data[message_index] >> 2 & 0b00000001);

        message_index++;
    }

    // Save the modified image data to a new file
    FILE* new_image_file = fopen("modified_image.ppm", "wb");
    fprintf(new_image_file, "P3\n%d %d\n%d\n", width, height, max_color_value);
    for (int i = 0; i < image_size; i++)
    {
        fprintf(new_image_file, "%d %d %d ", image_data[i].red, image_data[i].green, image_data[i].blue);
    }

    printf("Message hidden in image successfully\n");

    // Close all files and free memory
    fclose(image_file);
    fclose(message_file);
    fclose(new_image_file);
    free(image_data);
    free(message_data);
}

void extract_data_from_image(char* image_path, char* message_path)
{
    FILE* image_file = fopen(image_path, "rb");
    FILE* message_file = fopen(message_path, "w");

    if (image_file == NULL || message_file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read the image data
    int width, height, max_color_value;
    int image_size, bytes_per_pixel;

    fscanf(image_file, "P3\n%d %d\n%d\n", &width, &height, &max_color_value);
    image_size = width * height;
    bytes_per_pixel = 3;

    Pixel* image_data = malloc(image_size * sizeof(Pixel));
    for (int i = 0; i < image_size; i++)
    {
        fscanf(image_file, "%d %d %d", &image_data[i].red, &image_data[i].green, &image_data[i].blue);
    }

    // Extract the message from the image data
    char* message_data = malloc(image_size * sizeof(char));
    int message_index = 0;
    for (int i = 0; i < image_size; i++)
    {
        if (message_index >= image_size)
        {
            break;
        }

        // Retrieve the least significant bit of each pixel color value which contains one bit of the message
        message_data[message_index] = (image_data[i].red & 0b00000001) | (image_data[i].green >> 1 & 0b00000001) | (image_data[i].blue >> 2 & 0b00000001);

        message_index++;
    }

    // Save the extracted message data to a new file
    fwrite(message_data, sizeof(char), message_index, message_file);

    printf("Message extracted from image successfully\n");

    // Close all files and free memory
    fclose(image_file);
    fclose(message_file);
    free(image_data);
    free(message_data);
}

int main()
{
    // Hide a message in the image
    hide_data_in_image("image.ppm", "message.txt");

    // Extract the message from the image
    extract_data_from_image("modified_image.ppm", "extracted_message.txt");

    return 0;
}