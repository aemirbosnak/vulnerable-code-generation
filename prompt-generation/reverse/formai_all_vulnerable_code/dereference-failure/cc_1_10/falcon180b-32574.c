//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i == MAX_WORD_LENGTH - 1) {
                printf("Error: Word is too long - %s\n", filename);
                exit(1);
            }
            strncat(filename, &ch, 1);
            i++;
        } else {
            filename[i] = '\0';
            i = 0;
        }
    }
    if (i > 0) {
        filename[i] = '\0';
    }
}

void count_words(char *filename, WordFrequency *word_frequency, int num_words) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found - %s\n", filename);
        exit(1);
    }
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i == MAX_WORD_LENGTH - 1) {
                printf("Error: Word is too long - %s\n", filename);
                exit(1);
            }
            strncat(word_frequency[num_words].word, &ch, 1);
            i++;
        } else {
            word_frequency[num_words].word[i] = '\0';
            i = 0;
            num_words++;
        }
    }
    if (i > 0) {
        word_frequency[num_words - 1].word[i] = '\0';
    }
    fclose(file);
}

void sort_words(WordFrequency *word_frequency, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(word_frequency[i].word, word_frequency[j].word) > 0) {
                WordFrequency temp = word_frequency[i];
                word_frequency[i] = word_frequency[j];
                word_frequency[j] = temp;
            }
        }
    }
}

void print_word_frequency(WordFrequency *word_frequency, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char filename[MAX_WORD_LENGTH];
    read_file(stdin, filename);
    WordFrequency word_frequency[MAX_WORDS];
    int num_words = 0;
    count_words(filename, word_frequency, num_words);
    sort_words(word_frequency, num_words);
    print_word_frequency(word_frequency, num_words);
    return 0;
}