//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_TAB_STOP 8

void beautify_html(char* html) {
    char* out = malloc(strlen(html) * 2);
    char* in = html;
    char* out_p = out;

    while (*in) {
        if (*in == '<') {
            // Start of a tag
            *out_p++ = *in++;
            while (*in && *in != '>') {
                if (*in == ' ') {
                    // Space in the tag name
                    *out_p++ = ' ';
                } else {
                    // Attribute name or value
                    *out_p++ = *in++;
                }
            }
            *out_p++ = *in++;
        } else if (*in == '>') {
            // End of a tag
            *out_p++ = *in++;
            *out_p++ = ' ';
        } else if (*in == '/') {
            // Self-closing tag
            *out_p++ = *in++;
            while (*in && *in != '>') {
                if (*in == ' ') {
                    // Space in the tag name
                    *out_p++ = ' ';
                } else {
                    // Attribute name or value
                    *out_p++ = *in++;
                }
            }
            *out_p++ = *in++;
            *out_p++ = ' ';
        } else {
            // Text node
            *out_p++ = *in++;
        }
    }

    *out_p = '\0';
    printf("%s\n", out);
    free(out);
}

int main() {
    char html[] = "<html>\n<head>\n<title>Hello World</title>\n</head>\n<body>\n<h1>Hello World</h1>\n</body>\n</html>";
    beautify_html(html);
    return 0;
}