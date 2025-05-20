//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(const char* filename, WordCount* word_counts, int num_word_counts) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_word_counts) {
            if (num_word_counts >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                break;
            }
            strcpy(word_counts[num_word_counts].word, word);
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }
    }

    fclose(file);
}

void print_word_counts(WordCount* word_counts, int num_word_counts) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;

    read_file("example.txt", word_counts, num_word_counts);
    print_word_counts(word_counts, num_word_counts);

    return 0;
}