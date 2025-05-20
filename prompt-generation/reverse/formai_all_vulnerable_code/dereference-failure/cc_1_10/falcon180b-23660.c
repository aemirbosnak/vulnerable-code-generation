//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

char *tokens[MAX_TOKENS];
int num_tokens;

void tokenize(char *input) {
    char *token;
    int i = 0;
    num_tokens = 0;

    while ((token = strtok(input, " \t\n\r\f\v"))!= NULL) {
        if (strlen(token) > 0) {
            strcpy(tokens[num_tokens], token);
            num_tokens++;
        }
        if (num_tokens >= MAX_TOKENS) {
            break;
        }
    }
}

int is_spam(char *input) {
    int i;
    int num_caps = 0;
    int num_excl = 0;
    int num_num = 0;
    int num_spec = 0;
    int num_url = 0;

    for (i = 0; i < num_tokens; i++) {
        if (isupper(tokens[i][0])) {
            num_caps++;
        }
        if (strchr(tokens[i], '!')) {
            num_excl++;
        }
        if (isdigit(tokens[i][0])) {
            num_num++;
        }
        if (strchr(tokens[i], '@')) {
            num_spec++;
        }
        if (strchr(tokens[i], '.')) {
            num_url++;
        }
    }

    if (num_caps > 3 || num_excl > 3 || num_num > 3 || num_spec > 3 || num_url > 3) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input[MAX_TOKEN_LEN];

    if (argc!= 2) {
        printf("Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    strcpy(input, argv[1]);
    tokenize(input);

    if (is_spam(input)) {
        printf("SPAM\n");
    } else {
        printf("NOT SPAM\n");
    }

    return 0;
}