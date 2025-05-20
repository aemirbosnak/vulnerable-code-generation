//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_word(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

void read_words(FILE *file, char *filename, WordCount *word_counts, int *word_count) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > 0 && isalpha(word[0])) {
            strcpy(word_counts[*word_count].word, word);
            word_counts[*word_count].count = 1;
            (*word_count)++;
        }
    }
    fclose(file);
}

void print_word_count(WordCount *word_counts, int word_count) {
    qsort(word_counts, word_count, sizeof(WordCount), compare_word);
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    WordCount word_counts[MAX_WORD_LENGTH];
    int word_count = 0;

    read_words(file, filename, word_counts, &word_count);

    printf("Word count for %s:\n", filename);
    print_word_count(word_counts, word_count);

    return 0;
}