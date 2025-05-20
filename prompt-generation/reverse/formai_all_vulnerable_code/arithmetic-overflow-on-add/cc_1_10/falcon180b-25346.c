//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

typedef struct {
    char *filename;
    FILE *file;
    int filesize;
    char *data;
} FileInfo;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FileInfo *file_info = malloc(sizeof(FileInfo));
    if (!file_info) {
        printf("Error: Could not allocate memory for file info.\n");
        return 1;
    }

    file_info->filename = strdup(filename);
    file_info->file = fopen(filename, "rb");
    if (!file_info->file) {
        printf("Error: Could not open file '%s'.\n", filename);
        free(file_info->filename);
        free(file_info);
        return 1;
    }

    fseek(file_info->file, 0, SEEK_END);
    file_info->filesize = ftell(file_info->file);
    rewind(file_info->file);

    file_info->data = malloc(file_info->filesize + 1);
    if (!file_info->data) {
        printf("Error: Could not allocate memory for file data.\n");
        fclose(file_info->file);
        free(file_info->filename);
        free(file_info);
        return 1;
    }

    size_t bytes_read = fread(file_info->data, 1, file_info->filesize, file_info->file);
    if (bytes_read!= file_info->filesize) {
        printf("Error: Could not read entire file.\n");
        fclose(file_info->file);
        free(file_info->data);
        free(file_info->filename);
        free(file_info);
        return 1;
    }

    fclose(file_info->file);

    printf("File '%s' successfully loaded into memory.\n", filename);

    return 0;
}