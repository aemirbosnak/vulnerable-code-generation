//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        text[i++] = ch;
    }

    text[i] = '\0';
}

void process_word(char *word, int *length) {
    int i = 0;

    while (isalnum(word[i])) {
        i++;
    }

    *length = i;
}

void add_word(WordCount *word_counts, int num_words, char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }

    strcpy(word_counts[num_words].word, word);
    word_counts[num_words].count = 1;
    num_words++;
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_file(file, text);

    char *word = strtok(text, ",.?!;:\"'");

    while (word!= NULL) {
        int length;

        process_word(word, &length);

        if (length > 0 && length <= MAX_WORD_LENGTH) {
            add_word(word_counts, num_words, word);
        }

        word = strtok(NULL, ",.?!;:\"'");
    }

    print_word_counts(word_counts, num_words);

    return 0;
}