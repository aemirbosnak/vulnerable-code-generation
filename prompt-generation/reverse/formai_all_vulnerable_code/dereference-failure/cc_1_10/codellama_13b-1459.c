//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: scalable
/*
 * HTML beautifier example program
 *
 * This program takes an HTML file as input and outputs a beautified version
 * of the file, with proper indentation and formatting.
 *
 * This program is written in a scalable style, meaning it can handle
 * large HTML files without crashing or running out of memory.
 *
 * Usage:
 *     html_beautifier <input_file> <output_file>
 *
 * Example:
 *     html_beautifier input.html output.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4

void print_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
}

void print_tag(const char *tag, int level) {
    printf("<%s>", tag);
    print_indent(level);
}

void print_tag_end(const char *tag, int level) {
    print_indent(level);
    printf("</%s>", tag);
}

void print_text(const char *text) {
    printf("%s", text);
}

void print_html(const char *html) {
    int level = 0;
    char *tag = NULL;
    char *text = NULL;
    char *token = NULL;

    token = strtok(html, " ");
    while (token != NULL) {
        if (token[0] == '<') {
            tag = token + 1;
            print_tag(tag, level);
        } else if (token[0] == '>') {
            print_tag_end(tag, level);
            level--;
        } else {
            text = token;
            print_text(text);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Unable to open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Unable to open output file %s\n", argv[2]);
        return 1;
    }

    char *html = NULL;
    size_t size = 0;
    while (getline(&html, &size, input) != -1) {
        print_html(html);
    }

    fclose(input);
    fclose(output);

    return 0;
}