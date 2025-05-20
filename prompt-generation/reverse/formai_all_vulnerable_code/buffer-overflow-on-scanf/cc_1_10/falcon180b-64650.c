//Falcon-180B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_FILES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int file_size;
} File;

void create_file(File *file) {
    printf("Enter file name: ");
    scanf("%s", file->name);
    printf("Enter file size: ");
    scanf("%d", &file->file_size);
}

void read_file(File *file) {
    printf("File name: %s\n", file->name);
    printf("File size: %d\n", file->file_size);
}

void write_file(File *file, FILE *fp) {
    fprintf(fp, "File name: %s\n", file->name);
    fprintf(fp, "File size: %d\n", file->file_size);
}

int main() {
    int num_files, i;
    FILE *fp;
    File files[MAX_NUM_FILES];

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    fp = fopen("files.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    for (i = 0; i < num_files; i++) {
        create_file(&files[i]);
        write_file(&files[i], fp);
    }

    fclose(fp);

    printf("Files created successfully!\n");

    return 0;
}