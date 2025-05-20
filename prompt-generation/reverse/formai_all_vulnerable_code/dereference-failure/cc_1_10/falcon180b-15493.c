//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA_SIZE 1000000

typedef struct {
    char* data;
    size_t size;
} Data;

void read_data(Data* data, FILE* file) {
    char buffer[MAX_DATA_SIZE];
    size_t read = 0;

    while ((read = fread(buffer, 1, MAX_DATA_SIZE, file)) > 0) {
        char* new_data = realloc(data->data, data->size + read);
        if (new_data == NULL) {
            printf("Error: Could not allocate memory.\n");
            exit(1);
        }
        data->data = new_data;
        memcpy(data->data + data->size, buffer, read);
        data->size += read;
    }
}

void recover_data(Data* data) {
    char* start = data->data;
    size_t size = data->size;

    while (size > 0) {
        char* end = memchr(start, '\0', size);
        if (end == NULL) {
            printf("Error: Corrupted data.\n");
            exit(1);
        }
        *end = '\0';
        printf("%s\n", start);
        start = end + 1;
        size -= (end - start) + 1;
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Data data = {NULL, 0};
    read_data(&data, file);
    fclose(file);

    recover_data(&data);

    free(data.data);
    return 0;
}