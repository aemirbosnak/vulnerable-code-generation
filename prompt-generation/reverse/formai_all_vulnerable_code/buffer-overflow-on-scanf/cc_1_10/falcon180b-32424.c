//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 10

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

void initialize(WordFrequency *word_frequency, int count) {
    for (int i = 0; i < count; i++) {
        word_frequency[i].frequency = 0;
        strcpy(word_frequency[i].word, "");
    }
}

void read_file(FILE *file, WordFrequency *word_frequency, int count) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i == WORD_LENGTH - 1) {
                i = 0;
            }
            word_frequency[i].word[i] = tolower(ch);
            i++;
        } else {
            if (i > 0) {
                word_frequency[i - 1].frequency++;
                i = 0;
            }
        }
    }
    if (i > 0) {
        word_frequency[i - 1].frequency++;
    }
}

void print_word_frequency(WordFrequency *word_frequency, int count) {
    for (int i = 0; i < count; i++) {
        if (word_frequency[i].frequency > 0) {
            printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[50];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    WordFrequency word_frequency[MAX_WORDS];
    int count = 0;
    initialize(word_frequency, MAX_WORDS);

    read_file(file, word_frequency, MAX_WORDS);

    print_word_frequency(word_frequency, MAX_WORDS);

    fclose(file);
    return 0;
}