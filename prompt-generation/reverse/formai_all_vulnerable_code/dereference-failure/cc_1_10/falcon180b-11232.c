//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *filename, WordFrequency words[]) {
    char line[1024];
    char *token;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            int i;
            for (i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    token[i] = '\0';
                    break;
                }
            }

            int word_length = strlen(token);
            if (word_length > MAX_WORD_LENGTH) {
                word_length = MAX_WORD_LENGTH;
            }

            strncpy(words[i].word, token, word_length);
            words[i].count++;

            token = strtok(NULL, ",.?!;:");
            i++;
        }
    }

    fclose(fp);
}

void sort_words(WordFrequency words[], int num_words) {
    int i, j;
    WordFrequency temp;

    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    read_file(file, argv[1], words);
    fclose(file);

    sort_words(words, num_words);
    print_word_frequencies(words, num_words);

    return 0;
}