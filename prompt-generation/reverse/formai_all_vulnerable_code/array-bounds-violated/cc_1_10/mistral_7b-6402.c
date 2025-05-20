//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 255
#define TAB_SIZE 4

void print_error_and_exit(char *error_message) {
    printf("%s\n", error_message);
    exit(EXIT_FAILURE);
}

void process_line(char *line, int *current_indent, int *tab_count) {
    int i, j;
    char tab[TAB_SIZE];

    for (i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') {
            tab[*tab_count * TAB_SIZE + i - *tab_count * TAB_SIZE] = ' ';
            tab[*tab_count * TAB_SIZE + i] = '\0';
            *tab_count += 1;
        }
    }

    for (i = 0; i <= *tab_count; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            putchar(' ');
        }
    }

    for (i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') {
            continue;
        }

        if (isspace(line[i])) {
            continue;
        }

        putchar(line[i]);

        if (line[i] == '>') {
            *current_indent = *current_indent - *tab_count;
            *tab_count = 0;
        }
    }

    if (line[strlen(line) - 1] == '\n') {
        putchar('\n');
    }

    for (i = 0; i <= *tab_count; i++) {
        tab[i * TAB_SIZE] = '\t';
        tab[i * TAB_SIZE + 1] = '\0';
        putchar(tab[i * TAB_SIZE]);
    }

    *current_indent = *current_indent + *tab_count;
    *tab_count = 0;
}

int main(int argc, char **argv) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    int current_indent = 0;
    int tab_count = 0;

    if (argc != 2) {
        print_error_and_exit("Usage: beautifier <input_file.html>");
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        print_error_and_exit("Error opening input file.");
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        process_line(line, &current_indent, &tab_count);
    }

    fclose(input_file);

    return EXIT_SUCCESS;
}