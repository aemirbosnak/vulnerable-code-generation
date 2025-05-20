//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

char alien_words[MAX_WORDS][20] = {
    "Tr'x'zt!",
    "Zork'zork!",
    "Fl'ubbl!",
    "Bar'n'bar!",
    "Blork!",
    "Zork!",
    "Gork'gork!",
    "Tr'x'zt't!",
    "Zork'zork'zork!",
    "Fl'ubbl'fl'ubbl!"
};

int alien_language_translate(char *word)
{
    int i = 0;
    for (i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(word, alien_words[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char word[20];

    printf("Enter an alien word: ");
    scanf("%s", word);

    int translation = alien_language_translate(word);

    if (translation == -1)
    {
        printf("Word not found.\n");
    }
    else
    {
        printf("Translation: %s\n", alien_words[translation]);
    }

    return 0;
}