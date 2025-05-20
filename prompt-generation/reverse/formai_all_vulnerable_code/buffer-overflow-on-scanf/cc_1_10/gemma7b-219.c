//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char word[MAX_WORD_LENGTH];
    int translations[5];
} AlienWord;

AlienWord alienWords[] =
{
    {"Blorg", {1, 2, 3, 4, 5}},
    {"Flork", {2, 4, 6, 8, 10}},
    {"Zork", {3, 5, 7, 9, 11}},
    {"Korb", {4, 6, 8, 10, 12}},
    {"Narb", {5, 7, 9, 11, 13}}
};

int alienWordTranslate(char *word)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(word, alienWords[i].word) == 0)
        {
            return alienWords[i].translations[0];
        }
    }

    return -1;
}

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter an alien word: ");
    scanf("%s", word);

    int translation = alienWordTranslate(word);

    if (translation != -1)
    {
        printf("Translation: %d", translation);
    }
    else
    {
        printf("Word not found.");
    }

    return 0;
}