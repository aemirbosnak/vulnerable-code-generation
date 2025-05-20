//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount *word_counts) {
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int in_word = 0;

    while ((fscanf(fp, "%c", &word[word_length]))!= EOF) {
        if (isalnum(word[word_length])) {
            in_word = 1;
            word_length++;
        } else if (in_word) {
            word[word_length] = '\0';
            in_word = 0;
            if (strlen(word) > 0) {
                int i;
                for (i = 0; i < MAX_WORDS; i++) {
                    if (strcmp(word_counts[i].word, word) == 0) {
                        word_counts[i].count++;
                        break;
                    }
                }
                if (i == MAX_WORDS) {
                    printf("Warning: Maximum number of words reached.\n");
                }
            }
        }
    }
}

void write_word_counts(WordCount *word_counts) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word_counts[i].word, "")!= 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    WordCount word_counts[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    memset(word_counts, 0, sizeof(word_counts));
    read_file(fp, word_counts);

    fclose(fp);

    write_word_counts(word_counts);

    return 0;
}