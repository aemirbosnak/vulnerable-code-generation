//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct AlienLanguageTranslation
{
    char alienWord[MAX_BUFFER_SIZE];
    char humanWord[MAX_BUFFER_SIZE];
} AlienLanguageTranslation;

AlienLanguageTranslation translations[] =
{
    {"Gr'bl'zt", "Hello"},
    {"Th'znk", "Thank you"},
    {"Fl'kr", "No problem"},
    {"R'k'l", "Yes"},
    {"Tr'k'k", "Goodbye"}
};

int translateAlienLanguage(char *alienWord)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(alienWord, translations[i].alienWord) == 0)
        {
            return translations[i].humanWord;
        }
    }

    return -1;
}

int main()
{
    char alienWord[MAX_BUFFER_SIZE];

    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int translation = translateAlienLanguage(alienWord);

    if (translation != -1)
    {
        printf("The translation is: %s\n", translation);
    }
    else
    {
        printf("No translation found.\n");
    }

    return 0;
}