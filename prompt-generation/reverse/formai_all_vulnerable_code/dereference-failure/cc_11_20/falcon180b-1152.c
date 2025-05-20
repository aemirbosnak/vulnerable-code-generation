//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 256

typedef struct {
    char *key;
    char *value;
} token_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    char quote = '"';
    char *token;
    int line_count = 0;
    int token_count = 0;
    token_t tokens[MAX_TOKENS];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line_count++;

        // Remove leading/trailing whitespace
        char *ptr = line;
        while (isspace(*ptr)) {
            ptr++;
        }
        if (*ptr == '\0') {
            continue;
        }
        char *end_ptr = ptr + strlen(ptr) - 1;
        while (isspace(*end_ptr)) {
            end_ptr--;
            *end_ptr = '\0';
        }

        // Parse line into tokens
        token = strtok(ptr, &delimiter);
        while (token!= NULL) {
            token_count++;
            if (token_count >= MAX_TOKENS) {
                printf("Error: Too many tokens on line %d\n", line_count);
                exit(1);
            }
            tokens[token_count].key = strdup(token);
            tokens[token_count].value = NULL;
            token = strtok(NULL, &delimiter);
        }
    }

    fclose(fp);

    // Print tokens
    for (int i = 0; i < token_count; i++) {
        printf("Key: %s\n", tokens[i].key);
        if (tokens[i].value!= NULL) {
            printf("Value: %s\n", tokens[i].value);
        }
    }

    return 0;
}