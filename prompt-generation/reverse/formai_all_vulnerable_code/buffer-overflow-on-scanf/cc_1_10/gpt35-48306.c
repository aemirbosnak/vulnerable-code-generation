//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This compression algorithm uses a happy approach to compress text */

void compress(char* input, char* output)
{
    int i, j, count;
    char prev, current;
    
    // Initialize count
    count = 1;
    
    // Initialize previous character to first character of input
    prev = input[0];
    
    // Loop through input string
    for (i = 1, j = 0; i < strlen(input); i++)
    {
        current = input[i];
        
        // If current character is equal to previous character, increase the count
        if (current == prev)
        {
            count++;
        }
        else
        {
            // If current character is not equal to previous character, write compressed data to output
            output[j++] = prev;
            output[j++] = count + '0';
            
            // Reset count
            count = 1;
        }
        
        // Update previous character
        prev = current;
    }
    
    // Write last compressed data to output
    output[j++] = prev;
    output[j++] = count + '0';
    
    // Add null terminator to output string
    output[j] = '\0';
}

int main()
{
    char input[100], compressed[100];
    
    printf("Enter text to compress: ");
    scanf("%s", input);
    
    // Call compress function
    compress(input, compressed);
    
    if (strlen(input) > strlen(compressed))
    {
        printf("Text has been compressed! Compressed data: %s\n", compressed);
    }
    else
    {
        printf("Text was not compressed as it would not save space! Original data: %s\n", input);
    }
    
    return 0;
}