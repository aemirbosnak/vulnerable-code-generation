//Falcon-180B DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(FILE *file, WordCount *word_counts) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Reached maximum number of words.\n");
            exit(1);
        }
    }
}

void print_word_counts(WordCount *word_counts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    WordCount word_counts[MAX_WORDS];
    read_words(file, word_counts);
    fclose(file);
    printf("Word counts:\n");
    print_word_counts(word_counts);
    return 0;
}