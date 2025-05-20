//Falcon-180B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

int file_init(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    return 0;
}

int file_close(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
    free(file->filename);
    file->filename = NULL;
    return 0;
}

int file_read_line(File *file, char *buffer, size_t size) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    do {
        read = getline(&line, &len, file->file);
        if (read == -1) {
            if (feof(file->file)) {
                strncpy(buffer, "", size);
                return 0;
            } else {
                printf("Error reading file %s\n", file->filename);
                exit(1);
            }
        }
    } while (read == -1);

    strncpy(buffer, line, size);
    return strlen(buffer);
}

int main() {
    File file;
    char filename[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    size_t size = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file_init(&file, filename);

    while (file_read_line(&file, buffer, MAX_LINE_LENGTH) > 0) {
        printf("%s", buffer);
        size += strlen(buffer);
        if (size >= MAX_LINE_LENGTH) {
            printf("\n");
            size = 0;
        }
    }

    file_close(&file);

    return 0;
}