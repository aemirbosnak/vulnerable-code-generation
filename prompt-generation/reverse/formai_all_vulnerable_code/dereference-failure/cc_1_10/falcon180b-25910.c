//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 4096
#define MAX_TOKENS 1024

typedef struct {
    char *key;
    int value;
} KeyValuePair;

KeyValuePair *tokens[MAX_TOKENS];
int num_tokens = 0;

void ParseLogLine(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: too many tokens\n");
            exit(1);
        }
        KeyValuePair *pair = malloc(sizeof(KeyValuePair));
        pair->key = strdup(token);
        pair->value = 1;
        tokens[num_tokens++] = pair;
        token = strtok(NULL, " ");
    }
}

void PrintTokenFrequency(KeyValuePair *token) {
    printf("%s: %d\n", token->key, token->value);
}

void FreeTokens() {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]->key);
        free(tokens[i]);
    }
    num_tokens = 0;
}

int main() {
    FILE *file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        ParseLogLine(line);
    }

    fclose(file);

    printf("Token frequencies:\n");
    for (int i = 0; i < num_tokens; i++) {
        PrintTokenFrequency(tokens[i]);
    }

    FreeTokens();

    return 0;
}