//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 100
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int count;
} WordCount;

void read_file(const char* filename, WordCount* word_counts, int num_word_counts) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        char* word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            int word_len = strlen(word);
            if (word_len <= WORD_LEN) {
                for (int i = 0; i < num_word_counts; i++) {
                    if (strcmp(word_counts[i].word, word) == 0) {
                        word_counts[i].count++;
                        break;
                    }
                }
            }
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(fp);
}

void print_word_counts(WordCount* word_counts, int num_word_counts) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;

    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename, word_counts, num_word_counts);
    print_word_counts(word_counts, num_word_counts);

    return 0;
}