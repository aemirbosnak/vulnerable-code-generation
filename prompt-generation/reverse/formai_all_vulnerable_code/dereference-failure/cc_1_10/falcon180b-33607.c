//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *beautify_html(char *html) {
    char *output = malloc(BUFFER_SIZE);
    char *p = output;

    while (*html) {
        if (*html == '<') {
            if (*(html + 1) == '!') {
                if (*(html + 2) == '-') {
                    if (*(html + 3) == '-') {
                        strcpy(p, "&lt;!--");
                        p += strlen("&lt;!--");
                        html += 4;
                        continue;
                    }
                }
            }
            if (*(html + 1) == '/') {
                strcpy(p, "&lt;");
                p += strlen("&lt;");
                html += 2;
                continue;
            }
            *p++ = *html++;
        } else if (*html == '>') {
            strcpy(p, "&gt;");
            p += strlen("&gt;");
            html++;
            continue;
        } else if (*html == '&') {
            strcpy(p, "&amp;");
            p += strlen("&amp;");
            html++;
            continue;
        } else {
            *p++ = *html++;
        }

        if (p - output >= BUFFER_SIZE - 10) {
            output = realloc(output, BUFFER_SIZE * 2);
            p = output + strlen(output);
        }
    }

    *p = '\0';
    return output;
}

int main() {
    char *html = "<html><head><title>Example</title></head><body><p>Hello, world!</p></body></html>";
    char *beautified_html = beautify_html(html);
    printf("%s\n", beautified_html);
    free(beautified_html);
    return 0;
}