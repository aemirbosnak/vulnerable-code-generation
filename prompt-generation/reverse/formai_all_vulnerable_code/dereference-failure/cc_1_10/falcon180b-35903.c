//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100
#define COMMENT_CHAR '#'

typedef struct token {
    char *value;
    int line_number;
    int column_number;
} token_t;

typedef struct {
    int num_tokens;
    token_t tokens[MAX_TOKENS];
} metadata_t;

metadata_t *extract_metadata(FILE *file) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->num_tokens = 0;
    int line_number = 1;
    int column_number = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (c == '\n') {
            line_number++;
            column_number = 0;
        }
        if (c == COMMENT_CHAR) {
            while ((c = fgetc(file))!= EOF && c!= '\n') {
                if (c == '\r') {
                    // ignore
                }
            }
        }
        else if (isalpha(c)) {
            char *value = malloc(MAX_TOKEN_LENGTH * sizeof(char));
            int length = 0;
            while (isalnum(c)) {
                value[length++] = tolower(c);
                c = fgetc(file);
            }
            value[length] = '\0';
            token_t token = {
               .value = value,
               .line_number = line_number,
               .column_number = column_number
            };
            metadata->tokens[metadata->num_tokens++] = token;
            column_number += strlen(value) + 1;
        }
        else {
            column_number++;
        }
    }
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tokens; i++) {
        printf("Line %d, Column %d: %s\n", metadata->tokens[i].line_number, metadata->tokens[i].column_number, metadata->tokens[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }
    metadata_t *metadata = extract_metadata(file);
    fclose(file);
    print_metadata(metadata);
    free(metadata);
    return 0;
}