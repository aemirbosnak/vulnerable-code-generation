//Falcon-180B DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKEN_LEN 64

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    int num_tokens;
    token_t tokens[MAX_TOKEN_LEN];
} line_t;

line_t *read_line(FILE *file) {
    line_t *line = malloc(sizeof(line_t));
    line->num_tokens = 0;

    char *buffer = malloc(MAX_LINE_LEN);
    char *token = malloc(MAX_TOKEN_LEN);

    fgets(buffer, MAX_LINE_LEN, file);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

    char *current_token = strtok(buffer, " ");
    while (current_token!= NULL) {
        if (line->num_tokens >= MAX_TOKEN_LEN) {
            printf("Error: Too many tokens on line.\n");
            exit(1);
        }

        strcpy(line->tokens[line->num_tokens].name, current_token);
        strcpy(line->tokens[line->num_tokens].value, "");
        line->num_tokens++;

        current_token = strtok(NULL, " ");
    }

    free(buffer);
    free(token);

    return line;
}

void print_line(line_t *line) {
    for (int i = 0; i < line->num_tokens; i++) {
        printf("%s: %s\n", line->tokens[i].name, line->tokens[i].value);
    }
}

void write_line(FILE *file, line_t *line) {
    for (int i = 0; i < line->num_tokens; i++) {
        fprintf(file, "%s: %s\n", line->tokens[i].name, line->tokens[i].value);
    }
}

void execute_query(line_t *line) {
    if (strcmp(line->tokens[0].name, "SELECT") == 0) {
        printf("Executing SELECT query...\n");
        for (int i = 1; i < line->num_tokens; i++) {
            printf("%s\n", line->tokens[i].value);
        }
    } else if (strcmp(line->tokens[0].name, "INSERT") == 0) {
        printf("Executing INSERT query...\n");
        // TODO: Implement INSERT query
    } else if (strcmp(line->tokens[0].name, "UPDATE") == 0) {
        printf("Executing UPDATE query...\n");
        // TODO: Implement UPDATE query
    } else if (strcmp(line->tokens[0].name, "DELETE") == 0) {
        printf("Executing DELETE query...\n");
        // TODO: Implement DELETE query
    } else {
        printf("Invalid query.\n");
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    line_t *line = NULL;

    while ((line = read_line(input_file))!= NULL) {
        print_line(line);
        execute_query(line);
        write_line(stdout, line);
        free(line->tokens);
        free(line);
        line = NULL;
    }

    fclose(input_file);

    return 0;
}