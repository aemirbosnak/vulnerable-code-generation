//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALIEN_DICTIONARY_SIZE 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_t;

typedef struct {
    word_t words[MAX_WORDS];
    int num_words;
} dictionary_t;

void load_dictionary(dictionary_t* dict) {
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", line)!= EOF) {
        word_t word = {.english = line,.alien = "" };
        dict->words[dict->num_words++] = word;
    }

    fclose(fp);
}

void generate_alien_word(char* english_word, char* alien_word) {
    int len = strlen(english_word);
    int i;
    for (i = 0; i < len; i++) {
        char c = tolower(english_word[i]);
        if (isalpha(c)) {
            alien_word[i] = c + rand() % 26;
        } else {
            alien_word[i] = c;
        }
    }
    alien_word[len] = '\0';
}

int main() {
    srand(time(NULL));
    dictionary_t dict;
    load_dictionary(&dict);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter an English word: ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        word_t* word = NULL;
        int i;
        for (i = 0; i < dict.num_words; i++) {
            if (strcmp(dict.words[i].english, input) == 0) {
                word = &dict.words[i];
                break;
            }
        }

        if (word == NULL) {
            printf("Unknown word.\n");
        } else {
            char alien_word[MAX_WORD_LENGTH];
            generate_alien_word(word->english, alien_word);
            printf("Alien translation: %s\n", alien_word);
        }
    }

    return 0;
}