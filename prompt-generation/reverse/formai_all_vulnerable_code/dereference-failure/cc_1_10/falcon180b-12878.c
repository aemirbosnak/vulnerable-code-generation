//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char *name;
    unsigned char *data;
    int size;
} file_t;

void read_file(const char *filename, file_t *file) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    if (file->size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (%d bytes)\n", filename, file->size);
        fclose(fp);
        exit(1);
    }

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error: Could not allocate memory for file '%s'\n", filename);
        fclose(fp);
        exit(1);
    }

    if (fread(file->data, file->size, 1, fp)!= 1) {
        printf("Error: Could not read file '%s'\n", filename);
        free(file->data);
        fclose(fp);
        exit(1);
    }

    file->name = strdup(filename);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t file;
    read_file(argv[1], &file);

    unsigned char *data = file.data;
    int size = file.size;

    int i = 0;
    while (i < size) {
        if (data[i] == 0xE9) { // check for jump instruction
            if (i + 5 >= size) { // make sure there is enough data for the instruction
                break;
            }

            unsigned int target = *(unsigned int *)(data + i + 1);
            if (target < i + 5 || target >= size) { // make sure the target is within the file
                printf("Warning: Suspicious jump at offset 0x%X in file '%s'\n", i, file.name);
            }
        }

        i++;
    }

    free(file.data);
    free(file.name);

    return 0;
}