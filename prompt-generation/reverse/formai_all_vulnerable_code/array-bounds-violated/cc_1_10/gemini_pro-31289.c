//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 80
#define MAX_ROWS 1000

char *metadata[MAX_ROWS][MAX_COLS];
int num_rows = 0;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        char *tokens[MAX_COLS];
        int num_tokens = 0;

        char *token = strtok(line, ",");
        while (token != NULL) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, ",");
        }

        if (num_tokens < 2) {
            continue;
        }

        metadata[num_rows][0] = strdup(tokens[0]);
        metadata[num_rows][1] = strdup(tokens[1]);
        num_rows++;
    }

    fclose(fp);

    for (int i = 0; i < num_rows; i++) {
        printf("%s\t%s\n", metadata[i][0], metadata[i][1]);
    }

    return 0;
}