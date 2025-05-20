//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initialize(char *filename, WordCount *word_counts, int num_word_counts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_word_counts) {
            strcpy(word_counts[i].word, word);
            word_counts[i].count = 1;
        }
    }
    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    int num_word_counts = 10;
    WordCount word_counts[num_word_counts];
    initialize(filename, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    return 0;
}