//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANGUAGE_MAGIC_NUMBER 42

typedef struct AlienLanguageWord
{
    char alien_word[20];
    int translation_number;
} AlienLanguageWord;

AlienLanguageWord alien_language_words[] =
{
    {"Blorg", 12},
    {"Zork", 4},
    {"Korb", 18},
    {"Zarg", 23},
    {"Blorkz", 21},
    {"Zorkz", 42}
};

int alien_language_translate(char *alien_word)
{
    for (int i = 0; i < sizeof(alien_language_words) / sizeof(AlienLanguageWord); i++)
    {
        if (strcmp(alien_language_words[i].alien_word, alien_word) == 0)
        {
            return alien_language_words[i].translation_number;
        }
    }

    return -1;
}

int main()
{
    char alien_word[20];

    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    int translation_number = alien_language_translate(alien_word);

    if (translation_number != -1)
    {
        printf("Translation: %d\n", translation_number);
    }
    else
    {
        printf("Error: alien word not found.\n");
    }

    return 0;
}