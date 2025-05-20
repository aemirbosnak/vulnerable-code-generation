//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Define maximum size for file names and message strings
#define MAX_FILENAME_SIZE 100
#define MAX_MSG_SIZE 1000

// Define bitwise operations 
#define GET_BIT(num, bit) (num & (1 << bit))
#define SET_BIT(num, bit) (num | (1 << bit))
#define CLR_BIT(num, bit) (num & ~(1 << bit))
#define TOGGLE_BIT(num, bit) (num ^ (1 << bit))

// Function to hide the message in the image
bool hide_message_in_image(char *img_filename, char *msg, char *output_filename);

// Function to extract the message from the image
bool extract_message_from_image(char *img_filename, char *output_filename);

int main()
{
    // Define filenames and message string
    char img_filename[MAX_FILENAME_SIZE];
    char msg[MAX_MSG_SIZE];
    char output_filename[MAX_FILENAME_SIZE] = "hidden_image.bmp";
    bool success = false;
    
    // Get input for image filename and message to hide
    printf("Enter the filename of the image to hide the message: ");
    scanf("%s", img_filename);
    printf("Enter the message to hide: ");
    getchar();
    fgets(msg, MAX_MSG_SIZE, stdin);
    
    // Hide the message in the image and check for success
    success = hide_message_in_image(img_filename, msg, output_filename);
    if (success)
    {
        printf("Message was successfully hidden in the image!\n");
    }
    else
    {
        printf("Error hiding the message in the image.\n");
        return 1;
    }
    
    // Extract the message from the image and check for success
    success = extract_message_from_image(output_filename, "extracted_message.txt");
    if (success)
    {
        printf("Message was successfully extracted from the image!\n");
    }
    else
    {
        printf("Error extracting the message from the image.\n");
        return 1;
    }
    
    return 0;
}

bool hide_message_in_image(char *img_filename, char *msg, char *output_filename)
{
    // Open the image file for binary reading
    FILE *img_file = fopen(img_filename, "rb");
    if (!img_file)
    {
        printf("Error opening the image file.\n");
        return false;
    }
    
    // Get the file size to allocate memory
    fseek(img_file, 0, SEEK_END);
    long int file_size = ftell(img_file);
    rewind(img_file);
    
    // Read the image data into buffer
    uint8_t *img_buf = (uint8_t*)malloc(sizeof(uint8_t) * file_size);
    if (!img_buf)
    {
        printf("Error allocating memory for image buffer.\n");
        fclose(img_file);
        return false;
    }
    fread(img_buf, sizeof(uint8_t), file_size, img_file);
    
    // Close the image file
    fclose(img_file);
    
    // Open the output file for binary writing
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file)
    {
        printf("Error opening the output file.\n");
        free(img_buf);
        return false;
    }
    
    // Write the BMP file header to output file
    fwrite(img_buf, sizeof(uint8_t), 54, output_file);
    
    // Initialize variables
    uint32_t msg_length = strlen(msg);
    uint32_t img_size = file_size - 54;
    uint32_t max_msg_size = img_size / 8;
    uint32_t bits_per_byte = 8;
    uint32_t i, j;
    
    // Check if message is too large to hide in image
    if (msg_length > max_msg_size)
    {
        printf("Message is too large to hide in image.\n");
        free(img_buf);
        fclose(output_file);
        return false;
    }
    
    // Hide message in image
    for (i = 0, j = 0; i < msg_length; i++, j += bits_per_byte)
    {
        uint8_t byte = msg[i];
        uint8_t img_byte = img_buf[54 + j / bits_per_byte];
        for (int k = 0; k < bits_per_byte; k++)
        {
            if (GET_BIT(byte, k))
            {
                img_byte = SET_BIT(img_byte, j % bits_per_byte + k);
            }
            else
            {
                img_byte = CLR_BIT(img_byte, j % bits_per_byte + k);
            }
        }
        img_buf[54 + j / bits_per_byte] = img_byte;
    }
    
    // Write the modified image data to output file
    fwrite(img_buf, sizeof(uint8_t), file_size, output_file);
    
    // Close the output file and free memory
    fclose(output_file);
    free(img_buf);
    
    return true;
}

bool extract_message_from_image(char *img_filename, char *output_filename)
{
    // Open the image file for binary reading
    FILE *img_file = fopen(img_filename, "rb");
    if (!img_file)
    {
        printf("Error opening the image file.\n");
        return false;
    }
    
    // Get the file size to allocate memory
    fseek(img_file, 0, SEEK_END);
    long int file_size = ftell(img_file);
    rewind(img_file);
    
    // Read the image data into buffer
    uint8_t *img_buf = (uint8_t*)malloc(sizeof(uint8_t) * file_size);
    if (!img_buf)
    {
        printf("Error allocating memory for image buffer.\n");
        fclose(img_file);
        return false;
    }
    fread(img_buf, sizeof(uint8_t), file_size, img_file);
    
    // Close the image file
    fclose(img_file);
    
    // Open the output file for writing
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        printf("Error opening the output file.\n");
        free(img_buf);
        return false;
    }
    
    // Initialize variables
    uint32_t img_size = file_size - 54;
    uint32_t bits_per_byte = 8;
    uint32_t i, j;
    char msg[MAX_MSG_SIZE] = {0};
    
    // Extract message from image
    for (i = 0, j = 0; j < img_size; i++, j += bits_per_byte)
    {
        uint8_t img_byte = img_buf[54 + j / bits_per_byte];
        uint8_t byte = 0;
        for (int k = 0; k < bits_per_byte; k++)
        {
            byte = TOGGLE_BIT(byte, k);
            if (GET_BIT(img_byte, j % bits_per_byte + k))
            {
                byte = SET_BIT(byte, k);
            }
            else
            {
                byte = CLR_BIT(byte, k);
            }
        }
        msg[i] = byte;
        if (byte == '\0')
        {
            break;
        }
    }
    
    // Write message to output file
    fprintf(output_file, "%s", msg);
    
    // Close the output file and free memory
    fclose(output_file);
    free(img_buf);
    
    return true;
}