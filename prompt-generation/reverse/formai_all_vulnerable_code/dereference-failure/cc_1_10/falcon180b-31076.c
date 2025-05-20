//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *token;
    int length;
} Token;

void tokenize(char *input, Token *tokens) {
    int i = 0;
    char *ptr = input;
    while (*ptr!= '\0') {
        if (isalpha(*ptr)) {
            char *start = ptr;
            while (isalpha(*ptr)) {
                ptr++;
            }
            tokens[i].token = malloc(ptr - start + 1);
            strncpy(tokens[i].token, start, ptr - start);
            tokens[i].length = ptr - start;
            i++;
        } else if (isspace(*ptr)) {
            ptr++;
        } else if (*ptr == ',') {
            ptr++;
        } else {
            printf("Invalid input! \n");
            exit(1);
        }
    }
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, 1000, stdin);
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;
    tokenize(input, tokens);
    printf("Number of tokens: %d\n", num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: %s (%d characters)\n", i, tokens[i].token, tokens[i].length);
    }
    return 0;
}