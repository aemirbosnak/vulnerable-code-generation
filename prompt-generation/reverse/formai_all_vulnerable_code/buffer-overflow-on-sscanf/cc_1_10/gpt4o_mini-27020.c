//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void indent(char *line, int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // Print four spaces for indentation
    }
    printf("%s", line);
}

bool is_opening_tag(const char *line) {
    return (strchr(line, '<') && strchr(line, '>') && line[1] != '/');
}

bool is_closing_tag(const char *line) {
    return (strstr(line, "</") != NULL);
}

int main() {
    FILE *input, *output;
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    input = fopen("input.html", "r"); // Open input HTML file
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    output = fopen("output.html", "w"); // Open output HTML file
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), input)) { // Read line by line
        char trimmed_line[MAX_LINE_LENGTH];
        sscanf(line, "%[^\n]", trimmed_line); // Remove new line at the end
        
        if (is_opening_tag(trimmed_line)) {
            indent(trimmed_line, indent_level);
            fprintf(output, "%s\n", trimmed_line);
            indent_level++; // Indent for next line
        } else if (is_closing_tag(trimmed_line)) {
            indent_level--; // Stop indentation for closing tags
            indent(trimmed_line, indent_level);
            fprintf(output, "%s\n", trimmed_line);
        } else {
            indent(trimmed_line, indent_level);
            fprintf(output, "%s\n", trimmed_line);
        }
    }

    fclose(input);
    fclose(output);

    printf("HTML beautification completed. Check output.html\n");
    return EXIT_SUCCESS; // Successful execution
}