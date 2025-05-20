//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency words[MAX_WORDS]) {
    char ch;
    int word_length = 0;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (word_length == MAX_WORD_LENGTH - 1) {
                printf("Error: word too long\n");
                exit(1);
            }
            words[i].word[word_length++] = tolower(ch);
        } else {
            if (word_length > 0) {
                words[i].word[word_length] = '\0';
                words[i].frequency++;
                word_length = 0;
            }
        }
    }

    if (word_length > 0) {
        words[i].word[word_length] = '\0';
        words[i].frequency++;
    }
}

void sort_words(WordFrequency words[MAX_WORDS]) {
    int i, j;
    WordFrequency temp;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].frequency > words[i].frequency) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    read_file(file, words);
    fclose(file);

    sort_words(words);
    print_word_frequencies(words);

    return 0;
}