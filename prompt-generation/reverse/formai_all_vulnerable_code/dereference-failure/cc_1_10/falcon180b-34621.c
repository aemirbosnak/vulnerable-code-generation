//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 50

typedef struct {
    char *name;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        return;
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char line[MAX_TOKEN_SIZE];
    while (fgets(line, MAX_TOKEN_SIZE, file)!= NULL) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            char *name = strtok(token, " ");
            char *value = strtok(NULL, " ");
            if (name == NULL || value == NULL) {
                printf("Error: Invalid token format.\n");
                return 1;
            }
            add_token(name, value);
            token = strtok(NULL, ":");
        }
    }

    fclose(file);

    printf("Name: %s\n", tokens[0].value);
    printf("Address: %s\n", tokens[1].value);
    printf("Phone: %s\n", tokens[2].value);
    printf("Email: %s\n", tokens[3].value);

    return 0;
}