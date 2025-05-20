//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Token;

int token_count = 0;
Token tokens[MAX_TOKENS];

void add_token(char *text, int length) {
    if (token_count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[token_count].text = malloc(length + 1);
    strncpy(tokens[token_count].text, text, length);
    tokens[token_count].length = length;
    token_count++;
}

void print_tokens() {
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i].text);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        for (int i = 0; i < length; i++) {
            if (isalpha(line[i])) {
                char word[length - i];
                strncpy(word, &line[i], length - i);
                word[length - i] = '\0';
                add_token(word, strlen(word));
            }
        }
    }

    fclose(file);
    print_tokens();

    return 0;
}