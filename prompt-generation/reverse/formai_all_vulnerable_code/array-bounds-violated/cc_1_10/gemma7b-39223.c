//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex = 0;
    char previousChar = '\0';
    char currentChar = '\0';

    printf("Enter text: ");

    // Get text from user
    while ((currentChar = getchar()) != '\n')
    {
        // Check if character is different from previous character
        if (currentChar != previousChar)
        {
            // Write previous character to buffer
            buffer[bufferIndex++] = previousChar;

            // Write character count to buffer
            buffer[bufferIndex++] = (int)currentChar - (int)previousChar + 1;
        }

        previousChar = currentChar;
    }

    // Write remaining character to buffer
    buffer[bufferIndex++] = previousChar;

    // Write character count to buffer
    buffer[bufferIndex++] = (int)previousChar - (int)previousChar + 1;

    // Compress the text
    int compressedSize = 0;
    char compressedBuffer[MAX_BUFFER_SIZE];

    for (int i = 0; i < bufferIndex; i++)
    {
        int count = buffer[i] - buffer[i-1] + 1;
        compressedBuffer[compressedSize++] = count;
    }

    // Print the compressed text
    printf("Compressed text: ");
    for (int i = 0; i < compressedSize; i++)
    {
        printf("%d ", compressedBuffer[i]);
    }

    printf("\n");

    return 0;
}