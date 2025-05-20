//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_TOKENS 100

typedef struct {
    char *key;
    char *value;
} token_t;

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    char input[1024];
    char *token;
    char *value;
    char *saveptr;
    int num_tokens = 0;
    token_t tokens[MAX_TOKENS];

    // Read input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Parse input file
    while (fgets(input, sizeof(input), file)!= NULL) {
        token = strtok_r(input, " \t\n", &saveptr);
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens.\n");
                return 1;
            }
            value = strchr(token, '=');
            if (value == NULL) {
                printf("Error: Invalid token format.\n");
                return 1;
            }
            *value = '\0';
            value++;
            tokens[num_tokens].key = strdup(token);
            tokens[num_tokens].value = strdup(value);
            num_tokens++;
            token = strtok_r(NULL, " \t\n", &saveptr);
        }
    }

    // Translate tokens
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].key, "cat") == 0) {
            strcpy(tokens[i].value, "gato");
        } else if (strcmp(tokens[i].key, "dog") == 0) {
            strcpy(tokens[i].value, "perro");
        } else if (strcmp(tokens[i].key, "bird") == 0) {
            strcpy(tokens[i].value, "pájaro");
        }
    }

    // Write output file
    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    for (int i = 0; i < num_tokens; i++) {
        fprintf(output, "%s=%s\n", tokens[i].key, tokens[i].value);
    }
    fclose(output);

    // Free memory
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].key);
        free(tokens[i].value);
    }
    fclose(file);

    return 0;
}