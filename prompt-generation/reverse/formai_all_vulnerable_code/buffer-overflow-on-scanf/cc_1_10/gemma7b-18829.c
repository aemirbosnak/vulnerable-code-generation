//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char *word)
{
    int i, word_length, valid = 1;
    char *dictionary[] = {"apple", "banana", "orange", "grape", "apricot", "mango", "peach", "watermelon", "apricot", "pineapple"};

    word_length = strlen(word);

    for (i = 0; i < word_length; i++)
    {
        if (!isalnum(word[i]))
        {
            valid = 0;
            break;
        }
    }

    if (valid)
    {
        for (i = 0; i < 10; i++)
        {
            if (strcmp(word, dictionary[i]) == 0)
            {
                printf("Word: %s is valid\n", word);
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            printf("Word: %s is not valid\n", word);
        }
    }
    else
    {
        printf("Error: Invalid input\n");
    }
}

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    spell_checker(word);

    return 0;
}