//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB

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

    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);

    if (filesize > MAX_FILE_SIZE) {
        printf("Error: File size exceeds limit of 1MB\n");
        fclose(fp);
        return 1;
    }

    fseek(fp, 0, SEEK_SET);
    File file = {
       .name = filename,
       .data = malloc(filesize),
       .size = filesize
    };

    if (!file.data) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file.data, 1, filesize, fp);

    if (bytes_read!= filesize) {
        printf("Error: Could not read entire file\n");
        free(file.data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    unsigned char *data = file.data;
    size_t datasize = file.size;

    while (datasize > 0) {
        int i;
        for (i = 0; i < datasize - 3; i++) {
            if (data[i] == 0xE8 && data[i + 1] == 0x00 && data[i + 2] == 0x00 && data[i + 3] == 0x00) {
                printf("Possible virus found at offset %lu\n", i);
            }
        }
        data += datasize - 4;
        datasize -= 4;
    }

    free(file.data);
    return 0;
}