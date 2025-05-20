//FormAI DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void hideMessage(char *message, FILE *inputImage, FILE *outputImage);
void retrieveMessage(FILE *imageWithMessage);

int main()
{
    char option;
    char message[MAX_SIZE];
    FILE *inputImage, *outputImage, *imageWithMessage;

    printf("C Image Steganography Program\n");
    printf("------------------------------\n\n");
    
    while(1)
    {
        printf("Please choose an option:\n");
        printf("h - Hide a message in an image\n");
        printf("r - Retrieve a message from an image\n");
        printf("q - Quit program\n");
        
        scanf(" %c", &option);
        getchar();  // removes trailing newline character
        
        if(option == 'h')
        {
            // Hiding a message in an image
            printf("\nEnter the message to hide in the image (max %d characters):\n", MAX_SIZE);
            fgets(message, MAX_SIZE, stdin);
            
            inputImage = fopen("input_image.bmp", "rb");
            outputImage = fopen("output_image.bmp", "wb");
            
            // Hides the message in the image and saves it to the output file
            hideMessage(message, inputImage, outputImage);
            
            fclose(inputImage);
            fclose(outputImage);
            
            printf("\nMessage hidden successfully!\n\n");
        }
        else if(option == 'r')
        {
            // Retrieving a message from an image
            imageWithMessage = fopen("output_image.bmp", "rb");
            
            // Retrieves the message from the image and prints it to the console
            retrieveMessage(imageWithMessage);
            
            fclose(imageWithMessage);
        }
        else if(option == 'q')
        {
            // Quit the program
            printf("\nGoodbye!\n");
            break;
        }
        else
        {
            printf("\nInvalid option. Please choose again.\n\n");
        }
    }
    
    return 0;
}

// Function to hide a message (as a string) in an image
void hideMessage(char *message, FILE *inputImage, FILE *outputImage)
{
    unsigned char buffer[54];
    unsigned char pixel[3];
    int messageIndex = 0;
    int bitIndex = 0;
    int bit;
    int i;
    
    // Copy the header of the BMP file to the output file
    fread(buffer, sizeof(unsigned char), 54, inputImage);
    fwrite(buffer, sizeof(unsigned char), 54, outputImage);
    
    // Loop through the pixels in the image and hide the message in the least significant bit of each color component
    while(fread(pixel, sizeof(unsigned char), 3, inputImage) == 3)
    {
        for(i = 0; i < 3; i++)
        {
            if(messageIndex < strlen(message))
            {
                // Get the next bit of the message to hide
                bit = (message[messageIndex] >> bitIndex) & 1;
                
                // Replace the least significant bit of the color component with the bit of the message
                pixel[i] = (pixel[i] & ~1) | bit;
                
                // Move to the next bit in the message
                bitIndex++;
                if(bitIndex == 8)
                {
                    messageIndex++;
                    bitIndex = 0;
                }
            }
        }
        
        // Write the pixel (with the hidden message) to the output file
        fwrite(pixel, sizeof(unsigned char), 3, outputImage);
    }
}

// Function to retrieve a message (as a string) from an image
void retrieveMessage(FILE *imageWithMessage)
{
    unsigned char buffer[54];
    unsigned char pixel[3];
    char message[MAX_SIZE];
    int messageIndex = 0;
    int bitIndex = 0;
    int bit;
    int i;
    
    // Skip the header of the BMP file
    fread(buffer, sizeof(unsigned char), 54, imageWithMessage);
    
    // Loop through the pixels in the image and retrieve the hidden message from the least significant bit of each color component
    while(fread(pixel, sizeof(unsigned char), 3, imageWithMessage) == 3)
    {
        for(i = 0; i < 3; i++)
        {
            // Get the least significant bit of the color component (this is where the message is hidden)
            bit = pixel[i] & 1;
            
            // Add the bit to the message
            message[messageIndex] |= bit << bitIndex;
            
            // Move to the next bit in the message
            bitIndex++;
            if(bitIndex == 8)
            {
                messageIndex++;
                bitIndex = 0;
            }
        }
    }
    
    // Print the retrieved message to the console
    printf("\nThe retrieved message is:\n%s\n\n", message);
}