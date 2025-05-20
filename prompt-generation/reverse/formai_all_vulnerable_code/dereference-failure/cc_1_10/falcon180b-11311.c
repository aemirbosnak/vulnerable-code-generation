//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 10000
#define MAX_FILE_LEN 1000000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char c;
    WordCount *word_counts = (WordCount *) malloc(MAX_WORD_COUNT * sizeof(WordCount));
    int num_words = 0;

    while ((c = fgetc(fp))!= EOF) {
        if (isalpha(c)) {
            int len = 0;
            char *word = (char *) malloc(MAX_WORD_LEN * sizeof(char));

            while (isalpha(c)) {
                word[len++] = tolower(c);
                c = fgetc(fp);
            }

            word[len] = '\0';

            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                num_words++;
                word_counts[i].count = 1;
                strcpy(word_counts[i].word, word);
            }

            free(word);
        }
    }

    fclose(fp);

    printf("Total number of words: %d\n", num_words);
}

void display_word_counts(WordCount *word_counts, int num_words) {
    printf("Word\t\tCount\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(fp, argv[1]);

    fclose(fp);

    return 0;
}