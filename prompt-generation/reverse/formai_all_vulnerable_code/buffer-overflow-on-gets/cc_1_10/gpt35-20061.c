//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[1000], word[100], replace[100], new_sentence[1000];
    int i, j, index = 0, replace_len, len;

    printf("Enter a sentence: ");
    gets(sentence);

    printf("Enter word to replace: ");
    gets(word);

    printf("Enter replacement word: ");
    gets(replace);

    len = strlen(sentence);
    replace_len = strlen(replace);

    for (i = 0; i < len; i++)
    {
        if (sentence[i] != ' ')
        {
            new_sentence[index++] = sentence[i];
        }
        else
        {
            new_sentence[index] = '\0'; // set end of word to null terminator
            if (strcmp(new_sentence, word) == 0) // check if the word matches
            {
                for (j = 0; j < replace_len; j++)
                {
                    printf("%c", replace[j]);
                }
                index = 0; // reset index for new word
            }
            else
            {
                printf("%s ", new_sentence);
                index = 0;
            }
        }
    }
    // print last word since loop ends before printing last word
    new_sentence[index] = '\0';
    if (strcmp(new_sentence, word) == 0)
    {
        for (j = 0; j < replace_len; j++)
        {
            printf("%c", replace[j]);
        }
    }
    else
    {
        printf("%s", new_sentence);
    }
    return 0;
}