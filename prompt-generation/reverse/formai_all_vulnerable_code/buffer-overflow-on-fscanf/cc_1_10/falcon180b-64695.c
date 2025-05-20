//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_MAX_LENGTH 50

typedef struct {
    char word[WORD_MAX_LENGTH];
    int frequency;
} WordFrequency;

void read_words(FILE *file, WordFrequency words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].word[1] = '\0';
            words[i].frequency = 1;
            i++;
        }
    }
}

void count_words(WordFrequency words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void print_words(WordFrequency words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
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
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int num_words = 0;
    while (num_words < MAX_WORDS && fscanf(file, "%s", words[num_words].word)!= EOF) {
        num_words++;
    }

    read_words(file, words);
    count_words(words, num_words);
    print_words(words, num_words);

    fclose(file);
    return 0;
}