//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
    char alienWord[20];
    char englishWord[20];
} AlienWord;

AlienWord alienWords[MAX_WORDS] =
{
    {"Tr'bl'z", "Thunder"},
    {"Fl'z", "Light"},
    {"Sk'z", "Sky"},
    {"Gn'z", "Green"},
    {"St'p", "Stop"},
    {"H'r'k", "Hard"},
    {"R'z", "Run"},
    {"P'c'k", "Pack"},
    {"S'p'n", "Spin"},
    {"L'h't", "Light"}
};

int translateAlienWord(char *alienWord)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(alienWord, alienWords[i].alienWord) == 0)
        {
            return alienWords[i].englishWord;
        }
    }

    return -1;
}

int main()
{
    char alienWord[20];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int translation = translateAlienWord(alienWord);

    if (translation != -1)
    {
        printf("English translation: %s\n", translation);
    }
    else
    {
        printf("No translation found.\n");
    }

    return 0;
}