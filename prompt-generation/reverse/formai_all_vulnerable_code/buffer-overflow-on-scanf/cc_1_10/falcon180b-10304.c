//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char filename[MAX_LINE_LENGTH];
    FILE *file;
    int line_number;
    char line[MAX_LINE_LENGTH];
} File_t;

void open_file(File_t *file, const char *filename) {
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->line_number = 0;
}

void close_file(File_t *file) {
    fclose(file->file);
}

int read_line(File_t *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF && i < MAX_LINE_LENGTH - 1) {
        file->line[i++] = c;
    }
    file->line[i] = '\0';
    file->line_number++;
    return i;
}

void print_line(File_t *file) {
    printf("%d: %s", file->line_number, file->line);
}

int main() {
    File_t file;
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    open_file(&file, filename);
    while (read_line(&file) > 0) {
        print_line(&file);
    }
    close_file(&file);
    printf("File closed.\n");
    return 0;
}