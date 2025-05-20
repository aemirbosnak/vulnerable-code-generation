//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_text_file(FILE *file, char text[]) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }
    text[i] = '\0';
}

void count_words(char text[], WordFrequency words[], int num_words) {
    char *token;
    int i;

    token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_frequencies(WordFrequency words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_text_file(file, text);
    count_words(text, words, num_words);
    print_word_frequencies(words, num_words);

    return 0;
}