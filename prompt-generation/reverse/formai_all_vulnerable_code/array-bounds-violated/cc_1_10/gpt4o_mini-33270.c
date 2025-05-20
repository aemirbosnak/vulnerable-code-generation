//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(FILE *input, FILE *output) {
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int i;

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '<' && buffer[i + 1] == '/') {
                // Close tag found
                indent_level--;
                if (indent_level < 0) indent_level = 0; // Prevent negative indent
            }
            // Print indentation
            if (buffer[i] == '<') {
                for (int j = 0; j < indent_level * INDENT_SIZE; j++) {
                    fputc(' ', output);
                }
            }
            fputc(buffer[i], output);
            if (buffer[i] == '>') {
                // Check for open tag
                if (buffer[i - 1] != '/') {
                    indent_level++;
                }
            }
        }
    }
}

void usage() {
    printf("Usage: beautifier <input.html> <output.html>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error creating file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification is complete. Output saved to %s\n", argv[2]);
    return 0;
}