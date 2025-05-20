//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
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

void read_file(FILE *file, char *text) {
    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_WORDS * MAX_WORD_LENGTH) {
        fprintf(stderr, "Error: File is too large.\n");
        exit(1);
    }

    fread(text, file_size, 1, file);
    text[file_size] = '\0';
}

void tokenize(char *text, char **tokens) {
    int num_tokens = 0;
    char *token = strtok(text, ",.?!;:");

    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;

        if (num_tokens >= MAX_WORDS) {
            break;
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void count_word_frequencies(char **tokens, int num_tokens, WordFrequency *frequencies) {
    for (int i = 0; i < num_tokens; i++) {
        char *token = tokens[i];

        if (strlen(token) > MAX_WORD_LENGTH) {
            continue;
        }

        strcpy(frequencies[i].word, token);
        frequencies[i].count = 1;
    }
}

void print_frequencies(WordFrequency *frequencies, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        if (frequencies[i].count > 1) {
            printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    char text[MAX_WORDS * MAX_WORD_LENGTH];
    read_file(file, text);
    fclose(file);

    char *tokens[MAX_WORDS];
    tokenize(text, tokens);

    WordFrequency frequencies[MAX_WORDS];
    count_word_frequencies(tokens, MAX_WORDS, frequencies);

    print_frequencies(frequencies, MAX_WORDS);

    return 0;
}