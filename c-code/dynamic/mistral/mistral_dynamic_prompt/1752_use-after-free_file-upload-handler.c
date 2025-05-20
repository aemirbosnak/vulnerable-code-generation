#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileData {
    char *filename;
    char *data;
    size_t size;
} FileData;

FileData* parse_file(char* filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    FileData *data = (FileData*)malloc(sizeof(FileData));
    data->filename = strdup(filename);
    data->data = (char*)malloc(size);
    data->size = size;

    fread(data->data, size, 1, file);
    fclose(file);

    return data;
}

void free_file_data(FileData *file_data) {
    free(file_data->filename);
    free(file_data->data);
    free(file_data);
}

int main() {
    FileData *file1 = parse_file("example.txt");
    FileData *file2 = parse_file("another_example.txt");

    // Handle the uploaded files as needed...

    free_file_data(file1);
    free_file_data(file2);

    return 0;
}
