//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_indentation(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

void print_element(char *start_tag, char *end_tag) {
    printf("%s", start_tag);
    if (strcmp(start_tag, "<br>") != 0 && strcmp(start_tag, "<hr>") != 0) {
        printf("\n");
    }
    printf("%s", end_tag);
    if (strcmp(end_tag, "</br>") != 0 && strcmp(end_tag, "</hr>") != 0) {
        printf("\n");
    }
}

void beautify_html(char *html, int level) {
    char *start_tag = strtok(html, "<>");
    while (start_tag != NULL) {
        char *end_tag = strtok(NULL, "<>");
        if (end_tag == NULL) {
            return;
        }
        if (strcmp(end_tag, "/") != 0) {
            print_indentation(level);
            print_element(start_tag, end_tag);
            if (strcmp(start_tag, "<br>") != 0 && strcmp(start_tag, "<hr>") != 0) {
                beautify_html(end_tag, level + 1);
                print_indentation(level);
            }
        } else {
            if (strcmp(start_tag, end_tag + 1) != 0) {
                fprintf(stderr, "Error: mismatched tag - %s %s\n", start_tag, end_tag + 1);
                exit(EXIT_FAILURE);
            } else {
                return;
            }
        }
        start_tag = strtok(NULL, "<>");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    char *html = (char *) malloc((size + 1) * sizeof(char));
    if (html == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    fread(html, sizeof(char), size, fp);
    fclose(fp);
    html[size] = '\0';
    beautify_html(html, 0);
    free(html);
    return 0;
}