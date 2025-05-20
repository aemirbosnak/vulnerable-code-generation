//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define ALIEN_LANGUAGE_LEN 4
#define ENGLISH_ALPHABET_LEN 26

typedef struct {
    char alien_char[ALIEN_LANGUAGE_LEN + 1];
    char english_char;
} Translation;

Translation dictionary[ENGLISH_ALPHABET_LEN] = {
    {"abcd", 'A'},
    {"bcdea", 'B'},
    {"cdeab", 'C'},
    {"deabc", 'D'},
    {"eabcd", 'E'},
    // ...
};

void translate(char* alien_word, char* english_word) {
    int i, j, k;
    int alien_word_len = strlen(alien_word);
    int found = 0;

    for (i = 0; i < ENGLISH_ALPHABET_LEN; i++) {
        for (j = 0; j < ALIEN_LANGUAGE_LEN; j++) {
            found = 0;
            for (k = 0; k < alien_word_len; k++) {
                if (dictionary[i].alien_char[j] == alien_word[k]) {
                    found++;
                } else {
                    found = 0;
                    break;
                }
            }
            if (found == alien_word_len) {
                *english_word = dictionary[i].english_char;
                return;
            }
        }
    }

    *english_word = '\0';
}

int main() {
    char alien_word[ALIEN_LANGUAGE_LEN + 1];
    char english_word[2]; // We only need space for one character and a null terminator

    printf("Enter an alien word to translate: ");
    scanf("%s", alien_word);

    translate(alien_word, english_word);

    if (*english_word == '\0') {
        printf("Could not translate word: %s\n", alien_word);
    } else {
        printf("Translated: %s -> %c\n", alien_word, *english_word);
    }

    return 0;
}