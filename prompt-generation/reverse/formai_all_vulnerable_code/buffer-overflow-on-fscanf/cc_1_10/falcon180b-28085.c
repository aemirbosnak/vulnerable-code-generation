//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts, int max_words) {
    char word[MAX_WORD_LENGTH];
    int word_index = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (word_index >= max_words) {
            break;
        }
        word_counts[word_index].word[0] = 0;
        strncat(word_counts[word_index].word, word, MAX_WORD_LENGTH - 1);
        word_counts[word_index].count = 1;
        word_index++;
    }
}

void count_words(WordCount* word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(word_counts[i].word, word_counts[j].word) == 0) {
                word_counts[i].count += word_counts[j].count;
                word_counts[j].word[0] = 0;
                word_counts[j].count = 0;
            }
        }
    }
}

void print_word_counts(WordCount* word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].word[0]!= 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    read_file(file, word_counts, MAX_WORDS);
    fclose(file);

    count_words(word_counts, num_words);

    printf("Word Counts:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}