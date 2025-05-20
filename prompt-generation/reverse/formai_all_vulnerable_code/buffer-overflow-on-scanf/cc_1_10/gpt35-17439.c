//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];
    printf("Welcome to the unique C Compression algorithm program! \n\n");

    printf("Enter the string you want to compress: ");
    scanf("%s", input);

    int len = strlen(input);
    char compressed[256]; // allocate a buffer for compressed data

    int i = 0, j = 0; // i for reading data, j for writing compressed data
    while (i < len)
    {
        int count = 1; // count number of consecutive characters
        while (input[i] == input[i+1])
        {
            count++;
            i++; // move to next character until it is different
        }

        if (count == 1) // if only one character, simply put it in output
        {
            compressed[j] = input[i];
            j++;
        }
        else // if more than one character, write the count and then character
        {
            char buffer[256]; // allocate a buffer for the count
            snprintf(buffer, sizeof(buffer), "%d", count); // convert count to string

            int buffer_len = strlen(buffer);
            for (int k = 0; k < buffer_len; k++) // write the count
            {
                compressed[j] = buffer[k];
                j++;
            }

            compressed[j] = input[i]; // write the character
            j++;
        }
        i++; // move to next character
    }
    compressed[j] = '\0'; // terminate the compressed string

    printf("Compressed string: %s\n", compressed);

    return 0;
}