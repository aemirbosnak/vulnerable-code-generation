//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR_PER_WORD 20

typedef struct Word
{
    char characters[MAX_CHAR_PER_WORD];
    int length;
} Word;

Word words[MAX_WORDS];

void initializeWords()
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i].length = 0;
    }
}

void addWord(char *word)
{
    Word *wordPtr = &words[words[MAX_WORDS - 1].length];

    wordPtr->length = words[MAX_WORDS - 1].length + 1;

    for (int i = 0; i < MAX_CHAR_PER_WORD && word[i] != '\0'; i++)
    {
        wordPtr->characters[i] = word[i];
    }

    words[MAX_WORDS - 1].length++;
}

int main()
{
    initializeWords();

    char word[MAX_CHAR_PER_WORD];

    printf("Enter a word: ");
    scanf("%s", word);

    addWord(word);

    printf("Word added: %s\n", words[words[MAX_WORDS - 1].length - 1].characters);

    return 0;
}