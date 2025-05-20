//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define INDENT_SPACES 2

typedef struct {
    char *text;
    int length;
} Line;

void indent(int level) {
    for (int i = 0; i < level * INDENT_SPACES; i++) {
        printf(" ");
    }
}

void print_line(Line line, int level) {
    if (line.length > MAX_LINE_LENGTH) {
        printf("Error: Line too long\n");
        return;
    }

    for (int i = 0; i < level * INDENT_SPACES; i++) {
        printf(" ");
    }

    printf("%s\n", line.text);
}

void process_file(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    Line current_line = {.text = NULL,.length = 0 };
    int level = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(buffer);

        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
            length--;
        }

        if (length == 0) {
            continue;
        }

        if (length + current_line.length + 1 > MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            return;
        }

        char *new_buffer = realloc(current_line.text, current_line.length + length + 1);
        if (new_buffer == NULL) {
            printf("Error: Memory allocation failed\n");
            return;
        }

        current_line.text = new_buffer;
        strcat(current_line.text, buffer);
        current_line.length += length;

        if (buffer[0] == '<') {
            level++;
        } else if (buffer[0] == '>') {
            level--;
        }
    }

    if (current_line.text!= NULL) {
        print_line(current_line, level);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Cannot open input file\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Cannot open output file\n");
        return 1;
    }

    process_file(input_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}