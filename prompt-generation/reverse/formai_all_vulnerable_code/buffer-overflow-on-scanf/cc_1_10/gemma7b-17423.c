//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AlienWord
{
    char alienWord[20];
    int meaning;
} AlienWord;

AlienWord alienWords[] = {
    {"Zork", 10},
    {"Blork", 20},
    {"Flork", 30},
    {"Zor", 40},
    {"Bargl", 50},
    {"Zarg", 60}
};

int translateAlienWord(char *alienWord)
{
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(alienWord, alienWords[i].alienWord) == 0)
        {
            return alienWords[i].meaning;
        }
    }

    return -1;
}

int main()
{
    char alienWord[20];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int meaning = translateAlienWord(alienWord);

    if (meaning == -1)
    {
        printf("Word not found.\n");
    }
    else
    {
        printf("Meaning: %d\n", meaning);
    }

    return 0;
}