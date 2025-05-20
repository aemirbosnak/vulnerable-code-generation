//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dictionary[500][30] = {"happy", "program", "spell", "checking", "example", "unique", "code", "compile", "run", "error", "sorry", "creative"};

int dictionary_count = 12;

void happy_spell_check(char *word)
{
    int i, j, flag = 0;
    char lower_case_word[30];
    strcpy(lower_case_word, word);

    for(i = 0; lower_case_word[i]; i++){
        lower_case_word[i] = tolower(lower_case_word[i]);
    }

    for(i = 0; i < dictionary_count; i++)
    {
        if(strcmp(dictionary[i], lower_case_word) == 0)
        {
            printf("The word '%s' is spelled correctly!", word);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Oops! The word '%s' is spelled incorrectly! Did you mean:\n", word);
        for(i = 0; i < dictionary_count; i++)
        {
            if(strlen(dictionary[i]) == strlen(lower_case_word))
            {
                int difference = 0;
                for(j = 0; lower_case_word[j]; j++)
                {
                    if(tolower(lower_case_word[j]) != tolower(dictionary[i][j]))
                    {
                        difference++;
                    }
                }

                if(difference == 1)
                {
                    printf("%s\n", dictionary[i]);
                }
            }
        }
    }
}

int main()
{
    char word[30];
    printf("Welcome to the happy spell checking program!\n");
    printf("Please enter a word that you would like to spell check: ");
    scanf("%s", word);
    happy_spell_check(word);
    return 0;
}