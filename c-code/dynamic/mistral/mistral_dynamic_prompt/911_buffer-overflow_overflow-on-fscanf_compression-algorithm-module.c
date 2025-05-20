#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    char *data;
    int size;
} File;

File *read_file(const char *filename) {
    File *file = malloc(sizeof(File));
    FILE *f = fopen(filename, "r");
    fscanf(f, "%s", file->name);
    file->data = malloc(512);
    fread(file->data, sizeof(char), 512, f);
    file->size = ftell(f);
    rewind(f);
    return file;
}

void free_file(File *file) {
    free(file->data);
    free(file);
}

int main() {
    File *input = read_file("large_input.txt");
    FILE *output = fopen("compressed.bin", "wb");
    for (int i = 0; i < input->size; ++i) {
        fputc((char)i & 0x7f, output);
        if (input->data[i] == 0x7f) {
            fputc((char)(i >> 7), output);
            fputc((char)((i & 0xff) >> 1), output);
            fputc((char)(input->data[i + 1] & 0x7f), output);
            i++;
        }
    }
    free_file(input);
    fclose(output);
    return 0;
}
