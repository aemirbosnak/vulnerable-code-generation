//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main()
{
    char str[MAX];
    int i, len, comp_size, original_size, count = 0;
    printf("Enter a string: ");
    gets(str);

    len = strlen(str);
    original_size = len;

    // Compress the string
    for (i = 0; i < len; i++)
    {
        char current_char = str[i];
        int occurrences = 0;

        // Count the occurrences of the current character
        for (int j = 0; j < len; j++)
        {
            if (current_char == str[j])
            {
                occurrences++;
            }
        }

        // Replace the character with its occurrences
        str[i] = occurrences + 'a';

        // Update the count of occurrences
        count++;
    }

    // Calculate the compressed size
    comp_size = count + 1;

    // Print the compressed size
    printf("Compressed size: %d", comp_size);

    // Print the compressed string
    printf("\nCompressed string: ");
    printf("%s", str);

    // Calculate the compression ratio
    float ratio = (float)original_size / comp_size;

    // Print the compression ratio
    printf("\nCompression ratio: %.2f", ratio);

    return 0;
}