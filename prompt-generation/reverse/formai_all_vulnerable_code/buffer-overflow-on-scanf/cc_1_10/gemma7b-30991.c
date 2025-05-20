//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word
{
    char word[20];
    int frequency;
} Word;

Word words[MAX_WORDS];

void initializeWords()
{
    int i = 0;
    for (i = 0; i < MAX_WORDS; i++)
    {
        words[i].word[0] = '\0';
        words[i].frequency = 0;
    }
}

void addWord(char *word)
{
    int i = 0;
    for (i = 0; i < MAX_WORDS; i++)
    {
        if (words[i].word[0] == '\0')
        {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            return;
        }
        else if (strcmp(words[i].word, word) == 0)
        {
            words[i].frequency++;
            return;
        }
    }

    // If no space, allocate new memory
    printf("Error: Word list full!\n");
}

int main()
{
    initializeWords();

    char input[20];
    printf("Enter a word: ");
    scanf("%s", input);

    addWord(input);

    printf("Word added: %s, frequency: %d\n", words[0].word, words[0].frequency);

    return 0;
}