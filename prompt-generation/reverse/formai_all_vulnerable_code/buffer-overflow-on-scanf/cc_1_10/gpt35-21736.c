//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        return;
    }

    char c;
    int indent_level = 0;
    int in_tag = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '<') {
            in_tag = 1;
            printf("%c", c);
            continue;
        } else if (c == '>') {
            in_tag = 0;
            printf("%c", c);
            // Check if it's a self-closing tag
            if (indent_level > 0 && (c = fgetc(file)) == '/') {
                indent_level--;
            } else {
                printf("\n");
                for (int i = 0; i < indent_level; i++) {
                    printf("    ");
                }
            }
            ungetc(c, file);
            continue;
        }

        if (in_tag) {
            printf("%c", c);
        } else {
            if (c == ' ') {
                if (indent_level > 0) {
                    printf("\n");
                    for (int i = 0; i < indent_level; i++) {
                        printf("    ");
                    }
                }
                // Skip any additional spaces
                while ((c = fgetc(file)) == ' ') {}
                printf("%c", c);
            } else {
                printf("%c", c);
            }
        }
    }

    fclose(file);
    return;
}

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    beautify_html(filename);
    return 0;
}