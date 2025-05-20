//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: intelligent
/*
 * HTML Beautifier Example Program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 100

typedef struct {
    char* html;
    int pos;
    int len;
} html_t;

html_t* html_init(char* html) {
    html_t* h = malloc(sizeof(html_t));
    h->html = html;
    h->pos = 0;
    h->len = strlen(html);
    return h;
}

void html_free(html_t* h) {
    free(h->html);
    free(h);
}

char* html_next_token(html_t* h) {
    char* token = NULL;
    int i = h->pos;
    int len = 0;

    while (i < h->len && !isspace(h->html[i])) {
        i++;
        len++;
    }

    token = malloc(len + 1);
    memcpy(token, &h->html[h->pos], len);
    token[len] = '\0';

    h->pos = i;
    return token;
}

char* html_beautify(char* html) {
    html_t* h = html_init(html);
    char* token;
    char* result = malloc(MAX_LINE_LEN);
    int pos = 0;

    while ((token = html_next_token(h)) != NULL) {
        if (pos + strlen(token) + 1 >= MAX_LINE_LEN) {
            result = realloc(result, MAX_LINE_LEN + MAX_LINE_LEN);
            pos += MAX_LINE_LEN;
        }
        memcpy(&result[pos], token, strlen(token));
        pos += strlen(token);
        result[pos++] = ' ';
        free(token);
    }

    result[pos] = '\0';
    html_free(h);
    return result;
}

int main() {
    char* html = "<html><body><h1>Hello, world!</h1></body></html>";
    char* result = html_beautify(html);
    printf("%s\n", result);
    free(result);
    return 0;
}