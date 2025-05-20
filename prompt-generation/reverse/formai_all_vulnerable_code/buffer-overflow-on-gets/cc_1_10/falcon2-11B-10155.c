//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char alien_word[100];
    char translation[100];
    char translated_word[100];

    printf("Enter an alien word to translate: ");
    gets(alien_word);

    int len = strlen(alien_word);

    for (int i = 0; i < len; i++) {
        if (isalpha(alien_word[i])) {
            if (isupper(alien_word[i])) {
                alien_word[i] = toupper(alien_word[i]);
            } else {
                alien_word[i] = tolower(alien_word[i]);
            }
        }
    }

    printf("Translated word: %s\n", alien_word);

    for (int i = 0; i < len; i++) {
        if (isalpha(alien_word[i])) {
            if (isupper(alien_word[i])) {
                alien_word[i] = toupper(alien_word[i]);
            } else {
                alien_word[i] = tolower(alien_word[i]);
            }
        }
    }

    printf("Translated word: %s\n", alien_word);

    for (int i = 0; i < len; i++) {
        if (isalpha(alien_word[i])) {
            if (isupper(alien_word[i])) {
                alien_word[i] = toupper(alien_word[i]);
            } else {
                alien_word[i] = tolower(alien_word[i]);
            }
        }
    }

    printf("Translated word: %s\n", alien_word);

    return 0;
}