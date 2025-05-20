//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the file

typedef struct {
    char *filename;
    FILE *file;
} File;

File *file_open(const char *filename) {
    File *f = (File *) malloc(sizeof(File));
    if (f == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    f->filename = strdup(filename);
    f->file = fopen(filename, "r");
    if (f->file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        free(f->filename);
        free(f);
        exit(1);
    }
    return f;
}

void file_close(File *f) {
    if (f == NULL) {
        printf("Error: Invalid file pointer.\n");
        exit(1);
    }
    if (fclose(f->file)!= 0) {
        printf("Error: Could not close file.\n");
        exit(1);
    }
    free(f->filename);
    free(f);
}

char *file_readline(File *f) {
    char *line = NULL;
    size_t n = 0;
    ssize_t read;
    if (f == NULL) {
        printf("Error: Invalid file pointer.\n");
        exit(1);
    }
    line = (char *) malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    read = getline(&line, &n, f->file);
    if (read == -1) {
        if (feof(f->file)) {
            printf("End of file reached.\n");
        } else {
            printf("Error: Could not read line from file.\n");
        }
        free(line);
        line = NULL;
    } else {
        line[read] = '\0';
    }
    return line;
}

int main() {
    File *file = file_open("example.txt");
    if (file == NULL) {
        return 1;
    }
    char *line = file_readline(file);
    while (line!= NULL) {
        printf("%s", line);
        line = file_readline(file);
    }
    file_close(file);
    return 0;
}