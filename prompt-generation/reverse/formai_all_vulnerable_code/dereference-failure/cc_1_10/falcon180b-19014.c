//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 4096

typedef struct {
    char *text;
    int token_count;
    char **tokens;
} Line;

Line *line_create(char *text) {
    Line *line = (Line *)malloc(sizeof(Line));
    line->text = text;
    line->token_count = 0;
    line->tokens = (char **)malloc(sizeof(char *) * MAX_TOKENS);
    return line;
}

void line_destroy(Line *line) {
    free(line->text);
    free(line->tokens);
    free(line);
}

void line_split(Line *line) {
    char *token;
    int i = 0;
    char *text = line->text;
    char *word_start = text;
    while (*text!= '\0') {
        if (isspace(*text)) {
            *text = '\0';
            token = strdup(word_start);
            line->tokens[i++] = token;
            word_start = text + 1;
        }
        text++;
    }
    line->token_count = i;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Line *line_ptr;
    int line_count = 0;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_ptr = line_create(strdup(line));
        line_split(line_ptr);
        printf("Line %d: %s\n", line_count++, line_ptr->text);
        for (int i = 0; i < line_ptr->token_count; i++) {
            printf("\tToken %d: %s\n", i, line_ptr->tokens[i]);
        }
        free(line_ptr->text);
        for (int i = 0; i < line_ptr->token_count; i++) {
            free(line_ptr->tokens[i]);
        }
        free(line_ptr->tokens);
        line_destroy(line_ptr);
    }

    fclose(fp);
    return 0;
}