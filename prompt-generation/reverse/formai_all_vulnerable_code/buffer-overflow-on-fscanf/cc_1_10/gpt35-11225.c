//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_SIZE 50
#define MAX_SIZE 20

typedef struct {
    char name[MAX_FILENAME_SIZE];
    long size;
} File;

void sort_files(File *files, int num_files) {
    int i, j;
    File temp;

    for (i = 0; i < num_files - 1; i++) {
        for (j = i + 1; j < num_files; j++) {
            if (files[i].size < files[j].size) {
                temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

int main() {
    // Declare variables.
    int i;
    long total_size = 0;
    int num_files = 0;
    File files[MAX_FILES];
    char filename[MAX_FILENAME_SIZE];
    char size_as_string[MAX_SIZE];
    FILE *fp;

    // Open directory and read files.
    system("dir /a /b > files.txt");
    fp = fopen("files.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp, "%s", filename) == 1) {
        if (strcmp(filename, "files.txt") != 0) {
            strcpy(files[num_files].name, filename);
            fseek(fp, 0L, SEEK_CUR);
            fscanf(fp, "%ld", &files[num_files].size);
            total_size += files[num_files].size;
            num_files++;
        }
    }
    fclose(fp);

    // Sort files by size.
    sort_files(files, num_files);

    // Print summary information.
    printf("Total Size: %ld bytes\n", total_size);
    printf("Largest Files:\n");
    for (i = 0; i < num_files && i < 10; i++) {
        sprintf(size_as_string, "%ld", files[i].size);
        printf("%s Bytes - %s\n", size_as_string, files[i].name);
    }

    // Delete temporary file.
    system("del files.txt");

    return 0;
}