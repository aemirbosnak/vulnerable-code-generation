//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

// This is a simple implementation of Run Length Encoding algorithm in C language.

int main()
{
    // Input data to be encoded
    char data[MAX_SIZE];
    printf("Enter the data to be encoded: ");
    fgets(data, MAX_SIZE, stdin);

    // Length of the input data
    int len = strlen(data) - 1;

    // Initialize variables for RLE compression
    int count = 1, i = 0, j = 0;
    char result[MAX_SIZE];

    // Start compressing the input data
    while(i < len)
    {
        // Check if the next character is equal to the current character
        if(data[i] == data[i + 1])
        {
            // Increment count for the repeated characters
            count++;
        }
        else
        {
            // Add the count and current character to the result string
            result[j++] = count + '0';
            result[j++] = data[i];

            // Reset count for the next character
            count = 1;
        }

        i++;
    }

    // Add the last character to the result string
    result[j++] = count + '0';
    result[j++] = data[len - 1];

    // Add the terminating null character to the result string
    result[j] = '\0';

    // Print the compressed data
    printf("\nCompressed data: %s\n", result);

    // Decode the compressed data
    i = 0;
    j = 0;
    char decoded[MAX_SIZE];

    while(i < len)
    {
        // Extract the count of the repeated characters
        int count = result[i++] - '0';

        // Repeat the current character 'count' times
        while(count--)
        {
            decoded[j++] = result[i];
        }

        i++;
    }

    // Add the terminating null character to the decoded string
    decoded[j] = '\0';

    // Print the decoded data
    printf("\nDecoded data: %s\n", decoded);

    return 0;
}