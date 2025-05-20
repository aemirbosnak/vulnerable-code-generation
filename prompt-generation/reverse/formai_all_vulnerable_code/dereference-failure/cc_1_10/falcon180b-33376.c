//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

typedef struct token_t {
    char *name;
    char *value;
    int is_attribute;
} token_t;

typedef struct metadata_t {
    int num_tokens;
    token_t tokens[MAX_TOKENS];
} metadata_t;

metadata_t *metadata_extract(FILE *file) {
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->num_tokens = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v:=");
        while (token!= NULL) {
            if (metadata->num_tokens >= MAX_TOKENS) {
                printf("Maximum number of tokens reached.\n");
                exit(1);
            }

            token_t t = {0};
            strcpy(t.name, token);

            if (strlen(token) > 1 && token[0] == '@' && isalpha(token[1])) {
                t.is_attribute = 1;
            }

            if (token[0] == '=') {
                token = strtok(NULL, " \t\n\r\f\v");
                if (token == NULL) {
                    printf("Missing value for token '%s'.\n", t.name);
                    exit(1);
                }
                strcpy(t.value, token);
            }

            metadata->tokens[metadata->num_tokens++] = t;

            token = strtok(NULL, " \t\n\r\f\v:=");
        }
    }

    return metadata;
}

void metadata_print(metadata_t *metadata) {
    printf("Metadata:\n");
    for (int i = 0; i < metadata->num_tokens; i++) {
        token_t t = metadata->tokens[i];
        if (t.is_attribute) {
            printf("@%s\n", t.name);
        } else {
            printf("%s=%s\n", t.name, t.value);
        }
    }
}

void metadata_free(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tokens; i++) {
        free(metadata->tokens[i].name);
        free(metadata->tokens[i].value);
    }
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    metadata_t *metadata = metadata_extract(file);
    metadata_print(metadata);
    metadata_free(metadata);

    fclose(file);
    return 0;
}