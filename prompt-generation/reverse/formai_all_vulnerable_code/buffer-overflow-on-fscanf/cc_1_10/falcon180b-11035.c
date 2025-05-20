//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, file);
            fscanf(file, "%s", filename + i);
            i += strlen(filename + i) + 1;
        }
    }
}

void count_words(char *filename, WordCount *word_counts, int num_words) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    char ch;
    int word_length = 0;
    int in_word = false;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = true;
        } else if (in_word) {
            in_word = false;
            word_counts[word_length].count++;
            word_length = 0;
        } else {
            word_length++;
        }
    }
    if (in_word) {
        word_counts[word_length].count++;
    }
    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    read_file(stdin, filename);
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    count_words(filename, word_counts, num_words);
    print_word_counts(word_counts, num_words);
    return 0;
}