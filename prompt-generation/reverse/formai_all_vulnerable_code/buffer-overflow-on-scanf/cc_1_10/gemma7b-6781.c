//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    int i, j, word_length, flag = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    word_length = strlen(word);

    for (i = 0; i < word_length; i++)
    {
        if (!isalnum(word[i]))
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("Error: Invalid input. Please enter a word with only letters and numbers.\n");
    }
    else
    {
        for (j = 0; j < word_length; j++)
        {
            word[j] = tolower(word[j]);
        }

        int count = 0;
        for (i = 0; i < word_length; i++)
        {
            char letter = word[i];
            int letter_frequency = 0;

            for (j = 0; j < word_length; j++)
            {
                if (word[j] == letter)
                {
                    letter_frequency++;
                }
            }

            if (letter_frequency > 1)
            {
                count++;
            }
        }

        if (count)
        {
            printf("Word has repeated letters.\n");
        }
        else
        {
            printf("Word has no repeated letters.\n");
        }
    }

    return 0;
}