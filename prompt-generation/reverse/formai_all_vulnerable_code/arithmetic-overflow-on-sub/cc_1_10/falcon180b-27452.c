//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT_LEVEL 16
#define INDENT_STEP 4

int indent_level = 0;

void indent(int step) {
    for (int i = 0; i < step; i++) {
        printf(" ");
    }
}

void beautify_html(char* html) {
    char* line = strtok(html, "\n");
    while (line!= NULL) {
        printf("%*s%s\n", indent_level * INDENT_STEP, "", line);
        indent_level += line[strlen(line) - 1] == '<'? 1 : -1;
        if (indent_level > MAX_INDENT_LEVEL) {
            indent_level = MAX_INDENT_LEVEL;
        } else if (indent_level < 0) {
            indent_level = 0;
        }
        line = strtok(NULL, "\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char* html = NULL;
    size_t size = 0;
    ssize_t read;
    while ((read = getline(&html, &size, file))!= -1) {
        html[read - 1] = '\0';
        beautify_html(html);
    }

    free(html);
    fclose(file);

    return 0;
}