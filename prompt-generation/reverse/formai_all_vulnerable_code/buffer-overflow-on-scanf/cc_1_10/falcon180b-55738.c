//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100000

typedef struct {
    char *text;
    int length;
} Line;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    int num_lines = 0;
    Line *lines = NULL;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(filename, MAX_LINE_LENGTH, fp)!= NULL) {
        num_lines++;
    }

    rewind(fp);
    lines = malloc(num_lines * sizeof(Line));

    int line_num = 0;
    while (fgets(filename, MAX_LINE_LENGTH, fp)!= NULL) {
        lines[line_num].text = strdup(filename);
        lines[line_num].length = strlen(filename);
        line_num++;
    }

    fclose(fp);

    printf("Enter search term: ");
    char *search_term = malloc(MAX_LINE_LENGTH);
    scanf("%s", search_term);

    int matches = 0;
    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].text, search_term)!= NULL) {
            printf("%d: %s\n", i + 1, lines[i].text);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);
    free(search_term);

    return 0;
}