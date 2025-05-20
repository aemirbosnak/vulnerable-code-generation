//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *filename;
    int size;
    char *data;
} file_t;

void read_file(file_t *file) {
    FILE *fp = fopen(file->filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", file->filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error: could not allocate memory for file '%s'\n", file->filename);
        exit(1);
    }

    fread(file->data, file->size, 1, fp);
    fclose(fp);
}

void write_file(file_t *file) {
    FILE *fp = fopen(file->filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", file->filename);
        exit(1);
    }

    fwrite(file->data, file->size, 1, fp);
    fclose(fp);
}

int is_valid_data(char *data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] == 0xff) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    file_t input_file, output_file;

    input_file.filename = argv[1];
    read_file(&input_file);

    if (!is_valid_data(input_file.data, input_file.size)) {
        printf("Error: input file contains invalid data\n");
        exit(1);
    }

    output_file.filename = argv[2];
    output_file.size = input_file.size;
    output_file.data = malloc(output_file.size);
    if (output_file.data == NULL) {
        printf("Error: could not allocate memory for output file\n");
        exit(1);
    }

    memcpy(output_file.data, input_file.data, output_file.size);
    write_file(&output_file);

    printf("Data recovery successful!\n");
    return 0;
}