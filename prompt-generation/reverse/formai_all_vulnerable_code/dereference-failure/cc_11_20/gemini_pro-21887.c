//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

static char *html_beautify(char *html) {
    size_t html_len = strlen(html);
    char *beautified_html = malloc(html_len * 2);
    int beautified_html_len = 0;
    int in_tag = 0;
    int in_pre = 0;
    int in_script = 0;
    int indent_level = 0;
    int line_count = 0;
    int line_start = 0;
    int i;

    for (i = 0; i < html_len; i++) {
        char c = html[i];

        if (c == '\n') {
            line_count++;
            line_start = i + 1;
            continue;
        }

        if (!in_tag && !in_pre && !in_script && c == '<') {
            in_tag = 1;
            if (beautified_html_len > 0) {
                beautified_html[beautified_html_len++] = '\n';
                for (int j = 0; j < indent_level * TAB_SIZE; j++) {
                    beautified_html[beautified_html_len++] = ' ';
                }
            }
            beautified_html[beautified_html_len++] = c;
            continue;
        }

        if (in_tag && c == '>') {
            in_tag = 0;
            beautified_html[beautified_html_len++] = c;
            continue;
        }

        if (in_tag && strncmp(html + i, "pre", 3) == 0) {
            in_pre = 1;
            i += 2;
            continue;
        }

        if (in_tag && strncmp(html + i, "/pre", 4) == 0) {
            in_pre = 0;
            i += 3;
            continue;
        }

        if (in_tag && strncmp(html + i, "script", 6) == 0) {
            in_script = 1;
            i += 5;
            continue;
        }

        if (in_tag && strncmp(html + i, "/script", 7) == 0) {
            in_script = 0;
            i += 6;
            continue;
        }

        if (in_pre || in_script) {
            beautified_html[beautified_html_len++] = c;
            continue;
        }

        if (!in_tag && c == ' ') {
            if (i > line_start && html[i - 1] != ' ') {
                beautified_html[beautified_html_len++] = ' ';
            }
            continue;
        }

        beautified_html[beautified_html_len++] = c;
    }

    beautified_html[beautified_html_len] = '\0';
    return beautified_html;
}

int main() {
    char *html = "<html>\n\n<head>\n  <title>My Website</title>\n</head>\n\n<body>\n  <h1>Hello, world!</h1>\n\n  <p>This is my website.</p>\n\n</body>\n\n</html>";
    char *beautified_html = html_beautify(html);
    printf("%s\n", beautified_html);
    free(beautified_html);
    return 0;
}