//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 100

struct word_count {
    char word[WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void count_words(FILE *file, struct word_count *word_counts, int num_words) {
    char word[WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= num_words) {
            printf("Reached maximum number of words.\n");
            break;
        }
        for (int j = 0; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
                break;
            }
        }
        strcpy(word_counts[i].word, word);
        word_counts[i].count++;
        i++;
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_words = 0;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));

    while (fscanf(file, "%s", filename)!= EOF) {
        num_words++;
    }

    rewind(file);
    count_words(file, word_counts, num_words);
    print_word_counts(word_counts, num_words);

    free(word_counts);
    fclose(file);

    return 0;
}