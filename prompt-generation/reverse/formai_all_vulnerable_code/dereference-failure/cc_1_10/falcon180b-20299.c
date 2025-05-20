//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 100) // 100 MB

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} FileData;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    if (filesize == 0 || filesize > MAX_FILE_SIZE) {
        printf("Invalid file size\n");
        fclose(file);
        return 1;
    }

    rewind(file);

    FileData *data = malloc(sizeof(FileData));
    if (data == NULL) {
        printf("Memory error\n");
        fclose(file);
        return 1;
    }

    data->filename = strdup(argv[1]);
    data->data = malloc(filesize);
    if (data->filename == NULL || data->data == NULL) {
        printf("Memory error\n");
        free(data->filename);
        free(data->data);
        free(data);
        fclose(file);
        return 1;
    }

    if (fread(data->data, filesize, 1, file)!= 1) {
        printf("Error reading file\n");
        free(data->filename);
        free(data->data);
        free(data);
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("File %s recovered successfully\n", data->filename);

    return 0;
}