//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int size;
    char *buffer;
} file_t;

void read_file(file_t *file) {
    FILE *fp = fopen(file->filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file->filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    file->buffer = malloc(file->size + 1);
    fread(file->buffer, file->size, 1, fp);
    fclose(fp);
}

void write_file(file_t *file) {
    FILE *fp = fopen(file->filename, "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", file->filename);
        exit(1);
    }

    fwrite(file->buffer, file->size, 1, fp);
    fclose(fp);
}

int main() {
    int num_files = 0;
    file_t *files = NULL;

    printf("Enter number of files to recover:\n");
    scanf("%d", &num_files);

    files = malloc(num_files * sizeof(file_t));

    for (int i = 0; i < num_files; i++) {
        printf("Enter filename for file %d:\n", i+1);
        scanf("%s", files[i].filename);

        read_file(&files[i]);
    }

    printf("Files successfully recovered!\n");

    for (int i = 0; i < num_files; i++) {
        write_file(&files[i]);
        printf("Recovered file %s\n", files[i].filename);
    }

    return 0;
}