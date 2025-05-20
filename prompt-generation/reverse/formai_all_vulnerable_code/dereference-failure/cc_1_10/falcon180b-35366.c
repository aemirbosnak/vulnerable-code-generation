//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    int value;
} token_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[MAX_TOKEN_LEN];
    char line[MAX_TOKEN_LEN];
    char *token;
    char *saveptr;
    int count = 0;
    token_t tokens[MAX_TOKENS];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        char *line_copy = strdup(line);
        char *token_copy = strtok_r(line_copy, " \t\r\n", &saveptr);

        while (token_copy!= NULL) {
            if (count >= MAX_TOKENS) {
                printf("Error: Maximum number of tokens reached.\n");
                exit(1);
            }

            tokens[count].name = strdup(token_copy);
            tokens[count].value = 0;

            count++;

            token_copy = strtok_r(NULL, " \t\r\n", &saveptr);
        }

        free(line_copy);
    }

    fclose(fp);

    printf("Tokens:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", tokens[i].name);
    }

    return 0;
}