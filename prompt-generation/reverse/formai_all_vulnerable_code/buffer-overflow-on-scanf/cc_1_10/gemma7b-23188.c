//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main()
{
    char str[MAX];
    int i, j, k, flag = 0;
    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is a letter
        if (isalpha(str[i]))
        {
            // Check if the character is uppercase
            if (isupper(str[i]))
            {
                // Convert the character to lowercase
                str[i] = tolower(str[i]);
            }

            // Iterate over the remaining characters in the word
            for (j = i + 1; str[j] != '\0'; j++)
            {
                // Check if the character is a letter and not the same as the first character
                if (isalpha(str[j]) && str[j] != str[i])
                {
                    // Flag the word as having errors
                    flag = 1;
                }
            }
        }
    }

    // Check if the word has errors
    if (flag)
    {
        printf("The word has errors.\n");
    }
    else
    {
        printf("The word is valid.\n");
    }

    return 0;
}