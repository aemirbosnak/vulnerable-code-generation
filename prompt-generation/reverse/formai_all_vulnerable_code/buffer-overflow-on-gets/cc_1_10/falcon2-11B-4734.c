//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char* html) {
    int i, j;
    char line[256];
    char *p;
    int indent_level = 0;
    int num_tabs = 0;

    for (i = 0; i < strlen(html); i++) {
        if (html[i] == '<') {
            indent_level++;
            if (html[i] == '/') {
                indent_level--;
            }
            num_tabs = (num_tabs + 1) % 4;
            strcpy(line, "");
            for (j = 0; j < num_tabs; j++) {
                strcat(line, "    ");
            }
            strcat(line, "<");
            for (j = 0; j < indent_level; j++) {
                strcat(line, "&nbsp;");
            }
            strcat(line, ">");
            p = line;
            for (j = i + 1; j < strlen(html); j++) {
                if (html[j] == '>') {
                    break;
                }
                p = strcat(p, html[j]);
            }
            strcat(html, p);
        }
    }
}

int main() {
    char html[512];
    char *p;

    printf("Enter HTML code: ");
    gets(html);
    p = html;
    while ((*p!= '\0') && (*p!= '<')) {
        p++;
    }
    beautify_html(p);
    printf("%s\n", html);
    return 0;
}