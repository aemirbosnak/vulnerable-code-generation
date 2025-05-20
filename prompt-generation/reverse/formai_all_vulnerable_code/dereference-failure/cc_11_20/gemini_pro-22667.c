//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char *html_beautify(char *html) {
    int i, j, k, l;
    char *beautified_html = malloc(strlen(html) * 2);
    int in_tag = 0;
    int in_attribute = 0;
    int in_comment = 0;
    int line_length = 0;
    int indent_level = 0;

    for (i = 0, j = 0; html[i] != '\0'; i++) {
        if (in_comment) {
            if (html[i] == '*' && html[i+1] == '/') {
                in_comment = 0;
                i++;
            }
            continue;
        }

        if (html[i] == '<') {
            if (in_attribute) {
                beautified_html[j++] = html[i];
            } else {
                if (line_length > 0) {
                    beautified_html[j++] = '\n';
                    for (k = 0; k < indent_level; k++) {
                        beautified_html[j++] = ' ';
                    }
                }
                beautified_html[j++] = html[i];
                in_tag = 1;
                line_length = 0;
            }
        } else if (html[i] == '>') {
            in_tag = 0;
            beautified_html[j++] = html[i];
            line_length = 0;
        } else if (html[i] == '"') {
            if (in_attribute) {
                in_attribute = 0;
                beautified_html[j++] = html[i];
            } else {
                in_attribute = 1;
                beautified_html[j++] = html[i];
            }
        } else if (html[i] == '/') {
            if (html[i+1] == '>') {
                if (line_length > 0) {
                    beautified_html[j++] = '\n';
                    for (k = 0; k < indent_level; k++) {
                        beautified_html[j++] = ' ';
                    }
                }
                beautified_html[j++] = html[i];
                beautified_html[j++] = html[i+1];
                line_length = 0;
                i++;
            } else {
                beautified_html[j++] = html[i];
            }
        } else if (html[i] == '\n') {
            beautified_html[j++] = html[i];
            line_length = 0;
        } else if (html[i] == ' ') {
            if (in_attribute) {
                beautified_html[j++] = html[i];
            } else if (line_length > 0) {
                beautified_html[j++] = ' ';
                line_length++;
            }
        } else {
            if (in_tag) {
                if (html[i] == '=') {
                    beautified_html[j++] = ' ';
                    beautified_html[j++] = html[i];
                    beautified_html[j++] = ' ';
                } else {
                    beautified_html[j++] = html[i];
                }
            } else {
                beautified_html[j++] = html[i];
            }
            line_length++;
        }
    }

    beautified_html[j] = '\0';

    return beautified_html;
}

int main() {
    char *html = "<html>\n<head>\n<title>HTML Beautifier</title>\n</head>\n<body>\n<h1>HTML Beautifier</h1>\n<p>This is a simple HTML beautifier.</p>\n</body>\n</html>";
    char *beautified_html = html_beautify(html);
    printf("%s", beautified_html);
    free(beautified_html);
    return 0;
}