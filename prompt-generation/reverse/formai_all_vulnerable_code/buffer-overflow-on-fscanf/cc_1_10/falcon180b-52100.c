//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount *word_counts) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    while (fscanf(fp, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            word[word_length - 1] = '\0'; // add null terminator to the end of the word
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                } else if (strcmp(word_counts[i].word, "") == 0) {
                    strcpy(word_counts[i].word, word);
                    word_counts[i].count = 1;
                    break;
                }
            }
        }
    }
}

void print_word_counts(WordCount *word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word_counts[i].word, "")!= 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    WordCount word_counts[MAX_WORDS];
    memset(word_counts, 0, sizeof(word_counts));

    read_file(fp, word_counts);

    fclose(fp);

    print_word_counts(word_counts);

    return 0;
}