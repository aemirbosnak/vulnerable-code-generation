//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

struct file_info {
    char *filename;
    size_t filesize;
    char *buffer;
};

void read_file(struct file_info *file) {
    FILE *fp = fopen(file->filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file->filename);
        exit(1);
    }

    file->filesize = fseek(fp, 0, SEEK_END);
    if (file->filesize == -1) {
        printf("Error: Could not get file size for %s\n", file->filename);
        exit(1);
    }

    rewind(fp);
    file->buffer = malloc(file->filesize);
    if (file->buffer == NULL) {
        printf("Error: Could not allocate memory for file %s\n", file->filename);
        exit(1);
    }

    size_t bytes_read = fread(file->buffer, 1, file->filesize, fp);
    if (bytes_read!= file->filesize) {
        printf("Error: Could not read entire file %s\n", file->filename);
        exit(1);
    }

    fclose(fp);
}

void scan_file(struct file_info *file, char *virus_pattern) {
    char *buffer_ptr = file->buffer;
    size_t buffer_size = file->filesize;

    while (buffer_size > 0) {
        size_t pattern_len = strlen(virus_pattern);
        size_t buffer_len = buffer_size < pattern_len? buffer_size : pattern_len;
        if (memcmp(buffer_ptr, virus_pattern, buffer_len) == 0) {
            printf("Virus found in file %s at offset %zu\n", file->filename, buffer_ptr - file->buffer);
            exit(1);
        }
        buffer_ptr += buffer_len;
        buffer_size -= buffer_len;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file> <virus_pattern>\n", argv[0]);
        exit(1);
    }

    struct file_info file;
    file.filename = argv[1];

    read_file(&file);
    scan_file(&file, argv[2]);

    free(file.buffer);
    return 0;
}