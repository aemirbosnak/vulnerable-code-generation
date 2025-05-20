//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char filename[128];
    char buffer[BUFFER_SIZE];
    int size;
} FILE_DATA;

void read_file(FILE *file, char *filename) {
    FILE_DATA data;
    strncpy(data.filename, filename, 128);
    data.size = 0;

    while (!feof(file)) {
        if (fgets(data.buffer + data.size, BUFFER_SIZE - data.size, file) == NULL) {
            fprintf(stderr, "Error reading file: %s\n", filename);
            exit(1);
        }
        data.size += strlen(data.buffer + data.size);
    }

    data.buffer[data.size] = '\0';
}

void write_file(FILE *file, char *filename, char *buffer) {
    fprintf(file, "Filename: %s\nData:\n%s", filename, buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    FILE_DATA data;
    read_file(file, argv[1]);

    char *recovered_data = malloc(data.size + 1);
    strncpy(recovered_data, data.buffer, data.size);
    recovered_data[data.size] = '\0';

    write_file(stdout, data.filename, recovered_data);

    free(recovered_data);
    fclose(file);

    return 0;
}