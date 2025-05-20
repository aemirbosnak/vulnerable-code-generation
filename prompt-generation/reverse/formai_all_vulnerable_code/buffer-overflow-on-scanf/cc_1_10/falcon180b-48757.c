//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

struct file_header {
    char magic[4];
    int version;
    int num_files;
    int num_dirs;
};

struct file_entry {
    char name[256];
    int size;
    int offset;
};

void read_file(FILE *fp, void *buffer, int size) {
    int bytes_read = fread(buffer, 1, size, fp);
    if (bytes_read!= size) {
        printf("Error reading file\n");
        exit(1);
    }
}

int main() {
    FILE *fp;
    char filename[256];
    struct file_header header;
    struct file_entry entry;
    int i;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    read_file(fp, &header, sizeof(header));

    if (strcmp(header.magic, "DATA")!= 0) {
        printf("Invalid file format\n");
        exit(1);
    }

    printf("File version: %d\n", header.version);
    printf("Number of files: %d\n", header.num_files);
    printf("Number of directories: %d\n", header.num_dirs);

    for (i = 0; i < header.num_files; i++) {
        read_file(fp, &entry, sizeof(entry));

        printf("File %d:\n", i+1);
        printf("Name: %s\n", entry.name);
        printf("Size: %d bytes\n", entry.size);
        printf("Offset: %d bytes\n", entry.offset);
        printf("\n");
    }

    fclose(fp);
    return 0;
}