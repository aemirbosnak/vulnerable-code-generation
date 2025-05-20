//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    int original_length = 0;
    int compressed_length = 0;
    int run_length = 1;

    printf("Enter text: ");
    // Get the text from the user
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the original length of the text
    original_length = strlen(buffer) + 1;

    // Iterate over the text and compress it
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // If the current character is the same as the previous character, increment run length
        if (buffer[i] == buffer[i - 1])
        {
            run_length++;
        }
        else
        {
            // Write the previous character and its run length to the compressed text
            compressed_length++;
            fprintf(stderr, "%c%d ", buffer[i - 1], run_length);

            // Reset run length to 1
            run_length = 1;
        }
    }

    // Write the final character and its run length
    compressed_length++;
    fprintf(stderr, "%c%d ", buffer[i - 1], run_length);

    // Calculate the compressed length
    compressed_length -= 1;

    // Print the compressed length
    printf("Compressed length: %d\n", compressed_length);

    return 0;
}