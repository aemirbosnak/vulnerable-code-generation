//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    int word_length = strlen(word);

    // Check if the word is in the dictionary
    int is_word_valid = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (word[i] == '\0')
        {
            is_word_valid = 1;
            break;
        }

        // Check if the character is a letter
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            // Check if the character is repeated
            int character_repeat = 0;
            for (int j = 0; j < i; j++)
            {
                if (word[i] == word[j])
                {
                    character_repeat = 1;
                    break;
                }
            }

            // If the character is not repeated, add it to the word
            if (!character_repeat)
            {
                word[i] = 'x';
            }
        }
    }

    // Print the corrected word
    printf("The corrected word is: ");
    for (int i = 0; i < word_length; i++)
    {
        if (word[i] != '\0')
        {
            printf("%c ", word[i]);
        }
    }

    printf("\n");

    return 0;
}