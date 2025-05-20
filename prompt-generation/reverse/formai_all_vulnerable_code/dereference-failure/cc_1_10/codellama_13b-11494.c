//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: configurable
/*
 * C HTML beautifier program
 *
 * This program takes in a string of HTML code and
 * outputs a beautified version of the code, with
 * configurable indentation and spacing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDENT_LEVEL 10
#define MAX_INDENT_WIDTH 4

/*
 * Structure to hold the configuration options
 * for the beautifier.
 */
typedef struct {
    int indent_level;
    int indent_width;
} config_t;

/*
 * Function to parse the configuration options
 * from the command line arguments.
 */
void parse_config(config_t *config, int argc, char **argv) {
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            config->indent_level = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-w") == 0) {
            config->indent_width = atoi(argv[++i]);
        }
    }
}

/*
 * Function to beautify the HTML code.
 */
void beautify_html(config_t *config, char *html) {
    int i, j, k, l;
    char *new_html;
    int indent_level = 0;
    int indent_width = config->indent_width;
    int new_line = 0;
    int inside_tag = 0;

    // Allocate memory for the new HTML code
    new_html = (char *)malloc(strlen(html) * sizeof(char));

    // Loop through the HTML code and beautify it
    for (i = 0, j = 0; html[i] != '\0'; i++, j++) {
        // Check if we are inside a tag
        if (html[i] == '<') {
            inside_tag = 1;
            new_html[j] = html[i];
        } else if (html[i] == '>') {
            inside_tag = 0;
            new_html[j] = html[i];
        }

        // Check if we are at the end of a line
        if (html[i] == '\n') {
            new_line = 1;
        }

        // Check if we need to insert a newline and indent
        if (new_line) {
            // Insert a newline
            new_html[j++] = '\n';

            // Insert indentation
            for (k = 0; k < indent_level * indent_width; k++) {
                new_html[j++] = ' ';
            }

            // Reset the new line flag
            new_line = 0;
        }

        // Check if we need to increase the indentation level
        if (inside_tag) {
            indent_level++;
        }

        // Check if we need to decrease the indentation level
        if (html[i] == '>' && inside_tag) {
            indent_level--;
        }
    }

    // Add a newline at the end of the code
    new_html[j++] = '\n';

    // Null terminate the new HTML code
    new_html[j] = '\0';

    // Print the beautified HTML code
    printf("%s", new_html);

    // Free the memory allocated for the new HTML code
    free(new_html);
}

int main(int argc, char **argv) {
    config_t config;
    char *html;

    // Parse the configuration options from the command line arguments
    parse_config(&config, argc, argv);

    // Read the HTML code from the standard input
    html = (char *)malloc(BUFSIZ * sizeof(char));
    fgets(html, BUFSIZ, stdin);

    // Beautify the HTML code
    beautify_html(&config, html);

    // Free the memory allocated for the HTML code
    free(html);

    return 0;
}