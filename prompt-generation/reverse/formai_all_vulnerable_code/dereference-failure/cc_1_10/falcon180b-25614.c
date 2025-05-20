//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word_a = (struct word_count *)a;
    struct word_count *word_b = (struct word_count *)b;

    return strcmp(word_a->word, word_b->word);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(word, token);
            struct word_count *existing_word = NULL;

            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    existing_word = &word_counts[i];
                    break;
                }
            }

            if (existing_word == NULL) {
                if (num_words >= MAX_WORDS) {
                    printf("Reached maximum number of words.\n");
                    break;
                }

                strcpy(existing_word->word, word);
                existing_word->count = 1;
                num_words++;
            } else {
                existing_word->count++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}