//FormAI DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify_html(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file");
        exit(1);
    }
    FILE* ftemp = fopen("temp.html", "w");
    if (!ftemp) {
        printf("Could not create temporary file");
        fclose(fp);
        exit(1);
    }

    char c, prev;
    int indent_level = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '>') {
            fputc(c, ftemp);
            fputc('\n', ftemp);
        } else if (c == '<') {
            fputc('\n', ftemp);
            fputc(c, ftemp);
            prev = c;
        } else {
            if (prev == '<') {
                if (isspace(c)) {
                    continue;
                }
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', ftemp);
                }
                indent_level++;
            }
            fputc(c, ftemp);
            prev = c;
        }
    }

    fclose(fp);
    fclose(ftemp);
    remove(filename);
    rename("temp.html", filename);
}

int main() {
    char filename[100];
    printf("Enter HTML filename: ");
    scanf("%s", filename);
    beautify_html(filename);
    printf("HTML file has been beautified!");
    return 0;
}