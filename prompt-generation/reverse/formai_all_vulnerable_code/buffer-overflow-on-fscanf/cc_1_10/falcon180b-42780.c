//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void load_words(char *filename, WordFrequency *words, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    char *word = NULL;
    int word_length = 0;
    int i = 0;

    while (fscanf(file, "%s", line)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        word = strdup(line);
        word_length = strlen(word);

        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: word '%s' is too long\n", word);
            exit(1);
        }

        words[i].word = word;
        words[i].frequency = 1;
        i++;
    }

    fclose(file);

    *num_words = i;
}

void generate_sentence(WordFrequency *words, int num_words, int seed) {
    srand(seed);

    int current_word = rand() % num_words;
    char *sentence = strdup(words[current_word].word);

    for (int i = 1; i < 10; i++) {
        int next_word = rand() % num_words;

        while (next_word == current_word) {
            next_word = rand() % num_words;
        }

        char *next_word_lower = strdup(words[next_word].word);
        strcat(sentence, " ");
        strcat(sentence, next_word_lower);

        free(next_word_lower);

        current_word = next_word;
    }

    printf("%s\n", sentence);
    free(sentence);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <seed>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int seed = atoi(argv[2]);

    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    load_words(filename, words, &num_words);

    for (int i = 0; i < 10; i++) {
        generate_sentence(words, num_words, seed + i);
    }

    return 0;
}