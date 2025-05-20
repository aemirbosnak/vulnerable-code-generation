//FormAI DATASET v1.0 Category: Compression algorithms ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void compress(char *s1, char *s2);
void decompress(char *s1, char *s2);

// main function
int main()
{
    char str1[100], str2[100];

    printf("Enter a string: ");
    scanf("%s", str1);

    printf("Original string: %s\n", str1);

    // compress the string
    compress(str1, str2);
    printf("Compressed string: %s\n", str2);

    // decompress the string
    decompress(str2, str1);
    printf("Decompressed string: %s\n", str1);

    return 0;
}

// function to compress the string
void compress(char *s1, char *s2)
{
    int count, i, j, len;

    len = strlen(s1);

    // iterate through the string
    for (i = 0, j = 0; i < len; i = j)
    {
        s2[j++] = s1[i]; // copy the character

        // count number of consecutive occurrences of the character
        for (count = 1; s1[i] == s1[i+1] && i+1 < len; count++, i++);
        
        // convert the count to string
        char buffer[10];
        sprintf(buffer, "%d", count);

        // copy the count to the compressed string
        if (count > 1)
        {
            int k;
            for (k = 0; buffer[k] != '\0'; k++, j++)
            {
                s2[j] = buffer[k];
            }
        }
    }

    // add null terminator to the compressed string
    s2[j] = '\0';
}

// function to decompress the string
void decompress(char *s1, char *s2)
{
    int i, j, len;

    len = strlen(s1);

    // iterate through the compressed string
    for (i = 0, j = 0; i < len; i++, j++)
    {
        s2[j] = s1[i]; // copy the character

        // check if the next character is a digit
        if (isdigit(s1[i+1]))
        {
            // get the count
            int count = s1[++i] - '0';

            // get the remaining digits if count is more than 1 digit
            while (isdigit(s1[i+1]))
            {
                count = count * 10 + (s1[++i] - '0');
            }

            // repeat the character count times in the decompressed string
            int k;
            for (k = 1; k < count; k++)
            {
                s2[++j] = s2[j-1];
            }
        }
    }

    // add null terminator to the decompressed string
    s2[++j] = '\0';
}