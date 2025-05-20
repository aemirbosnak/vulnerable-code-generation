//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *words) {
    char ch;
    int word_length = 0;
    bool in_word = false;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = true;
                words[word_length].word[0] = tolower(ch);
                word_length = 1;
            } else {
                strncat(words[word_length - 1].word, &ch, 1);
                words[word_length - 1].frequency++;
            }
        } else {
            in_word = false;
        }
    }
}

void sort_words(WordFrequency *words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequency(WordFrequency *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_NUM_WORDS];
    int num_words = 0;

    read_file(file, words);
    num_words = sizeof(words) / sizeof(WordFrequency);

    sort_words(words, num_words);
    print_word_frequency(words, num_words);

    fclose(file);
    return 0;
}