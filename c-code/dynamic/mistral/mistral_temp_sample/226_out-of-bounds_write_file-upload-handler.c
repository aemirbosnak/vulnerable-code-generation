#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 10

typedef struct File {
    char name[256];
    FILE *fp;
    size_t size;
} File;

File files[MAX_FILES];
int num_files = 0;

void handle_file(File *file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file->fp)) > 0) {
        size_t dest_index = file->size;
        file->size += bytes_read;

        memcpy((void *)(file->name + dest_index), buffer, bytes_read);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 2;
    }

    File new_file;
    strcpy(new_file.name, argv[1]);
    new_file.fp = fp;
    new_file.size = 0;

    for (int i = 0; i < num_files; ++i) {
        if (strcmp(files[i].name, new_file.name) == 0) {
            printf("Error: File already exists\n");
            fclose(new_file.fp);
            return 3;
        }
    }

    files[num_files++] = new_file;
    handle_file(&files[num_files - 1]);

    fclose(fp);

    return 0;
}
