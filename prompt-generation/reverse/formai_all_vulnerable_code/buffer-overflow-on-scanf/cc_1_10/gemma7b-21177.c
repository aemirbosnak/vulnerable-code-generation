//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void analyze_word(char *word)
{
    int word_length = strlen(word);
    for (int i = 0; i < word_length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }

    int frequency[MAX_WORD_LENGTH] = {0};
    for (int i = 0; i < word_length; i++)
    {
        frequency[word[i]]++;
    }

    int flag = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (frequency[i] > 1)
        {
            flag = 1;
        }
    }

    if (flag)
    {
        printf("Spam detected!\n");
    }
    else
    {
        printf("Not spam.\n");
    }
}

int main()
{
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    analyze_word(word);

    return 0;
}