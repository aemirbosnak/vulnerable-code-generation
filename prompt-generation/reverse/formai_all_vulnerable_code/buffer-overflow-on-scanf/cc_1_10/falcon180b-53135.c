//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void init_word_counts(WordCount* counts) {
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        counts[i].count = 0;
        strcpy(counts[i].word, "");
    }
}

void update_word_count(WordCount* counts, char* word) {
    int index = 0;
    while (index < MAX_WORD_COUNT && strcmp(counts[index].word, word)!= 0) {
        index++;
    }
    if (index == MAX_WORD_COUNT) {
        printf("Max word count reached\n");
        exit(1);
    }
    counts[index].count++;
}

void print_word_counts(WordCount* counts) {
    int total_count = 0;
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (counts[i].count > 0) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
            total_count += counts[i].count;
        }
    }
    printf("Total word count: %d\n", total_count);
}

int main() {
    char input_file[100];
    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    WordCount counts[MAX_WORD_COUNT];
    init_word_counts(counts);

    char word[MAX_WORD_LENGTH];
    char c;
    int in_word = 0;
    while ((c = fgetc(input))!= EOF) {
        if (isalnum(c)) {
            in_word = 1;
            strncat(word, &c, 1);
        } else if (in_word) {
            in_word = 0;
            strcpy(word, "");
        }
    }
    if (in_word) {
        update_word_count(counts, word);
    }

    fclose(input);

    print_word_counts(counts);

    return 0;
}