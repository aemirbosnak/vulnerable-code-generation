//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} word_count_t;

void add_word(word_count_t *word_counts, int num_words, char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    word_count_t new_word_count = {word, 1};
    word_counts = realloc(word_counts, sizeof(word_count_t) * (num_words + 1));
    if (word_counts == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    word_counts[num_words] = new_word_count;
    num_words++;
}

void print_word_counts(word_count_t *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    char word[MAX_WORD_LENGTH];
    word_count_t word_counts[MAX_WORDS];
    int num_words = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            fclose(file);
            return 1;
        }
        word[strcspn(word, ".,?!;:")] = '\0';
        add_word(word_counts, num_words, word);
        num_words++;
    }
    fclose(file);
    print_word_counts(word_counts, num_words);
    return 0;
}