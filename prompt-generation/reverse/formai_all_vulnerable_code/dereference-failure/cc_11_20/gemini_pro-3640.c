//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 100
#define MAX_ROWS 100
#define MAX_LINE_LEN 1000

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LEN];
    char **cols = malloc(sizeof(char *) * MAX_COLS);
    if (cols == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    int num_cols = 0;
    int num_rows = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char *tok = strtok(line, ",");
        while (tok != NULL) {
            cols[num_cols] = strdup(tok);
            if (cols[num_cols] == NULL) {
                perror("strdup");
                return EXIT_FAILURE;
            }
            num_cols++;
            tok = strtok(NULL, ",");
        }
        num_rows++;
    }

    fclose(fp);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", cols[i * num_cols + j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            free(cols[i * num_cols + j]);
        }
    }
    free(cols);

    return EXIT_SUCCESS;
}