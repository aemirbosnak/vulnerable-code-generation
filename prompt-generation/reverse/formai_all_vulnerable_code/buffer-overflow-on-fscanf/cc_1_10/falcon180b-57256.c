//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequencies) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word_frequencies[i].word[word_frequencies[i].count] = tolower(ch);
            word_frequencies[i].count++;
        } else {
            if (word_frequencies[i].count > 0) {
                word_frequencies[i].word[word_frequencies[i].count] = '\0';
                i++;
            }
            word_frequencies[i].count = 0;
        }
    }
    if (word_frequencies[i].count > 0) {
        word_frequencies[i].word[word_frequencies[i].count] = '\0';
        i++;
    }
}

void sort_word_frequencies(WordFrequency *word_frequencies, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(word_frequencies[i].word, word_frequencies[j].word) > 0) {
                WordFrequency temp = word_frequencies[i];
                word_frequencies[i] = word_frequencies[j];
                word_frequencies[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }
}

int main() {
    FILE *file;
    WordFrequency word_frequencies[MAX_WORDS];
    int n = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (n < MAX_WORDS && fscanf(file, "%s", word_frequencies[n].word)!= EOF) {
        n++;
    }

    fclose(file);

    read_file(file, word_frequencies);

    sort_word_frequencies(word_frequencies, n);

    print_word_frequencies(word_frequencies, n);

    return 0;
}