//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *text;
    int length;
} string_t;

typedef struct {
    string_t **lines;
    int num_lines;
} file_t;

file_t *load_file(const char *filename) {
    file_t *file = malloc(sizeof(file_t));
    file->lines = NULL;
    file->num_lines = 0;

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        string_t *new_line = malloc(sizeof(string_t));
        new_line->text = strdup(line);
        new_line->length = length;
        file->lines = realloc(file->lines, sizeof(string_t *) * ++file->num_lines);
        file->lines[file->num_lines - 1] = new_line;
    }

    fclose(f);
    return file;
}

void free_file(file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i]->text);
        free(file->lines[i]);
    }
    free(file->lines);
    free(file);
}

void print_line(const string_t *line, int line_num) {
    printf("%d: %s\n", line_num, line->text);
}

void print_file(const file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        print_line(file->lines[i], i + 1);
    }
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file_t *file = load_file(filename);
    print_file(file);

    free_file(file);
    return 0;
}