//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 10000
#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *word;
    int line_count = 0;
    int word_count = 0;
    WordCount word_counts[MAX_WORDS];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line_count++;

        // Convert line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize line into words
        word = strtok(line, " ");
        while (word!= NULL) {
            word_count++;

            // Check if word is already in word_counts array
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }

            // If word is not found, add it to array
            if (!found) {
                if (word_count >= MAX_WORDS) {
                    printf("Error: Too many unique words in input file\n");
                    exit(1);
                }
                word_counts[word_count].word = strdup(word);
                word_counts[word_count].count = 1;
                word_count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    // Sort word_counts array by count
    qsort(word_counts, word_count, sizeof(WordCount), compare_word_counts);

    // Print results
    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", word_count);
    printf("Most frequent word: %s (%d occurrences)\n", word_counts[0].word, word_counts[0].count);

    for (int i = 1; i < word_count; i++) {
        if (word_counts[i].count!= word_counts[i-1].count) {
            printf("Words with %d occurrences:\n", word_counts[i].count);
            for (int j = i; j < word_count; j++) {
                if (word_counts[j].count == word_counts[i].count) {
                    printf(" %s", word_counts[j].word);
                }
            }
            printf("\n");
        }
    }

    return 0;
}