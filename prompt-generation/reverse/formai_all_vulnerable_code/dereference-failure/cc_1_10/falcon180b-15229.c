//Falcon-180B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
} FILE_T;

FILE_T *fopen_with_error_handling(const char *filename, const char *mode) {
    FILE_T *file = (FILE_T *) malloc(sizeof(FILE_T));

    if (file == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for FILE_T struct.\n");
        exit(EXIT_FAILURE);
    }

    file->filename = strdup(filename);
    file->fp = fopen(filename, mode);

    if (file->fp == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        free(file->filename);
        free(file);
        exit(EXIT_FAILURE);
    }

    return file;
}

void fclose_with_error_handling(FILE_T *file) {
    if (fclose(file->fp)!= 0) {
        fprintf(stderr, "Error: Failed to close file '%s'.\n", file->filename);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    free(file->filename);
    free(file);
}

char *fgets_with_error_handling(FILE_T *file, char *buffer, int max_length) {
    char *result = fgets(buffer, max_length, file->fp);

    if (result == NULL) {
        fprintf(stderr, "Error: Failed to read line from file '%s'.\n", file->filename);
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return result;
}

int main() {
    char filename[MAX_LINE_LENGTH];
    char mode[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE_T *file = NULL;

    printf("Enter filename: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);

    printf("Enter mode (r/w): ");
    fgets(mode, MAX_LINE_LENGTH, stdin);

    file = fopen_with_error_handling(filename, mode);

    while (fgets_with_error_handling(file, line, MAX_LINE_LENGTH)!= NULL) {
        printf("%s", line);
    }

    fclose_with_error_handling(file);

    return 0;
}