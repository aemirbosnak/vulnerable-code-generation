//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word words[MAX_WORDS];

void addWord(char *word)
{
    int i = 0;
    for (; i < MAX_WORDS && words[i].word != NULL; i++)
    {
        ;
    }

    words[i].word = strdup(word);
    words[i].frequency = 1;
}

void increaseWordFrequency(char *word)
{
    int i = 0;
    for (; i < MAX_WORDS && words[i].word != NULL; i++)
    {
        if (strcmp(words[i].word, word) == 0)
        {
            words[i].frequency++;
            return;
        }
    }

    addWord(word);
}

int main()
{
    clock_t start, end;
    char text[10000];

    printf("Type a text below:\n");
    fgets(text, 10000, stdin);

    start = clock();

    increaseWordFrequency(text);

    end = clock();

    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Most frequent words:\n");
    for (int i = 0; i < MAX_WORDS && words[i].word != NULL; i++)
    {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}