//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", dictionary[num_words].word) != EOF) {
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(fp);
}

int compare_words(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

void spell_check(char *text) {
    char *token = strtok(text, " ");
    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                dictionary[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s not found in dictionary.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

void print_results() {
    qsort(dictionary, num_words, sizeof(Word), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
}

int main() {
    load_dictionary();

    char text[] = "The quick brown fox jumps over the lazy dog.";

    spell_check(text);

    print_results();

    return EXIT_SUCCESS;
}