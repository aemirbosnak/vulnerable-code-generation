//FormAI DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the string
char* compressString(char* str)
{
    int len = strlen(str);
    int i = 0, j = 0;

    // Create a new compressed string
    char* compressed = (char*) malloc(sizeof(char) * (len + 1));

    // Loop through the string
    while (i < len)
    {

        char current = str[i];
        compressed[j++] = current;

        // Count consecutive similar characters
        int count = 1;
        while (current == str[i+1])
        {
            count++;
            i++;
        }

        // Add the count to the compressed string
        char numStr[10];
        sprintf(numStr, "%d", count);

        int k;
        for (k = 0; k < strlen(numStr); ++k)
        {
            compressed[j++] = numStr[k];
        }

        i++;
    }

    // End the compressed string with a null terminator
    compressed[j] = '\0';

    return compressed;
}

int main()
{
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%s", str);

    char* compressed = compressString(str);

    printf("Compressed string: %s\n", compressed);

    free(compressed);

    return 0;
}