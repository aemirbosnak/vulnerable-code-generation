//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define VIRUS_SIGNATURE "VIRUS"

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

int is_virus(unsigned char *data) {
    return strstr((char *)data, VIRUS_SIGNATURE)!= NULL;
}

void scan_file(File *file) {
    if (is_virus(file->data)) {
        printf("Virus found in %s\n", file->name);
    }
}

int read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    if (file->size > MAX_FILE_SIZE) {
        printf("Error: file '%s' is too large\n", filename);
        return 1;
    }

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error: could not allocate memory for file '%s'\n", filename);
        return 1;
    }

    size_t bytes_read = fread(file->data, 1, file->size, fp);
    if (bytes_read!= file->size) {
        printf("Error: could not read entire file '%s'\n", filename);
        return 1;
    }

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file = {0};
    if (read_file(argv[1], &file)) {
        return 1;
    }

    scan_file(&file);

    free(file.data);
    return 0;
}