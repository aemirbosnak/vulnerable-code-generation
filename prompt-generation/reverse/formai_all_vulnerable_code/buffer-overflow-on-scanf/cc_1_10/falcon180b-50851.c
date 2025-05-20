//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* text;
    int length;
} Line;

Line* read_line(FILE* file) {
    Line* line = malloc(sizeof(Line));
    line->text = malloc(MAX_LINE_LENGTH * sizeof(char));
    line->length = 0;

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            break;
        }
        if (line->length >= MAX_LINE_LENGTH - 1) {
            fprintf(stderr, "Line too long! ");
            exit(1);
        }
        line->text[line->length++] = ch;
    }
    line->text[line->length] = '\0';

    return line;
}

void print_line(Line* line) {
    printf("%s\n", line->text);
}

void free_line(Line* line) {
    free(line->text);
    free(line);
}

int main() {
    FILE* file;
    char filename[256];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file! ");
        exit(1);
    }

    Line* line;
    while ((line = read_line(file))!= NULL) {
        print_line(line);
        free_line(line);
    }

    fclose(file);
    return 0;
}