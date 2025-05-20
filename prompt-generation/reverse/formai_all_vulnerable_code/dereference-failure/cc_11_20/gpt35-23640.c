//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Please provide a filename as the command line argument\n");
        return 1;
    }

    FILE *input_file;
    input_file = fopen(argv[1], "r");

    if(input_file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char current_indent[MAX_LINE_LENGTH] = "";
    char next_indent[MAX_LINE_LENGTH] = "";
    while(fgets(line, MAX_LINE_LENGTH, input_file)) {
        char *trimmed_line = strdup(line);

        // trim leading and trailing whitespace
        char *start_ptr = trimmed_line;
        while(*start_ptr == ' ' || *start_ptr == '\t') {
            start_ptr++;
        }

        char *end_ptr = start_ptr + strlen(start_ptr) - 1;
        while(*end_ptr == ' ' || *end_ptr == '\t' || *end_ptr == '\n' || *end_ptr == '\r') {
            *end_ptr = 0;
            end_ptr--;
        }

        int line_length = strlen(trimmed_line);
        if(line_length == 0) {
            // skip blank lines
            continue;
        }

        char last_char = trimmed_line[line_length - 1];
        if(last_char == '{') {
            // increase indentation
            strcpy(next_indent, current_indent);
            strcat(next_indent, "\t");
        } else if(last_char == '}') {
            // decrease indentation
            int current_indent_length = strlen(current_indent);
            if(current_indent_length > 0) {
                current_indent[current_indent_length - 1] = '\0';
            }
            strcpy(next_indent, current_indent);
        } else {
            // maintain current indentation
            strcpy(next_indent, current_indent);
        }

        printf("%s%s\n", current_indent, trimmed_line);

        strcpy(current_indent, next_indent);
        free(trimmed_line);
    }
    fclose(input_file);

    return 0;
}