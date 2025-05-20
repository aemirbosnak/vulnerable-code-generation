//FormAI DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define OFFSET 54 // Offset for BMP images
#define MAX_MESSAGE_SIZE 1000 // Maximum message size that can be hidden
#define BUFFER_SIZE 3 // Buffer size to store the values of pixels

int main()
{
    // Open the image file in binary mode
    FILE *fp = fopen("image.bmp", "rb");
    if (fp==NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read the image header
    unsigned char header[OFFSET];
    fread(header, sizeof(unsigned char), OFFSET, fp);
    
    // Get the height and width of the image
    int height = *(int*)(&header[18]);
    int width = *(int*)(&header[22]);
    
    // Calculate the total number of pixels in the image
    int total_pixels = height * width;
    
    // Check if the message can fit in the image
    int max_message_length = (total_pixels * BUFFER_SIZE) / 8;
    if (max_message_length < MAX_MESSAGE_SIZE)
    {
        printf("Error: Message is too large to fit in the image!\n");
        exit(1);
    }
    
    // Read the message from the user
    char message[MAX_MESSAGE_SIZE];
    printf("Enter the message to hide in the image:\n");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    
    // Calculate the length of the message
    int message_length = 0;
    while (message[message_length] != '\0')
    {
        message_length++;
    }
    
    // Convert the message to binary form
    char binary_message[MAX_MESSAGE_SIZE * 8];
    int binary_index = 0;
    for (int i = 0; i < message_length; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            binary_message[binary_index++] = ((message[i] >> j) & 1) + '0';
        }
    }
    
    // Set the LSBs of the image pixels to the binary message
    fseek(fp, OFFSET, SEEK_SET);
    int message_index = 0;
    for (int i = 0; i < total_pixels; i++)
    {
        unsigned char buffer[BUFFER_SIZE];
        fread(buffer, sizeof(unsigned char), BUFFER_SIZE, fp);
        
        for (int j = 0; j < BUFFER_SIZE; j++)
        {
            // Replace the LSB with the binary message
            if (message_index < (message_length * 8))
            {
                buffer[j] = (buffer[j] & 0xFE) | (binary_message[message_index++] - '0');
            }
        }
        
        // Write the new pixel values to the image
        fseek(fp, -3, SEEK_CUR);
        fwrite(buffer, sizeof(unsigned char), BUFFER_SIZE, fp);
    }
    
    // Close the image file
    fclose(fp);
    
    printf("Message hidden successfully in the image!\n");
    
    return 0;
}