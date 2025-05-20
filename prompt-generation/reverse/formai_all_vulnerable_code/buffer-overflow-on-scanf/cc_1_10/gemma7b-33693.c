//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

char words[MAX_WORDS][20];

void spell_checker()
{
    int i, j, word_count = 0;

    printf("Enter a word: ");
    scanf("%s", words[word_count]);
    word_count++;

    for (i = 0; i < word_count; i++)
    {
        for (j = 0; words[i][j] != '\0'; j++)
        {
            // Logic to check if the letter is valid
            if (words[i][j] < 'a' || words[i][j] > 'z')
            {
                printf("Error: Invalid letter.\n");
                return;
            }
        }

        // Logic to check if the word exists
        if (word_count > 1)
        {
            for (j = 0; j < word_count; j++)
            {
                if (strcmp(words[i], words[j]) == 0)
                {
                    printf("Error: Word already exists.\n");
                    return;
                }
            }
        }

        printf("Word added: %s\n", words[i]);
    }

    printf("Thank you for using the spell checker.\n");
}

int main()
{
    spell_checker();

    return 0;
}