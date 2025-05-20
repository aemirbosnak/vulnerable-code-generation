//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char *word;
    int translation;
} AlienWord;

AlienWord alienWords[1000];

int translateWord(char *word)
{
    for (int i = 0; i < 1000; i++)
    {
        if (strcmp(word, alienWords[i].word) == 0)
        {
            return alienWords[i].translation;
        }
    }

    return -1;
}

int main()
{
    // Load alien words and translations
    alienWords[0].word = "Blorg";
    alienWords[0].translation = 10;

    alienWords[1].word = "Zork";
    alienWords[1].translation = 20;

    // Get the word to translate
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    // Translate the word
    int translation = translateWord(word);

    // Print the translation
    if (translation != -1)
    {
        printf("Translation: %d\n", translation);
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}