//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void embedMessage(char* filePath, char* message);
void extractMessage(char* filePath);

int main()
{
    char filePath[100];
    char message[1000];
    int choice;
    
    printf("---DIGITAL WATERMARKING---\n\n");
    printf("Choose an option:\n");
    printf("1. Embed message\n");
    printf("2. Extract message\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter the file path of the image: ");
            scanf("%s", filePath);
            printf("Enter the message to embed: ");
            scanf("%s", message);
            embedMessage(filePath, message);
            printf("Message embedding completed.\n");
            break;
        case 2:
            printf("Enter the file path of the image: ");
            scanf("%s", filePath);
            extractMessage(filePath);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}

void embedMessage(char* filePath, char* message)
{
    FILE* fptr = fopen(filePath, "r+b");
    
    if(fptr == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // skip the BMP header
    fseek(fptr, 54, SEEK_SET);
    
    int messageLen = strlen(message);
    int currCharIndex = 0; // current char index of the message
    int bitIndex = 0; // current bit index of the current char
    char currChar = message[currCharIndex];
    
    while(currCharIndex < messageLen)
    {
        char pixel;
        fread(&pixel, 1, 1, fptr);
        
        // manipulate the LSB of the pixel
        pixel &= ~(1 << bitIndex); // clear LSB
        pixel |= ((currChar >> bitIndex) & 1) << bitIndex; // set LSB to the bit of current char
        
        // write the pixel back to the file
        fseek(fptr, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, fptr);
        
        bitIndex++;
        
        // if we finished embedding a char, move to the next one
        if(bitIndex == 8)
        {
            currCharIndex++;
            bitIndex = 0;
            currChar = message[currCharIndex];
        }
    }
    
    fclose(fptr);
}

void extractMessage(char* filePath)
{
    FILE* fptr = fopen(filePath, "rb");
    
    if(fptr == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // skip the BMP header
    fseek(fptr, 54, SEEK_SET);
    
    char message[1000] = {0}; // initialize with zeros
    int currCharIndex = 0;
    int bitIndex = 0;
    
    while(1)
    {
        char pixel;
        fread(&pixel, 1, 1, fptr);
        
        // extract the LSB of the pixel
        char bit = (pixel & 1) << bitIndex;
        message[currCharIndex] |= bit;
        
        bitIndex++;
        
        // if we extracted a full char, move to the next one
        if(bitIndex == 8)
        {
            bitIndex = 0;
            currCharIndex++;
        }
        
        if(pixel == '\0') // stop at the null terminator character
        {
            message[currCharIndex - 1] = '\0';
            break;
        }
    }
    
    printf("Extracted message: %s\n", message);
    
    fclose(fptr);
}