//Falcon-180B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *text) {
    char c;
    int i = 0;

    while ((c = fgetc(file))!= EOF) {
        text[i++] = c;
    }

    text[i] = '\0';
}

void tokenize(char *text, char **tokens) {
    char delimiters[] = ",.!?;:\"'()[]{}<>";
    char *token = strtok(text, delimiters);

    int i = 0;
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delimiters);
    }

    tokens[i] = NULL;
}

void count_words(char **tokens, WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(tokens[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                break;
            }
        }

        if (j == MAX_WORDS) {
            strcpy(word_counts[i].word, tokens[i]);
            word_counts[i].count = 1;
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    char *tokens[MAX_WORDS];
    WordCount word_counts[MAX_WORDS];
    int num_words;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_file(file, text);
    fclose(file);

    tokenize(text, tokens);
    count_words(tokens, word_counts, MAX_WORDS);
    num_words = MAX_WORDS;

    print_word_counts(word_counts, num_words);

    return 0;
}