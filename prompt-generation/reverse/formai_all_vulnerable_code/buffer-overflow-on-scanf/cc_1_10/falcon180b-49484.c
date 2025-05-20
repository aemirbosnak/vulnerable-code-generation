//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int max_words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < max_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == max_words) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_file(file, word_counts, MAX_WORDS);
    num_words = num_words + 1;

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}