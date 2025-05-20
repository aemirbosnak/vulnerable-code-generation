//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    File file = {0};
    file.name = argv[1];

    FILE *fp = fopen(file.name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", file.name);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    rewind(fp);

    if (file.size > MAX_FILE_SIZE) {
        fprintf(stderr, "File '%s' is too large (max size is 1MB)\n", file.name);
        fclose(fp);
        return 1;
    }

    file.data = malloc(file.size);
    if (file.data == NULL) {
        fprintf(stderr, "Error allocating memory for file '%s'\n", file.name);
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file.data, 1, file.size, fp);
    if (bytes_read!= file.size) {
        fprintf(stderr, "Error reading file '%s'\n", file.name);
        free(file.data);
        fclose(fp);
        return 1;
    }

    int virus_found = 0;
    const unsigned char virus_signature[] = {0x4d, 0x5a, 0x90, 0x00};
    const size_t virus_signature_size = sizeof(virus_signature) - 1;

    for (size_t i = 0; i < file.size - virus_signature_size; i++) {
        if (memcmp(file.data + i, virus_signature, virus_signature_size) == 0) {
            fprintf(stdout, "Virus found in file '%s'\n", file.name);
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        fprintf(stdout, "File '%s' is clean\n", file.name);
    }

    free(file.data);
    fclose(fp);
    return 0;
}