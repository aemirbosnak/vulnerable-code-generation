//FormAI DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void html_format(char *input, char *output) {
    /*
     * This function formats the input HTML code and writes it to
     * the output buffer.
     */
    int indent_level = 0;
    char *token, *line;

    while (*input) {
        /* get next line */
        line = strtok_r(input, "\n", &input);

        if (!line) {
            continue;
        }

        /* get next token */
        token = strtok(line, " ");

        while (token) {
            if (strcmp(token, "<html>") == 0 ||
                strcmp(token, "<head>") == 0 ||
                strcmp(token, "<body>") == 0 ||
                strcmp(token, "<div>") == 0 ||
                strcmp(token, "<p>") == 0 ||
                strcmp(token, "<ul>") == 0 ||
                strcmp(token, "<li>") == 0) {
                /* start tag - increase indent level */
                for (int i = 0; i < indent_level; i++) {
                    strcat(output, "    ");
                }
                strcat(output, token);
                strcat(output, "\n");
                indent_level++;
            } else if (strcmp(token, "</html>") == 0 ||
                       strcmp(token, "</head>") == 0 ||
                       strcmp(token, "</body>") == 0 ||
                       strcmp(token, "</div>") == 0 ||
                       strcmp(token, "</p>") == 0 ||
                       strcmp(token, "</ul>") == 0 ||
                       strcmp(token, "</li>") == 0) {
                /* end tag - decrease indent level */
                indent_level--;
                for (int i = 0; i < indent_level; i++) {
                    strcat(output, "    ");
                }
                strcat(output, token);
                strcat(output, "\n");
            } else {
                /* other tag - no change to indent level */
                for (int i = 0; i < indent_level; i++) {
                    strcat(output, "    ");
                }
                strcat(output, token);
                strcat(output, "\n");
            }
            /* get next token */
            token = strtok(NULL, " ");
        }
    }
}

int main() {
    char code[] = "<html>\n<head>\n<title>Example HTML Code</title>\n</head>\n<body>\n<div id=\"main\">\n<h1>Example HTML Code</h1>\n<p>This is an example of how HTML code can be formatted using C.</p>\n<ul>\n<li>Item 1</li>\n<li>Item 2</li>\n</ul>\n</div>\n</body>\n</html>\n";
    char formatted_code[1000] = "";

    printf("Input HTML code:\n%s\n\n", code);
    html_format(code, formatted_code);
    printf("Formatted HTML code:\n%s", formatted_code);

    return 0;
}