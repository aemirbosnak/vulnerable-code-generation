//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

void initialize_word_count(WordCount *word_count, char *word) {
    word_count->word = word;
    word_count->count = 0;
}

int compare_word_counts(const void *a, const void *b) {
    WordCount *word_count_a = (WordCount *)a;
    WordCount *word_count_b = (WordCount *)b;

    return strcmp(word_count_a->word, word_count_b->word);
}

void print_word_counts(WordCount *word_counts, int count) {
    qsort(word_counts, count, sizeof(WordCount), compare_word_counts);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordCount word_counts[1000];
    int word_count_index = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        initialize_word_count(&word_counts[word_count_index], word);
        word_count_index++;
    }

    fclose(file);

    for (int i = 0; i < word_count_index; i++) {
        word_counts[i].count++;
    }

    print_word_counts(word_counts, word_count_index);

    return 0;
}