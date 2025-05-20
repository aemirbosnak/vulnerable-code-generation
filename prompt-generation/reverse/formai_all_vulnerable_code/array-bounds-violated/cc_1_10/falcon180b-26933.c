//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 20

typedef struct {
    char word[MAX_TOKEN_LEN];
    int count;
} Token;

void tokenize(char *sentence, Token *tokens) {
    int i, j, k;
    char word[MAX_TOKEN_LEN] = {0};

    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            word[k] = tolower(sentence[i]);
            k++;
        } else if (k > 0) {
            word[k] = '\0';
            for (j = 0; j < MAX_TOKENS; j++) {
                if (strcmp(tokens[j].word, word) == 0) {
                    tokens[j].count++;
                    break;
                }
            }
            if (j == MAX_TOKENS) {
                strcpy(tokens[j].word, word);
                tokens[j].count = 1;
            }
            k = 0;
        }
    }

    if (k > 0) {
        word[k] = '\0';
        for (j = 0; j < MAX_TOKENS; j++) {
            if (strcmp(tokens[j].word, word) == 0) {
                tokens[j].count++;
                break;
            }
        }
        if (j == MAX_TOKENS) {
            strcpy(tokens[j].word, word);
            tokens[j].count = 1;
        }
    }
}

void print_tokens(Token *tokens) {
    int i;

    for (i = 0; i < MAX_TOKENS; i++) {
        if (tokens[i].word[0]!= '\0') {
            printf("%s: %d\n", tokens[i].word, tokens[i].count);
        }
    }
}

int main() {
    char sentence[1000];
    Token tokens[MAX_TOKENS];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    tokenize(sentence, tokens);
    print_tokens(tokens);

    return 0;
}