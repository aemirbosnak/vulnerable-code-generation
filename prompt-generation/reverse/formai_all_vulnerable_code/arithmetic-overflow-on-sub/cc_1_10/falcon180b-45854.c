//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define TRUE 1
#define FALSE 0

typedef struct token {
    char *key;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, len + 1);
            line[read] = '\0';
        }
    }

    return line;
}

void parse_token(char *str, token_t *token) {
    char *key = NULL;
    char *value = NULL;
    char *p = str;
    int in_key = TRUE;

    while (*p!= '\0') {
        if (*p == '\"' && in_key) {
            in_key = FALSE;
            key = p + 1;
        } else if (*p == '\"' &&!in_key) {
            in_key = TRUE;
            value = p + 1;
        } else if (*p == ',' && in_key) {
            *p = '\0';
            break;
        } else if (*p == ':' && in_key) {
            *p = '\0';
            in_key = FALSE;
        }

        p++;
    }

    if (key!= NULL && value!= NULL) {
        token->key = strdup(key);
        token->value = strdup(value);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    num_tokens = 0;

    while ((line = read_line(fp))!= NULL) {
        parse_token(line, &tokens[num_tokens]);
        num_tokens++;
    }

    fclose(fp);

    for (i = 0; i < num_tokens; i++) {
        printf("Key: %s\nValue: %s\n", tokens[i].key, tokens[i].value);
    }

    return 0;
}