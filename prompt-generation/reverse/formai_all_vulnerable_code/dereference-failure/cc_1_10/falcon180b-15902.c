//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (10 * 1024 * 1024) // 10 MB

typedef struct {
    char *filename;
    char *data;
    size_t size;
} FileData;

int main() {
    char *filename = "test.txt";
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    size_t file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file is too large (%zu bytes)\n", file_size);
        fclose(file);
        return 1;
    }

    FileData *data = malloc(sizeof(FileData));
    data->filename = strdup(filename);
    data->data = malloc(file_size);
    data->size = file_size;

    if (fread(data->data, 1, file_size, file)!= file_size) {
        printf("Error: cannot read file %s\n", filename);
        free(data->filename);
        free(data->data);
        free(data);
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Successfully recovered file %s\n", filename);
    printf("Size: %zu bytes\n", file_size);

    return 0;
}