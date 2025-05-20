//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* filename;
    int size;
} file_t;

void read_file(file_t* file, const char* path) {
    FILE* fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", path);
        return;
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->filename = (char*)malloc(sizeof(char) * (file->size + 1));
    if (file->filename == NULL) {
        printf("Error allocating memory for filename\n");
        fclose(fp);
        return;
    }

    fread(file->filename, 1, file->size, fp);
    fclose(fp);
}

void scan_file(file_t* file) {
    char* buffer = (char*)malloc(sizeof(char) * 1024);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        free(file->filename);
        return;
    }

    int i = 0;
    for (i = 0; i < file->size; i++) {
        if (file->filename[i] == 0x41 && file->filename[i + 1] == 0x42 &&
            file->filename[i + 2] == 0x43 && file->filename[i + 3] == 0x44) {
            break;
        }
    }

    if (i >= file->size) {
        printf("No viruses found\n");
    } else {
        printf("Virus found at index %d\n", i);
    }

    free(buffer);
    free(file->filename);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t file;
    read_file(&file, argv[1]);
    scan_file(&file);

    return 0;
}