//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
/*
 * HTML beautifier program
 *
 * Input: HTML file
 * Output: Beautified HTML file
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INDENT_SIZE 4
#define MAX_LINE_LEN 1024

typedef struct {
    char *html;
    size_t len;
} html_t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    // Read the HTML file into memory
    html_t html = { .html = NULL, .len = 0 };
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return 1;
    }
    html.html = malloc(MAX_LINE_LEN);
    html.len = fread(html.html, sizeof(char), MAX_LINE_LEN, fp);
    fclose(fp);

    // Beautify the HTML
    char *output = malloc(html.len);
    int output_len = 0;
    int indent_level = 0;
    for (int i = 0; i < html.len; i++) {
        char c = html.html[i];
        if (c == '<') {
            // Opening tag
            output[output_len++] = c;
            indent_level++;
        } else if (c == '>') {
            // Closing tag
            indent_level--;
            output[output_len++] = c;
        } else if (c == '\n') {
            // Newline
            output[output_len++] = c;
            for (int j = 0; j < indent_level * INDENT_SIZE; j++) {
                output[output_len++] = ' ';
            }
        } else {
            // Other character
            output[output_len++] = c;
        }
    }
    output[output_len++] = '\0';

    // Write the beautified HTML to a file
    FILE *output_fp = fopen("beautified.html", "w");
    fwrite(output, sizeof(char), output_len, output_fp);
    fclose(output_fp);

    // Clean up
    free(html.html);
    free(output);

    return 0;
}