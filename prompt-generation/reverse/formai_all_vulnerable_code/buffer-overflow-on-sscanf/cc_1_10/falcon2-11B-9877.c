//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

struct Word {
    char word[MAX_LENGTH];
    int count;
};

struct Language {
    struct Word words[MAX_WORDS];
    int num_words;
};

struct Language alien_language;

void read_alien_language() {
    char word[MAX_LENGTH];
    int word_count;

    printf("Enter the words of the alien language: ");

    while (1) {
        fgets(word, MAX_LENGTH, stdin);
        word_count = sscanf(word, "%s", word);

        if (word_count == 1) {
            break;
        }

        if (word_count < 1 || word_count > MAX_WORDS) {
            fprintf(stderr, "Invalid number of words.\n");
            exit(1);
        }

        alien_language.num_words++;
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        memset(alien_language.words[i].word, 0, MAX_LENGTH);
        alien_language.words[i].count = 0;
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        alien_language.words[i].word[0] = word[i];
        alien_language.words[i].count++;
    }
}

void translate_alien_language(struct Language *language, char *phrase) {
    struct Word *word = language->words;
    int word_count = language->num_words;
    int phrase_len = strlen(phrase);
    char translated_phrase[phrase_len + 1];

    for (int i = 0; i < phrase_len; i++) {
        translated_phrase[i] = phrase[i];

        for (int j = 0; j < word_count; j++) {
            if (strcmp(word[j].word, phrase[i]) == 0) {
                translated_phrase[i] = word[j].word[0];
                break;
            }
        }
    }

    translated_phrase[phrase_len] = '\0';
    printf("%s\n", translated_phrase);
}

int main() {
    read_alien_language();

    char phrase[100];
    printf("Enter a phrase to translate: ");
    fgets(phrase, 100, stdin);

    translate_alien_language(&alien_language, phrase);

    return 0;
}