//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char* html = NULL;
    size_t len = 0;
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    len = ftell(file);
    rewind(file);

    html = malloc(len + 1);
    if (html == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    if (fread(html, 1, len, file)!= len) {
        printf("Error reading file %s\n", argv[1]);
        free(html);
        return 1;
    }

    html[len] = '\0';

    char* lines[100];
    int line_count = 0;
    char* line = strtok(html, "\n");
    while (line!= NULL) {
        lines[line_count++] = line;
        line = strtok(NULL, "\n");
    }

    char* trimmed_html = "";
    for (int i = 0; i < line_count; i++) {
        char* trimmed = strtok(lines[i], "\t");
        while (trimmed!= NULL) {
            if (trimmed[0]!= '\0') {
                if (trimmed_html[0] == '\0') {
                    trimmed_html = trimmed;
                } else {
                    trimmed_html = realloc(trimmed_html, strlen(trimmed_html) + strlen(trimmed) + 1);
                    if (trimmed_html == NULL) {
                        printf("Memory allocation error\n");
                        return 1;
                    }
                    strcat(trimmed_html, " ");
                    strcat(trimmed_html, trimmed);
                }
            }
            trimmed = strtok(NULL, "\t");
        }
        trimmed_html[strlen(trimmed_html) - 1] = '\n';
        trimmed_html[strlen(trimmed_html)] = '\0';
        printf("%s", trimmed_html);
        trimmed_html = "";
    }

    free(html);
    fclose(file);
    return 0;
}