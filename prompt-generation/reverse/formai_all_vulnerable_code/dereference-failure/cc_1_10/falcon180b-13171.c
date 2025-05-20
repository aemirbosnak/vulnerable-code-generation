//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

int main(int argc, char **argv) {
    FILE *fp;
    char line[1024];
    char *token;
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;

    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Too many tokens.\n");
                return 1;
            }
            tokens[num_tokens].name = strdup(token);
            token = strtok(NULL, ":");
            if (token == NULL) {
                printf("Invalid metadata.\n");
                return 1;
            }
            tokens[num_tokens].value = strdup(token);
            num_tokens++;
            token = strtok(NULL, ":");
        }
    }

    fclose(fp);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }

    return 0;
}