//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run Length Encoding (RLE) compression
char* compress(char* str)
{
    // Get the length of the input string
    int size = strlen(str);

    // Allocate memory for the compressed string
    char* compressed_str = (char*) malloc(sizeof(char) * (size + 1));

    // Initialize the variables
    int count = 1;
    char curr = str[0];
    int j = 0;

    // Loop through the input string
    for (int i = 1; i <= size; i++)
    {
        // If the current character is the same as the previous
        // character, increment the count
        if (str[i] == curr)
        {
            count++;
        }
        // Otherwise, add the count and current character to the
        // compressed string and move to the next character
        else
        {
            // Convert the count to a string and add it to the compressed string
            char count_str[5];
            sprintf(count_str, "%d", count);
            int count_size = strlen(count_str);
            for (int k = 0; k < count_size; k++)
            {
                compressed_str[j] = count_str[k];
                j++;
            }
            // Add the current character to the compressed string
            compressed_str[j] = curr;
            j++;
            // Reset the count and move to the next character
            count = 1;
            curr = str[i];
        }
    }

    // Add the terminating null character to the compressed string
    compressed_str[j] = '\0';

    return compressed_str;
}

// Main function
int main()
{
    // Get the input string from the user
    char* str = (char*) malloc(sizeof(char) * 100);
    printf("Enter the input string: ");
    scanf("%s", str);

    // Compress the input string
    char* compressed_str = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_str);

    // Free the memory
    free(str);
    free(compressed_str);

    return 0;
}