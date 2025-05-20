//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void read_file(FILE *fp, char *filename) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(filename, tolower(ch));
        }
    }
}

void tokenize(char *string, char **tokens, int max_tokens) {
    int i = 0;
    char *token = strtok(string, ",.?!;:");
    while (token!= NULL && i < max_tokens) {
        tokens[i++] = token;
        token = strtok(NULL, ",.?!;:");
    }
}

void count_words(char **tokens, int num_tokens, WordFrequency *word_freq, int max_words) {
    for (int i = 0; i < num_tokens; i++) {
        int found = false;
        for (int j = 0; j < max_words; j++) {
            if (strcmp(tokens[i], word_freq[j].word) == 0) {
                word_freq[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            if (word_freq[max_words - 1].count == 0) {
                strcpy(word_freq[max_words - 1].word, tokens[i]);
                word_freq[max_words - 1].count++;
            }
        }
    }
}

void print_word_freq(WordFrequency *word_freq, int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_freq[i].word, word_freq[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    char *tokens[MAX_WORDS];
    WordFrequency word_freq[MAX_WORDS];
    int num_tokens = 0;

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    read_file(fp, filename);

    fclose(fp);

    num_tokens = strlen(filename);

    tokenize(filename, tokens, num_tokens);

    count_words(tokens, num_tokens, word_freq, MAX_WORDS);

    print_word_freq(word_freq, MAX_WORDS);

    return 0;
}