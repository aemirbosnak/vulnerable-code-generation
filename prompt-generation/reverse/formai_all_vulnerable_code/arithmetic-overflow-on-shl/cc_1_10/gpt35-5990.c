//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

void countWords(char* text)
{
    int words[MAX_WORDS];
    char word[MAX_WORD_LEN];
    int wordIndex = 0;
    int wordCount = 0;
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            word[wordIndex++] = toupper(text[i]);
        }
        else if (wordIndex > 0)
        {
            word[wordIndex] = '\0';
            words[wordCount++] = hash(word);
            wordIndex = 0;
        }
    }

    if (wordIndex > 0)
    {
        word[wordIndex] = '\0';
        words[wordCount++] = hash(word);
    }

    printf("The number of distinct words in the text is %d\n", countDistinctWords(words, wordCount));
}

int hash(char* word)
{
    int hashVal = 0;
    int i;

    for (i = 0; word[i] != '\0'; i++)
    {
        hashVal = (hashVal << 5) + (word[i] - 'A' + 1);
    }

    return hashVal;
}

int countDistinctWords(int* words, int wordCount)
{
    int distinctWordCount = 0;
    int i, j;
    int isDistinct;

    for (i = 0; i < wordCount; i++)
    {
        isDistinct = 1;

        for (j = i + 1; j < wordCount; j++)
        {
            if (words[i] == words[j])
            {
                isDistinct = 0;
                break;
            }
        }

        if (isDistinct)
        {
            distinctWordCount++;
        }
    }

    return distinctWordCount;
}

int main()
{
    char text[] = "To Sherlock Holmes she is always THE woman. I have seldom heard him mention her under any other name. In his eyes she eclipses and predominates the whole of her sex. It was not that he felt any emotion akin to love for Irene Adler. All emotions, and that one particularly, were abhorrent to his cold, precise but admi-cally balanced mind.";

    countWords(text);

    return 0;
}