//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main() {
    FILE *fp;
    char *file_name = "example.c";

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file: %s\n", strerror(errno));
        return 1;
    }

    char line[ARRAY_SIZE];
    int line_num = 0;
    int char_count = 0;
    int comment_count = 0;
    int word_count = 0;
    int bracket_count = 0;
    int paranthesis_count = 0;
    int comma_count = 0;
    int semicolon_count = 0;

    while (fgets(line, ARRAY_SIZE, fp) != NULL) {
        line_num++;
        char_count += strlen(line);

        // Counting comments
        if (strstr(line, "//") || strstr(line, "/*")) {
            comment_count++;
        }

        // Counting words
        char *token;
        token = strtok(line, " \t\n");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " \t\n");
        }

        // Counting brackets
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '{' || line[i] == '}') {
                bracket_count++;
            }
        }

        // Counting parantheses
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '(' || line[i] == ')') {
                paranthesis_count++;
            }
        }

        // Counting commas
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == ',') {
                comma_count++;
            }
        }

        // Counting semicolons
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == ';') {
                semicolon_count++;
            }
        }
    }

    printf("Total lines: %d\n", line_num);
    printf("Total characters: %d\n", char_count);
    printf("Total comments: %d\n", comment_count);
    printf("Total words: %d\n", word_count);
    printf("Total brackets: %d\n", bracket_count);
    printf("Total parantheses: %d\n", paranthesis_count);
    printf("Total commas: %d\n", comma_count);
    printf("Total semicolons: %d\n", semicolon_count);

    fclose(fp);

    return 0;
}