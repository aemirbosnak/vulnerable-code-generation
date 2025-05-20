//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define ALPHABET_SIZE 26

typedef struct {
    char word[MAX_LENGTH];
    char translation[MAX_LENGTH];
} alien_language;

void translate_alien_language(alien_language* language) {
    int i, j;
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char translation_table[ALPHABET_SIZE][ALPHABET_SIZE] = {
        {'a', 'z'},
        {'b', 'y'},
        {'c', 'x'},
        {'d', 'w'},
        {'e', 'v'},
        {'f', 'u'},
        {'g', 't'},
        {'h','s'},
        {'i', 'r'},
        {'j', 'q'},
        {'k', 'p'},
        {'l', 'o'},
        {'m', 'n'},
        {'n','m'},
        {'o', 'l'},
        {'p', 'k'},
        {'q', 'j'},
        {'r', 'i'},
        {'s', 'h'},
        {'t', 'g'},
        {'u', 'f'},
        {'v', 'e'},
        {'w', 'd'},
        {'x', 'c'},
        {'y', 'b'},
        {'z', 'a'}
    };

    for (i = 0; i < ALPHABET_SIZE; i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            printf("%c ", translation_table[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_LENGTH; i++) {
        language->translation[i] = language->word[i] + 2;
    }

    for (i = 0; i < MAX_LENGTH; i++) {
        if (language->translation[i] > 'z') {
            language->translation[i] = language->translation[i] - ALPHABET_SIZE + 'a';
        }
    }

    for (i = 0; i < MAX_LENGTH; i++) {
        if (language->translation[i] > 'z') {
            language->translation[i] = language->translation[i] - ALPHABET_SIZE + 'a';
        }
    }

    for (i = 0; i < MAX_LENGTH; i++) {
        printf("%c ", language->translation[i]);
    }
    printf("\n");
}

int main() {
    alien_language language;
    char word[MAX_LENGTH];
    char translation[MAX_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Original word: %s\n", word);

    strcpy(language.word, word);
    translate_alien_language(&language);

    strcpy(translation, language.translation);

    printf("Translated word: %s\n", translation);

    return 0;
}