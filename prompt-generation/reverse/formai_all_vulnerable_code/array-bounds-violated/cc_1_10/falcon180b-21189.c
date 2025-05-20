//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int curr_line_num;
} File;

bool read_file(File *file, char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return false;
    }

    char line[MAX_LINE_LENGTH];
    char *line_ptr = line;
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        int line_len = strlen(line);
        if (line_ptr - line > MAX_LINE_LENGTH - 2) {
            printf("Error: Line too long in file %s\n", filename);
            fclose(f);
            return false;
        }
        line[line_len - 1] = '\0';
        file->lines = realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
        file->lines[file->num_lines++] = (Line) {.line = line,.line_num = line_num++};
        line_ptr += line_len + 1;
    }

    fclose(f);
    return true;
}

void print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%d: %s\n", file->lines[i].line_num, file->lines[i].line);
    }
}

void free_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        free(file->lines[i].line);
    }
    free(file->lines);
}

int main() {
    File file;
    char filename[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    if (!read_file(&file, filename)) {
        return 1;
    }

    print_file(&file);

    free_file(&file);

    return 0;
}