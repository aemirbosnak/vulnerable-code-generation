//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char *word)
{
    int i, word_length, flag = 0;
    char *dictionary[] = {"apple", "banana", "orange", "grape", "mango", "pineapple", "apricot", "peach", "pear", "apricot"};

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
        printf("Error: Invalid characters.\n");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (strcmp(word, dictionary[i]) == 0)
            {
                printf("Word: %s is correct.\n", word);
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            printf("Word: %s is not found.\n", word);
        }
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