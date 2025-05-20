//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// Structure to store words
typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} Word;

// Function to load words from file
void load_words(Word* words) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", words[num_words].word, words[num_words].translation) == 2) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Too many words\n");
            exit(1);
        }
    }

    fclose(file);
}

// Function to translate sentence
void translate_sentence(Word* words, char* sentence) {
    char* tokens = strtok(sentence, " ");
    while (tokens!= NULL) {
        Word* word = NULL;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, tokens) == 0) {
                word = &words[i];
                break;
            }
        }

        if (word == NULL) {
            printf("Unknown word: %s\n", tokens);
        } else {
            printf("%s ", word->translation);
        }

        tokens = strtok(NULL, " ");
    }
}

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(words, sentence);

    return 0;
}