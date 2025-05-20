#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    char *data;
} FileData;

FileData read_file(char *path) {
    FILE *file = fopen(path, "rb");
    FileData fd;
    size_t file_size;

    if (file) {
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        rewind(file);

        fd.filename = strdup(path);
        fd.data = malloc(file_size);
        fread(fd.data, sizeof(char), file_size, file);
        fclose(file);
    }

    return fd;
}

void save_file(FileData fd) {
    FILE *file = fopen(fd.filename, "wb");
    fwrite(fd.data, sizeof(char), strlen(fd.data), file);
    free(fd.filename);
    free(fd.data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s upload <filename> <data>\n", argv[0]);
        return 1;
    }

    FileData fd = read_file(argv[1]);
    save_file(fd);

    // This pointer is dereferenced with NULL content
    printf("%s\n", fd.filename);

    return 0;
}
