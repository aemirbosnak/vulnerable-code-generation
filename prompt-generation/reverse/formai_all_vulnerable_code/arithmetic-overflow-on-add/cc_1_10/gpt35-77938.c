//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// function prototypes
void compress(char str[]);
void decompress(char str[]);

int main()
{
    char str[MAX];

    // input a string from user
    printf("Enter a string to compress: ");
    fgets(str, MAX, stdin);

    // remove the newline character
    str[strcspn(str, "\n")] = 0;

    printf("\nOriginal string: %s\n", str);

    // compress the string
    compress(str);
    printf("Compressed string: %s\n\n", str);

    // decompress the string
    decompress(str);
    printf("Decompressed string: %s\n", str);

    return 0;
}

void compress(char str[])
{
    int count = 1, index = 1, i;
    char current = str[0];

    // iterate through each character in the string
    while (str[index] != '\0')
    {
        // if current character matches previous character
        if (str[index] == current)
        {
            count++;  // increment count
        }
        else
        {
            // if count is greater than 1, add it to compressed string
            if (count > 1)
            {
                str[i] = count + '0';
                i++;
            }
            str[i] = current;  // add current character to compressed string
            i++;

            count = 1;  // reset count
            current = str[index];  // set current character to new character
        }
        index++;
    }

    // add the last character and count to compressed string
    if (count > 1)
    {
        str[i] = count + '0';
        i++;
    }
    str[i] = current;  // add current character to compressed string
    i++;
    str[i] = '\0';  // terminate compressed string
}

void decompress(char str[])
{
    int i, count = 0, index = 0;

    // iterate through each character in the string
    while (str[index] != '\0')
    {
        // if character is a digit, update count
        if (isdigit(str[index]))
        {
            count = count * 10 + (str[index] - '0');
        }
        else
        {
            // if count is greater than 1, add it to decompressed string multiple times
            if (count > 1)
            {
                for (i = 0; i < count; i++)
                {
                    str[i] = str[index];
                }
                index++;
            }
            else
            {
                str[i] = str[index];
                index++;
                i++;
            }
            count = 0;  // reset count
        }
    }
    str[i] = '\0';  // terminate decompressed string
}