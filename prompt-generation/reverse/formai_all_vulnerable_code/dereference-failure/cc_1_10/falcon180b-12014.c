//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

WordCount *word_counts;
int num_words;

void init_word_counts() {
    word_counts = (WordCount *)malloc(sizeof(WordCount) * MAX_NUM_WORDS);
    num_words = 0;
}

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, word_counts[i].word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    if (num_words >= MAX_NUM_WORDS) {
        printf("Error: too many unique words\n");
        exit(1);
    }
    strcpy(word_counts[num_words].word, word);
    word_counts[num_words].count = 1;
    num_words++;
}

void print_word_counts() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int is_word(char *line) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (!isalpha(line[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *file;
    int line_num = 0;

    init_word_counts();

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_num++;
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            if (is_word(token)) {
                add_word(token);
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    print_word_counts();

    fclose(file);
    return 0;
}