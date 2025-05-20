//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

int main()
{
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    int word_length = strlen(word);

    // Check if the word is valid
    if (word_length > 0 && word_length <= MAX_WORD_LENGTH)
    {
        int i = 0;
        for (i = 0; i < word_length; i++)
        {
            // Check if the character is alphabetical
            if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
            {
                // Check if the character is repeated
                int j = 0;
                for (j = 0; j < i; j++)
                {
                    if (word[i] == word[j])
                    {
                        printf("Error: The character %c is repeated.\n", word[i]);
                        return 1;
                    }
                }
            }
            else
            {
                printf("Error: The character %c is not alphabetical.\n", word[i]);
                return 1;
            }
        }

        // The word is valid
        printf("The word %s is valid.\n", word);
    }
    else
    {
        printf("Error: The word is too long or too short.\n");
        return 1;
    }

    return 0;
}