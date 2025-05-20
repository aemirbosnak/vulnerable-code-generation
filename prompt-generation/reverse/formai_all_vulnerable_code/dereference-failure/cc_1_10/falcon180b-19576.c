//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *value;
    int length;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *value, int length) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].value = value;
    tokens[num_tokens].length = length;
    num_tokens++;
}

void parse_element(char *data, int start, int end) {
    char *value_start = data + start + 1;
    int value_length = end - start - 2;
    add_token(value_start, value_length);
}

void parse_attribute(char *data, int start, int end) {
    char *value_start = data + start + 1;
    int value_length = end - start - 2;
    add_token(value_start, value_length);
}

int main() {
    FILE *file;
    char *buffer;
    int buffer_size;
    int i;

    file = fopen("example.xml", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    buffer_size = 1024;
    buffer = malloc(buffer_size);

    while (fgets(buffer, buffer_size, file)!= NULL) {
        int length = strlen(buffer);
        for (i = 0; i < length; i++) {
            if (buffer[i] == '<') {
                if (i > 0 && isalpha(buffer[i - 1])) {
                    parse_element(buffer, i, length);
                } else {
                    parse_attribute(buffer, i, length);
                }
            }
        }
    }

    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].value);
    }

    free(buffer);
    fclose(file);

    return 0;
}