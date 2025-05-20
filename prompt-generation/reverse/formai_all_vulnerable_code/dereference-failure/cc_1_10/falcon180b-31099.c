//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

void read_file(const char *filename, File *file) {
    FILE *fp;
    fp = fopen(filename, "rb");

    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    file->data = malloc(file->size);
    if (!file->data) {
        printf("Error: could not allocate memory for file '%s'\n", filename);
        exit(1);
    }

    fread(file->data, 1, file->size, fp);
    fclose(fp);

    file->name = strdup(filename);
}

int is_infected(const unsigned char *data, size_t size) {
    const unsigned char virus_signature[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a };
    const size_t virus_signature_size = sizeof(virus_signature) - 1;

    for (size_t i = 0; i < size - virus_signature_size; i++) {
        if (memcmp(data + i, virus_signature, virus_signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(const File *file) {
    if (is_infected(file->data, file->size)) {
        printf("File '%s' is infected with a virus!\n", file->name);
    } else {
        printf("File '%s' is clean.\n", file->name);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file;
    read_file(argv[1], &file);
    scan_file(&file);

    free(file.data);
    free(file.name);

    return 0;
}