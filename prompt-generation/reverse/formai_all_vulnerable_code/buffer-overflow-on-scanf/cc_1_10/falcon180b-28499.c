//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_SIZE 100000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *backup_file;
    int file_size;
    int backup_file_size;
} File;

int main() {
    int num_files;
    File files[10]; // assume max 10 files

    // get number of files from user
    printf("Enter number of files: ");
    scanf("%d", &num_files);

    // get file names and sizes from user
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i+1);
        scanf("%s", files[i].file_name);
        printf("Enter backup file name for file %d: ", i+1);
        scanf("%s", files[i].backup_file_name);
        printf("Enter file size for file %d: ", i+1);
        scanf("%d", &files[i].file_size);
    }

    // open files and backup files
    for (int i = 0; i < num_files; i++) {
        files[i].file = fopen(files[i].file_name, "r");
        if (files[i].file == NULL) {
            printf("Error: could not open file %s\n", files[i].file_name);
            exit(1);
        }
        files[i].backup_file = fopen(files[i].backup_file_name, "w");
        if (files[i].backup_file == NULL) {
            printf("Error: could not open backup file %s\n", files[i].backup_file_name);
            exit(1);
        }
    }

    // backup files
    for (int i = 0; i < num_files; i++) {
        char buffer[MAX_FILE_SIZE];
        int bytes_read = 0;
        while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, files[i].file)) > 0) {
            files[i].backup_file_size += bytes_read;
            fwrite(buffer, 1, bytes_read, files[i].backup_file);
        }
        if (ferror(files[i].file)) {
            printf("Error: could not read file %s\n", files[i].file_name);
            exit(1);
        }
        if (ferror(files[i].backup_file)) {
            printf("Error: could not write backup file %s\n", files[i].backup_file_name);
            exit(1);
        }
        printf("File %s backed up to %s\n", files[i].file_name, files[i].backup_file_name);
    }

    return 0;
}