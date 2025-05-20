//Falcon-180B DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    if (filename == NULL) {
        printf("Error: filename cannot be NULL.\n");
        exit(1);
    }
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        free(file->filename);
        file->filename = NULL;
        file->file = NULL;
    }
}

char *read_line(File *file) {
    char *line = NULL;
    size_t length = 0;
    char *buffer = NULL;
    while (fgets(buffer, MAX_LINE_LENGTH, file->file)!= NULL) {
        if (line!= NULL) {
            char *new_buffer = realloc(line, length + strlen(buffer) + 1);
            if (new_buffer == NULL) {
                printf("Error: out of memory.\n");
                exit(1);
            }
            line = new_buffer;
        } else {
            line = strdup(buffer);
        }
        length += strlen(buffer);
        buffer = realloc(buffer, length + 1);
        if (buffer == NULL) {
            printf("Error: out of memory.\n");
            exit(1);
        }
    }
    if (line!= NULL) {
        line[length - 1] = '\0';
    }
    return line;
}

void print_file(File *file) {
    while ((file->file!= NULL) && (fgetc(file->file)!= EOF)) {
        printf("%c", fgetc(file->file));
    }
}

int main() {
    File file;
    open_file(&file, "example.txt");
    char *line = read_line(&file);
    printf("Contents of file:\n%s", line);
    close_file(&file);
    return 0;
}