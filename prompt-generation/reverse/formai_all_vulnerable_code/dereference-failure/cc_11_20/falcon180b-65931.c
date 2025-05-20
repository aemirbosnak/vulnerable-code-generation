//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: random
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
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    if (filesize > MAX_FILE_SIZE) {
        printf("Error: file is too large (%zu bytes)\n", filesize);
        fclose(fp);
        return 1;
    }

    rewind(fp);
    File file = {
       .name = filename,
       .data = malloc(filesize),
       .size = filesize
    };

    if (file.data == NULL) {
        printf("Error: could not allocate memory for file data\n");
        fclose(fp);
        return 1;
    }

    if (fread(file.data, 1, filesize, fp)!= filesize) {
        printf("Error: could not read file data\n");
        free(file.data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    unsigned char *p = file.data;
    while (p < file.data + file.size) {
        if (*p == 0xE8) { // E8: call
            p += 5; // skip call instruction and 32-bit displacement
            unsigned int offset = *(unsigned int *)p;
            p += 4; // skip 32-bit displacement
            if (offset > 0 && offset < file.size) {
                if (*(p + offset) == 0xE8) { // E8: call
                    printf("Possible virus detected in file '%s' at offset %u\n", file.name, offset);
                }
            }
        }
        p++;
    }

    free(file.data);
    return 0;
}