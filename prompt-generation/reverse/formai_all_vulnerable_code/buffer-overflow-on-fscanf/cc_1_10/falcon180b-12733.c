//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_word_counts) {
    char word[MAX_WORD_LENGTH];
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = tolower(ch);
            int j = 1;

            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    word[j++] = tolower(ch);
                }
            }

            word[j] = '\0';

            for (int k = 0; k < num_word_counts; k++) {
                if (strcmp(word, word_counts[k].word) == 0) {
                    word_counts[k].count++;
                    break;
                }
            }
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_word_counts = 0;
    WordCount word_counts[MAX_WORDS];

    while (num_word_counts < MAX_WORDS && fscanf(file, "%s", word_counts[num_word_counts].word)!= EOF) {
        num_word_counts++;
    }

    fclose(file);

    read_file(file, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    return 0;
}