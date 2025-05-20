//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TABS 50

// Function declarations
void beautify_html(FILE *input, FILE *output);
void print_with_indent(FILE *output, const char *line, int indent_level);
int is_opening_tag(const char *line);
int is_closing_tag(const char *line);

int main() {
    // A whimsical introduction
    printf("🌟 Welcome to the HTML Beautifier! 🌟\n");
    printf("Please provide the name of the input HTML file: ");
    
    char input_file_name[100];
    scanf("%s", input_file_name);

    printf("And now, the name for the output beautified file: ");
    char output_file_name[100];
    scanf("%s", output_file_name);

    FILE *input_file = fopen(input_file_name, "r");
    if (!input_file) {
        fprintf(stderr, "😱 Couldn't open the input file: %s\n", input_file_name);
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (!output_file) {
        fprintf(stderr, "😱 Couldn't open the output file: %s\n", output_file_name);
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Invoke the beautification wizard
    beautify_html(input_file, output_file);
    printf("✨ All done! Your HTML has been beautified and saved as: %s\n", output_file_name);

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        // Trim whitespace from the line
        char *trimmed_line = line;
        while (isspace((unsigned char)*trimmed_line)) trimmed_line++;

        // Determine if the line has opening or closing tags and adjust indentation
        if (is_closing_tag(trimmed_line)) {
            indent_level--;
        }

        print_with_indent(output, trimmed_line, indent_level);

        if (is_opening_tag(trimmed_line)) {
            indent_level++;
        }
    }
}

void print_with_indent(FILE *output, const char *line, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        fprintf(output, "\t"); // Add a tab for indentation
    }
    fprintf(output, "%s", line);
}

int is_opening_tag(const char *line) {
    return (line[0] == '<' && line[1] != '/' && strstr(line, ">") != NULL);
}

int is_closing_tag(const char *line) {
    return (line[0] == '<' && line[1] == '/');
}