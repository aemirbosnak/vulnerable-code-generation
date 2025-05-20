//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main()
{
    char str[MAX];
    int i, count = 0, c_word = 0;

    printf("Enter a text: ");
    fgets(str, MAX, stdin);

    // Remove punctuation from the text
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
        {
            str[i] = '\0';
        }
    }

    // Count the number of words in the text
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    // Count the number of complete words in the text
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i-1] >= 'a' && str[i-1] <= 'z')
        {
            c_word++;
        }
    }

    // Print the results
    printf("\nNumber of words in the text: %d", count);
    printf("\nNumber of complete words in the text: %d", c_word);

    return 0;
}