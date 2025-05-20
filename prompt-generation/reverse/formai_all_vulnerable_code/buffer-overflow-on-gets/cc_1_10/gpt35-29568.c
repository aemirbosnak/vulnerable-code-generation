//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compress(char* str)
{
    // Declaration of variables
    char temp[1000];
    int count = 0, size = 0;

    // Traverse through the string
    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = i;

        // Count the number of consecutive characters
        while (str[j] == str[i])
        {
            count++;
            j++;
        }

        // Add the character and its count to the compressed string
        temp[size++] = str[i];

        // If count > 1, add it to the compressed string
        if (count > 1)
        {
            char countStr[10];
            sprintf(countStr, "%d", count);
            for (int k = 0; countStr[k] != '\0'; k++)
            {
                temp[size++] = countStr[k];
            }
        }

        // Update i to the last counted character's position
        i = j - 1;

        // Reset count for the next character
        count = 0;
    }

    // Null terminate the compressed string
    temp[size] = '\0';

    // Copy the compressed string to a dynamic memory allocation
    char *compressedStr = (char*)malloc((size + 1) * sizeof(char));
    strcpy(compressedStr, temp);

    return compressedStr;
}

int main()
{
    // User input string
    char str[1000];
    printf("Enter a string to compress it: ");
    gets(str);

    // Compression
    char *compressedStr = compress(str);

    // Results
    printf("\n\nOriginal string: %s\n", str);
    printf("Compressed string: %s\n", compressedStr);

    // Free the dynamic memory allocation
    free(compressedStr);

    return 0;
}