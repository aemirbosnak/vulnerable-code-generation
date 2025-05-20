//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100], newSentence[100];
    int i, j, k, length, vowelsCount = 0;
    printf("Enter a sentence in C Alien Language: ");
    gets(sentence);

    length = strlen(sentence);

    for (i = 0, j = 0; i < length; i++)
    {
        if (sentence[i] == 'C' || sentence[i] == 'S')
        {
            newSentence[j] = 'K';
            j++;
        }
        else if (sentence[i] == 'I')
        {
            newSentence[j] = 'E';
            j++;
        }
        else if (sentence[i] == 'E')
        {
            newSentence[j] = 'I';
            j++;
        }
        else if (sentence[i] == 'R')
        {
            newSentence[j] = 'L';
            j++;
        }
        else if (sentence[i] == 'O' || sentence[i] == 'U')
        {
            newSentence[j] = sentence[i];
            j++;
            vowelsCount++;
        }
        else
        {
            newSentence[j] = sentence[i];
            j++;
        }
    }
    newSentence[j] = '\0';

    printf("\nTranslated sentence in English: %s", newSentence);
    printf("\nTotal number of vowels in the sentence: %d", vowelsCount);

    return 0;
}