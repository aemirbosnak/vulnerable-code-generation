//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *filename;
    char *buffer;
    size_t size;
} FileData;

void read_file(const char *filename, FileData *file_data) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_data->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_data->size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (%zu bytes).\n", filename, file_data->size);
        fclose(file);
        exit(1);
    }

    file_data->buffer = malloc(file_data->size + 1);
    if (file_data->buffer == NULL) {
        printf("Error: Could not allocate memory for file '%s'.\n", filename);
        fclose(file);
        exit(1);
    }

    fread(file_data->buffer, file_data->size, 1, file);
    fclose(file);

    file_data->buffer[file_data->size] = '\0'; // null-terminate the buffer
    file_data->filename = strdup(filename);
}

int scan_file(const char *filename, const char *signature) {
    FileData file_data;
    read_file(filename, &file_data);

    char *buffer_ptr = file_data.buffer;
    const char *signature_ptr = signature;
    while (*signature_ptr!= '\0') {
        if (tolower(*buffer_ptr)!= tolower(*signature_ptr)) {
            return 0;
        }
        buffer_ptr++;
        signature_ptr++;
    }

    printf("Virus signature found in file '%s'.\n", file_data.filename);
    free(file_data.buffer);
    free(file_data.filename);
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file> <signature>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *signature = argv[2];

    scan_file(filename, signature);

    return 0;
}