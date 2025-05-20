//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *f, const char *filename) {
    f->filename = strdup(filename);
    f->file = fopen(filename, "r");
    if (f->file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }
}

char *read_line(File *f) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, f->file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
        }
    }

    return line;
}

void close_file(File *f) {
    free(f->filename);
    fclose(f->file);
}

int compare_lines(const void *a, const void *b) {
    const char *line1 = *(const char **)a;
    const char *line2 = *(const char **)b;

    return strcasecmp(line1, line2);
}

void sync_files(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s FILE1 FILE2\n", argv[0]);
        exit(1);
    }

    File file1, file2;

    open_file(&file1, argv[1]);
    open_file(&file2, argv[2]);

    char *line1, *line2;
    while ((line1 = read_line(&file1))!= NULL && (line2 = read_line(&file2))!= NULL) {
        if (strcmp(line1, line2)!= 0) {
            printf("Mismatch in line '%s'\n", line1);
            exit(1);
        }
    }

    if (line1 == NULL && line2 == NULL) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
    }

    close_file(&file1);
    close_file(&file2);
}

int main(int argc, char **argv) {
    sync_files(argc, argv);

    return 0;
}