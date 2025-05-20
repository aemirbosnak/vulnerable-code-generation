//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int count) {
    char word[MAX_WORD_LENGTH];
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        if (count >= MAX_WORD_COUNT) {
            break;
        }

        int j;
        for (j = 0; j < count; j++) {
            if (strcmp(word, word_counts[j].word) == 0) {
                word_counts[j].count++;
                break;
            }
        }

        if (j == count) {
            strcpy(word_counts[count].word, word);
            word_counts[count].count = 1;
            count++;
        }
    }
}

void print_word_counts(WordCount *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORD_COUNT];
    int count = 0;

    read_file(file, word_counts, count);

    print_word_counts(word_counts, count);

    fclose(file);

    return 0;
}