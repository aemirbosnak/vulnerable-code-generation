//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount words[]) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            int i = 0;
            while (isalpha(ch) && i < MAX_WORD_LENGTH - 1) {
                words[i].word[i] = tolower(ch);
                i++;
                ch = fgetc(file);
            }
            words[i].word[i] = '\0';
            words[i].count++;
        }
    }
}

void sort_words(WordCount words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;

    read_file(file, words);
    fclose(file);

    sort_words(words, num_words);
    print_words(words, num_words);

    return 0;
}