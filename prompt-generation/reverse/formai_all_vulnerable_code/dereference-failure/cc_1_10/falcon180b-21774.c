//Falcon-180B DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
    int line_number;
} file_t;

typedef struct {
    char *message;
    int error_code;
} error_t;

void init_file(file_t *file, const char *filename)
{
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    file->line_number = 0;
}

int read_line(file_t *file, char *buffer, int max_length)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;

    while ((bytes_read = getline(&line, &len, file->fp))!= -1) {
        if (bytes_read >= max_length) {
            fprintf(stderr, "Error: Line too long in file '%s' at line %d\n", file->filename, file->line_number);
            exit(EXIT_FAILURE);
        }
        strncpy(buffer, line, bytes_read);
        buffer[bytes_read] = '\0';
        return 0;
    }

    if (ferror(file->fp)) {
        fprintf(stderr, "Error: Failed to read line in file '%s' at line %d: %s\n", file->filename, file->line_number, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 1;
}

void close_file(file_t *file)
{
    if (file->fp) {
        fclose(file->fp);
    }
    free(file->filename);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Error: Missing filename argument\n");
        return EXIT_FAILURE;
    }

    file_t file;
    init_file(&file, argv[1]);

    char buffer[MAX_LINE_LENGTH];
    while (read_line(&file, buffer, MAX_LINE_LENGTH)) {
        printf("%s", buffer);
    }

    close_file(&file);
    return 0;
}