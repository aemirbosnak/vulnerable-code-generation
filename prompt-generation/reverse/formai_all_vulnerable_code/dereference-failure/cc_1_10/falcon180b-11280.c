//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000

typedef struct {
    char *key;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *key, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].key = strdup(key);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].key, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[1024];
    char *key, *value;
    char delim = ':';

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        key = line;
        value = strchr(line, delim);
        if (value == NULL) {
            printf("Error: Invalid line format\n");
            exit(1);
        }
        *value = '\0';
        value++;
        add_token(key, value);
    }

    fclose(fp);
    print_tokens();

    return 0;
}