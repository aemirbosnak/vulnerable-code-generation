//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANG_LEN 100
#define EARTH_LANG_LEN 100

char alien_lang[ALIEN_LANG_LEN];
char earth_lang[EARTH_LANG_LEN];
int alien_lang_len = 0;
int earth_lang_len = 0;
int translation_table[256];

int main()
{
    // Get the alien language string
    printf("Enter the alien language string: ");
    scanf("%s", alien_lang);
    alien_lang_len = strlen(alien_lang);

    // Get the earth language string
    printf("Enter the earth language string: ");
    scanf("%s", earth_lang);
    earth_lang_len = strlen(earth_lang);

    // Create the translation table
    for (int i = 0; i < 256; i++)
    {
        translation_table[i] = -1;
    }

    // Populate the translation table
    for (int i = 0; i < alien_lang_len; i++)
    {
        char alien_char = alien_lang[i];
        char earth_char = earth_lang[i];
        translation_table[(int)alien_char] = (int)earth_char;
    }

    // Translate the alien language string
    char translated_string[ALIEN_LANG_LEN];
    for (int i = 0; i < alien_lang_len; i++)
    {
        char alien_char = alien_lang[i];
        char earth_char = (char)translation_table[(int)alien_char];
        translated_string[i] = earth_char;
    }

    // Print the translated string
    printf("Translated string: %s\n", translated_string);

    return 0;
}