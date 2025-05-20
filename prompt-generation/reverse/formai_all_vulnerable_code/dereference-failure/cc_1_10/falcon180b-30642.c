//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_SIZE 256

typedef struct {
    char *filename;
    int linenumber;
    char *line;
} Line;

int main(int argc, char **argv) {

    FILE *file;
    char buffer[MAX_FILE_SIZE];
    char *line;
    int linenumber = 1;
    int filesize = 0;
    Line *lines = NULL;
    int numlines = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_FILE_SIZE, file)!= NULL) {
        filesize += strlen(buffer);

        line = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(line, buffer);

        lines = realloc(lines, sizeof(Line) * ++numlines);

        lines[numlines - 1].filename = argv[1];
        lines[numlines - 1].linenumber = linenumber;
        lines[numlines - 1].line = line;

        linenumber++;
    }

    fclose(file);

    printf("File size: %d bytes\n", filesize);
    printf("Number of lines: %d\n", numlines);

    for (int i = 0; i < numlines; i++) {
        printf("Line %d: %s\n", lines[i].linenumber, lines[i].line);
    }

    for (int i = 0; i < numlines; i++) {
        free(lines[i].line);
        free(lines[i].filename);
    }
    free(lines);

    return 0;
}