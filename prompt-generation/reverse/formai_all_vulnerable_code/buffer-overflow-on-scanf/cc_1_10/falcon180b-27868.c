//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5000
#define MAX_LINE_LENGTH 500

struct line {
    char *text;
    int length;
};

void add_line(struct line *lines, int count, char *text) {
    if (count >= MAX_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    lines[count].text = malloc(MAX_LINE_LENGTH);
    if (lines[count].text == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    strcpy(lines[count].text, text);
    lines[count].length = strlen(text);
}

void print_lines(struct line lines[], int count) {
    if (count == 0) {
        printf("No lines found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    struct line lines[MAX_LINES];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(lines, line_count++, line);
    }

    fclose(file);
    print_lines(lines, line_count);

    return 0;
}