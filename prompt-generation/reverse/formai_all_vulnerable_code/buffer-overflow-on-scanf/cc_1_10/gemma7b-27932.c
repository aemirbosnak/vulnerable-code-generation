//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char alienWord[MAX_WORD_LENGTH];
    int translation;
} AlienWord;

AlienWord alienWords[] =
{
    {"Blorgnak", 12},
    {"Zork", 14},
    {"Flork", 16},
    {"Zornak", 18}
};

int translateAlienWord(char *alienWord)
{
    for (int i = 0; i < sizeof(alienWords) / sizeof(AlienWord); i++)
    {
        if (strcmp(alienWords[i].alienWord, alienWord) == 0)
        {
            return alienWords[i].translation;
        }
    }

    return -1;
}

int main()
{
    char alienWord[MAX_WORD_LENGTH];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int translation = translateAlienWord(alienWord);

    if (translation == -1)
    {
        printf("Translation not found.\n");
    }
    else
    {
        printf("Translation: %d\n", translation);
    }

    return 0;
}