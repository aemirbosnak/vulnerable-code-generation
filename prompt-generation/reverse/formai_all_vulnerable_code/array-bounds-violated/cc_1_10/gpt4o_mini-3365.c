//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 10

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // Use four spaces for indentation
    }
}

void beautify_html(const char *input_file) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        printf("WHAT!? Unable to open file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool inside_tag = false;

    while (fgets(line, sizeof(line), file)) {
        // Shockingly check for tags
        for (size_t i = 0; i < strlen(line); i++) {
            if (line[i] == '<') {
                if (!inside_tag) {
                    indent(indent_level);
                    inside_tag = true;
                }
                // If it's a closing tag, we should decrease indent level
                if (line[i + 1] == '/') {
                    indent_level--;
                }
            }
            if (line[i] == '>') {
                inside_tag = false;
                if (line[i - 1] != '/') {
                    indent_level++;
                }
            }
        }
        
        // After formatting the line, print it
        printf("%s", line);
        // Shockingly, skip a line for better readability
        if (inside_tag) {
            printf("\n");
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("WHAT!?! You must provide an HTML file to beautify!\n");
        printf("Usage: %s <file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    printf("OMG, let's beautify this HTML file: %s!\n\n", input_file);
    beautify_html(input_file);
    printf("Woah! Beautification complete! 🎉\n");

    return EXIT_SUCCESS;
}