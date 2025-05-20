//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
    char *word;
    int translation;
} AlienWord;

AlienWord alienWords[MAX_WORDS];

void translateAlienWord(char *alienWord)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(alienWord, alienWords[i].word) == 0)
        {
            printf("%s", alienWords[i].translation);
            break;
        }
    }
}

int main()
{
    // Populate the alien words array
    alienWords[0].word = "Tr'zk'zh";
    alienWords[0].translation = 10;

    alienWords[1].word = "Z'x'yl";
    alienWords[1].translation = 20;

    alienWords[2].word = "Q'br'x";
    alienWords[2].translation = 30;

    // Get the alien word to translate
    char alienWord[20];
    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    // Translate the alien word
    translateAlienWord(alienWord);

    printf("\n");

    return 0;
}