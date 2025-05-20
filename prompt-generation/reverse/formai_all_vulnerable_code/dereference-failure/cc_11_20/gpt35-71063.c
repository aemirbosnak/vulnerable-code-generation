//FormAI DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE* input_file;
    FILE* output_file;
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int tag_ended = 1;

    // Open input file for reading
    input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file for writing
    output_file = fopen("output.html", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        int len = strlen(buffer);

        // if the line ends with a newline character, ignore it
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // ignore empty lines
        if (len == 0) {
            continue;
        }

        // check if the line starts with a closing tag
        if (buffer[0] == '<' && buffer[1] == '/') {
            indent_level--;
        }

        // print the indentation
        for (int i = 0; i < indent_level; i++) {
            fprintf(output_file, "  ");
        }

        // print the line of HTML code
        fprintf(output_file, "%s\n", buffer);

        // check if the line starts with an opening tag
        if (buffer[0] == '<' && buffer[len - 2] != '/') {
            indent_level++;
        }

        // keep track of whether the tag has ended
        if (buffer[len - 2] == '/') {
            tag_ended = 1;
        } else {
            tag_ended = 0;
        }

        // if the tag has ended, decrease indentation
        if (tag_ended && indent_level > 0) {
            indent_level--;
        }
    }

    // close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}