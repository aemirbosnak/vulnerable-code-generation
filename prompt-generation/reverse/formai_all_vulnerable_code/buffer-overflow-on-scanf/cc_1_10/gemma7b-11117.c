//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienWord {
    char *word;
    int translation;
} AlienWord;

AlienWord alienWords[MAX_WORDS];

void translateAlien(char *alienWord)
{
    int i = 0;
    for (i = 0; i < MAX_WORDS && alienWords[i].word != NULL; i++)
    {
        if (strcmp(alienWord, alienWords[i].word) == 0)
        {
            printf("Translation: %d\n", alienWords[i].translation);
            break;
        }
    }

    if (i == MAX_WORDS)
    {
        printf("Word not found.\n");
    }
}

int main()
{
    alienWords[0].word = "Blorg";
    alienWords[0].translation = 12;

    alienWords[1].word = "Zork";
    alienWords[1].translation = 14;

    alienWords[2].word = "Quork";
    alienWords[2].translation = 16;

    char alienWord[20];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    translateAlien(alienWord);

    return 0;
}