//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct TextLine {
    char* text;
    int length;
};

struct TextLine* readTextFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct TextLine* lines = malloc(sizeof(struct TextLine));
    int numLines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        struct TextLine* newLine = realloc(lines, (numLines + 1) * sizeof(struct TextLine));
        if (newLine == NULL) {
            return NULL;
        }
        lines = newLine;

        lines[numLines].text = strdup(line);
        lines[numLines].length = strlen(line);

        numLines++;
    }

    fclose(file);

    return lines;
}

void printTextFile(struct TextLine* lines, int numLines) {
    for (int i = 0; i < numLines; i++) {
        printf("%s", lines[i].text);
    }
}

int main() {
    struct TextLine* lines = readTextFile("example.txt");
    if (lines == NULL) {
        return 1;
    }

    printTextFile(lines, 10);

    for (int i = 0; i < 10; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}