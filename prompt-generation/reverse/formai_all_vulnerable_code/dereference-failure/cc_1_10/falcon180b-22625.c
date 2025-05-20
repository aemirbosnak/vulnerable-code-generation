//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define MAX_FILE_SIZE (100 * 1024 * 1024) // 100 MB

typedef struct {
    FILE *file;
    char *buffer;
    int block_size;
    int block_count;
    int current_block;
    int current_offset;
} FileHandle;

void init_file_handle(FileHandle *handle, const char *filename) {
    handle->file = fopen(filename, "rb");
    if (!handle->file) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }
    handle->buffer = malloc(BLOCK_SIZE);
    handle->block_size = BLOCK_SIZE;
    handle->block_count = 0;
    handle->current_block = 0;
    handle->current_offset = 0;
}

void read_block(FileHandle *handle) {
    if (handle->current_offset == 0) {
        handle->current_block++;
    }
    fseek(handle->file, handle->current_block * BLOCK_SIZE, SEEK_SET);
    fread(handle->buffer, BLOCK_SIZE, 1, handle->file);
    handle->current_offset = 0;
}

int main() {
    FileHandle handle;
    init_file_handle(&handle, "test.txt");

    char *data = malloc(MAX_FILE_SIZE);
    int data_size = 0;

    while (1) {
        int bytes_read = fread(data + data_size, 1, BLOCK_SIZE - handle.current_offset, handle.file);
        if (bytes_read == 0) {
            break;
        }
        data_size += bytes_read;
        handle.current_offset += bytes_read;
        if (handle.current_offset == BLOCK_SIZE) {
            read_block(&handle);
        }
    }

    fclose(handle.file);
    printf("Data recovered successfully!\n");
    printf("Size of recovered data: %d bytes\n", data_size);

    return 0;
}