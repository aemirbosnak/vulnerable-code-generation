//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *token;
    int value;
} Token;

typedef struct {
    char *word;
    int length;
} Word;

Token tokens[MAX_TOKENS];
Word words[MAX_TOKENS];

int num_tokens = 0;
int num_words = 0;

char input_buffer[1000];
char word_buffer[MAX_WORD_LENGTH];

void add_token(char *token, int value) {
    tokens[num_tokens].token = strdup(token);
    tokens[num_tokens].value = value;
    num_tokens++;
}

void add_word(char *word) {
    words[num_words].word = strdup(word);
    words[num_words].length = strlen(word);
    num_words++;
}

int get_token_value(char *token) {
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].token, token) == 0) {
            return tokens[i].value;
        }
    }
    return -1;
}

void parse_input(char *input) {
    char *token = strtok(input, " ");
    while (token!= NULL) {
        add_token(token, get_token_value(token));
        token = strtok(NULL, " ");
    }
}

int main() {
    printf("Enter a program in C Cat Language:\n");
    fgets(input_buffer, 1000, stdin);
    parse_input(input_buffer);

    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].value);
    }

    printf("\nWords:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}