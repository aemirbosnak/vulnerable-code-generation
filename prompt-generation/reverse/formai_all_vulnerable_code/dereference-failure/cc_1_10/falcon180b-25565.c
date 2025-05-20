//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

void print_line(Line line, int level) {
    if (line.length == 0) {
        printf("\n");
        return;
    }

    int i = 0;
    while (i < level) {
        printf("  ");
        i++;
    }

    printf("%s", line.text);

    if (line.length > MAX_LINE_LENGTH) {
        printf("\n");
        i = 0;
        while (i < level) {
            printf("  ");
            i++;
        }
        print_line(line, level);
        return;
    }

    printf("\n");
}

void print_html(char *html, int level) {
    int i = 0;
    while (html[i] == '\n' || html[i] == '\r') {
        i++;
    }

    Line line = {.text = html + i,.length = strlen(html + i)};
    print_line(line, level);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char *html = NULL;
    size_t html_size = 0;
    char *buffer = NULL;
    while ((html_size = getline(&buffer, &html_size, file)) > 0) {
        html = realloc(html, html_size + 1);
        strcat(html, buffer);
    }

    fclose(file);

    print_html(html, 0);

    free(html);
    return 0;
}