//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define ALIEN_LANGUAGE_DICTIONARY_SIZE 20

typedef struct AlienLanguageWord
{
    char alienWord[20];
    char englishWord[20];
} AlienLanguageWord;

AlienLanguageWord alienLanguageDictionary[ALIEN_LANGUAGE_DICTIONARY_SIZE] =
{
    {"Tr'nth'k", "Thank you"},
    {"Zork'k", "Yes"},
    {"Fl'nd", "No"},
    {"Sk't", "Happy"},
    {"Bl'th", "Sad"},
    {"Zarg", "Beautiful"},
    {"Bar'k", "Ugly"},
    {"Th'ng", "Strong"},
    {"Tr'ng", "Weak"},
    {"X'zt", "Good"},
    {"R'k", "Bad"},
    {"S'k", "Easy"},
    {"Q'l", "Difficult"},
    {"Fl'w", "Love"},
    {"Tr'w", "Hate"},
    {"M'n", "Peace"},
    {"R'h", "War"},
    {"S'h", "Death"},
    {"Th'h", "Life"}
};

int alienLanguageTranslate(char *alienWord)
{
    int i = 0;
    for (i = 0; i < ALIEN_LANGUAGE_DICTIONARY_SIZE; i++)
    {
        if (strcmp(alienWord, alienLanguageDictionary[i].alienWord) == 0)
        {
            return alienLanguageDictionary[i].englishWord;
        }
    }

    return -1;
}

int main()
{
    char alienWord[20];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int translation = alienLanguageTranslate(alienWord);

    if (translation != -1)
    {
        printf("Translation: %s\n", translation);
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}