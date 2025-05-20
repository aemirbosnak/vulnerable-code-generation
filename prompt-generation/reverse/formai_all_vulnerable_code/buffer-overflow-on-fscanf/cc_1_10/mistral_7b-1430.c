//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define ALIEN_CONSONANTS "bcdfghjklmnpqrstvwxyz"
#define ALIEN_VOWELS "aeiou"

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
} Word;

void translate_word(const char *english_word) {
    int i;
    for (i = 0; english_word[i]; i++) {
        if (isalpha(english_word[i])) {
            if (strchr(ALIEN_VOWELS, tolower(english_word[i]))) {
                putchar('z');
            } else {
                putchar('x');
            }
        } else {
            putchar(english_word[i]);
        }
    }
    putchar('\n');
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int num_words = 0;

    file = fopen("english_words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file 'english_words.txt'\n");
        return 1;
    }

    while (fscanf(file, "%s", words[num_words].word) != EOF) {
        num_words++;
    }

    fclose(file);

    for (int i = 0; i < num_words; i++) {
        printf("English: %s\n", words[i].word);
        translate_word(words[i].word);
        printf("Alien: ");
    }

    return 0;
}