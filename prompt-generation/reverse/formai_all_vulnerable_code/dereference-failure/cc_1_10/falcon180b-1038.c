//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORDS_PER_LINE 10

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORDS_PER_LINE];
    int num_words = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int word_index = 0;
        char *word_start = line;

        while (isspace(*word_start)) {
            word_start++;
        }

        while (!isspace(*word_start) && word_index < MAX_WORDS_PER_LINE) {
            char *word_end = word_start;

            while (!isspace(*word_end) && word_end - word_start < MAX_WORD_LENGTH) {
                word_end++;
            }

            if (word_end - word_start > 0) {
                word_counts[word_index].word = malloc(word_end - word_start + 1);
                strncpy(word_counts[word_index].word, word_start, word_end - word_start);
                word_counts[word_index].word[word_end - word_start] = '\0';
                word_counts[word_index].count = 1;
                word_index++;
            }

            word_start = word_end;
        }

        if (num_words >= MAX_WORDS_PER_LINE) {
            break;
        }
    }

    fclose(fp);

    print_word_counts(word_counts, num_words);

    return 0;
}