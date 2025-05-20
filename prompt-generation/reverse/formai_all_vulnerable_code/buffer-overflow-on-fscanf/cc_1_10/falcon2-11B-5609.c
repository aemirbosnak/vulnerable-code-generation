//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 10000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_extension[3];
    int file_size;
} FileInfo;

int compare_files(const void *a, const void *b) {
    FileInfo *file_a = (FileInfo*)a;
    FileInfo *file_b = (FileInfo*)b;
    return strcmp(file_a->file_name, file_b->file_name);
}

void scan_directory(const char *directory, FileInfo *files, int num_files) {
    FILE *fp;
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_extension[3];
    int file_size;

    fp = fopen(directory, "r");
    if (fp == NULL) {
        printf("Error: Failed to open directory.\n");
        return;
    }

    while (fscanf(fp, "%s %s %d", file_name, file_extension, &file_size)!= EOF) {
        FileInfo new_file;
        strcpy(new_file.file_name, file_name);
        strcpy(new_file.file_extension, file_extension);
        new_file.file_size = file_size;

        qsort(files, num_files, sizeof(FileInfo), compare_files);

        if (strstr(new_file.file_extension, ".exe")!= NULL) {
            printf("File detected: %s\n", new_file.file_name);
            fclose(fp);
            exit(1);
        }

        strcpy(files[num_files - 1].file_name, new_file.file_name);
        strcpy(files[num_files - 1].file_extension, new_file.file_extension);
        files[num_files - 1].file_size = file_size;
        num_files++;
    }

    fclose(fp);

    printf("Scan complete.\n");
}

int main() {
    FileInfo files[MAX_FILE_SIZE];
    int num_files = 0;
    scan_directory("path/to/directory", files, num_files);
    return 0;
}