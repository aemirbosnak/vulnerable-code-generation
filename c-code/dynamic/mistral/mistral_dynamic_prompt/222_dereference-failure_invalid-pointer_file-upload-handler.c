#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[256];
    char* data;
    size_t size;
} File;

void read_file(const char* path, File* file) {
    FILE* f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    file->data = malloc(size);
    fseek(f, 0, SEEK_SET);
    fread(file->data, size, 1, f);
    fclose(f);
    file->size = size;
}

void process_file(File* file) {
    printf("Processing file: %s\n", file->filename);
    // Dereference invalid pointer here
    int some_variable = *((int*)(file->data + file->size));
}

int main() {
    File file;
    strcpy(file.filename, "test.txt");
    read_file("test.txt", &file);
    process_file(&file);
    free(file.data);
    return 0;
}
