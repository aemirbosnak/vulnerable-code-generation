//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1000
#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

bool is_word(char c) {
    return isalnum(c);
}

void add_word(char *line, int line_len, WordCount *word_counts, int num_word_counts) {
    int i = 0;
    while (i < line_len) {
        if (is_word(line[i])) {
            int j = 0;
            while (i < line_len && is_word(line[i])) {
                i++;
            }
            int word_len = i - j;
            if (word_len > 0) {
                strncpy(word_counts[num_word_counts].word, line + j, word_len);
                word_counts[num_word_counts].word[word_len] = '\0';
                word_counts[num_word_counts].count++;
                num_word_counts++;
            }
        }
        i++;
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char line[MAX_LINE_LEN];
    WordCount word_counts[MAX_WORD_COUNT];
    int num_word_counts = 0;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        int line_len = strlen(line);
        if (line_len == 0) {
            continue;
        }
        add_word(line, line_len, word_counts, num_word_counts);
    }

    fclose(file);

    if (num_word_counts == 0) {
        printf("No words found in input file.\n");
    } else {
        print_word_counts(word_counts, num_word_counts);
    }

    return 0;
}