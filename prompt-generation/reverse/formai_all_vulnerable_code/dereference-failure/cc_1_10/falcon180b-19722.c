//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} FileData;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    if (filesize == 0) {
        printf("File is empty\n");
        fclose(file);
        return 0;
    }

    if (filesize > MAX_FILE_SIZE) {
        printf("File is too large\n");
        fclose(file);
        return 1;
    }

    FileData *data = malloc(sizeof(FileData));
    data->filename = strdup(filename);
    data->data = malloc(filesize);
    data->size = filesize;

    fseek(file, 0, SEEK_SET);
    fread(data->data, 1, filesize, file);
    fclose(file);

    printf("File %s recovered successfully\n", filename);

    return 0;
}