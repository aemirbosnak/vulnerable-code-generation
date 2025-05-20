//Falcon-180B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    char *mode;
    FILE *fp;
} File;

File *file_open(char *filename, char *mode) {
    File *file = (File *)malloc(sizeof(File));
    if (file == NULL) {
        printf("Error: Failed to allocate memory for file.\n");
        exit(1);
    }
    file->filename = strdup(filename);
    file->mode = strdup(mode);
    file->fp = fopen(file->filename, file->mode);
    if (file->fp == NULL) {
        printf("Error: Failed to open file '%s' in '%s' mode.\n", file->filename, file->mode);
        free(file->filename);
        free(file->mode);
        free(file);
        exit(1);
    }
    return file;
}

void file_close(File *file) {
    fclose(file->fp);
    free(file->filename);
    free(file->mode);
    free(file);
}

int file_read_line(File *file, char *buffer, int max_length) {
    int length = 0;
    if (fgets(buffer, max_length, file->fp) == NULL) {
        if (ferror(file->fp)) {
            printf("Error: Failed to read line from file.\n");
        }
        return 0;
    }
    length = strlen(buffer);
    if (buffer[length - 1] == '\n') {
        buffer[--length] = '\0';
    }
    return length;
}

int file_write_line(File *file, const char *buffer) {
    return fprintf(file->fp, "%s\n", buffer);
}

int main() {
    File *input_file = NULL;
    File *output_file = NULL;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    int input_buffer_length;
    int output_buffer_length;

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = file_open(input_filename, "r");
    output_file = file_open(output_filename, "w");

    while ((input_buffer_length = file_read_line(input_file, input_buffer, MAX_LINE_LENGTH)) > 0) {
        output_buffer_length = file_write_line(output_file, input_buffer);
        if (output_buffer_length <= 0) {
            printf("Error: Failed to write line to output file.\n");
            break;
        }
    }

    file_close(input_file);
    file_close(output_file);

    return 0;
}