//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define NUM_ALIEN_WORDS 10
#define ALIEN_WORD_LENGTH 4

typedef struct {
    char alien_word[ALIEN_WORD_LENGTH + 1];
    char human_word[MAX_WORD_LENGTH + 1];
} Translation;

Translation translations[NUM_ALIEN_WORDS] = {
    {"blargh", "hello"},
    {"grkpl", "goodbye"},
    {"xaxxo", "water"},
    {"quux", "house"},
    {"plonk", "apple"},
    {"bleh", "cat"},
    {"zork", "dog"},
    {"quuxx", "car"},
    {"xaxxax", "tree"},
    {"blarghblargh", "I love you"}
};

int find_translation(char alien_word[], Translation translations[]) {
    int i;
    for (i = 0; i < NUM_ALIEN_WORDS; i++) {
        if (strcmp(translations[i].alien_word, alien_word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char alien_word[ALIEN_WORD_LENGTH + 1];
    int i;

    while (1) {
        printf("Enter an alien word: ");
        scanf("%s", alien_word);

        i = find_translation(alien_word, translations);
        if (i >= 0) {
            printf("The human translation for %s is %s.\n", alien_word, translations[i].human_word);
        } else {
            printf("Unknown alien word.\n");
        }
    }

    return 0;
}