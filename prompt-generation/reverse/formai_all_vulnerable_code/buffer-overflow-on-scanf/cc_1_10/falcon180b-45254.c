//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to synchronize files
void sync_files(char* source_file, char* target_file) {
    FILE* source_fp = fopen(source_file, "r");
    FILE* target_fp = fopen(target_file, "r");

    // Check if source or target file is empty
    if (source_fp == NULL || target_fp == NULL) {
        printf("Error: One of the files is empty.\n");
        exit(1);
    }

    char ch;

    // Check if files have different sizes
    fseek(source_fp, 0, SEEK_END);
    long source_size = ftell(source_fp);
    fseek(target_fp, 0, SEEK_END);
    long target_size = ftell(target_fp);

    if (source_size!= target_size) {
        printf("Error: Files have different sizes.\n");
        exit(1);
    }

    // Rewind source and target files
    rewind(source_fp);
    rewind(target_fp);

    // Read and compare files
    while ((ch = fgetc(source_fp))!= EOF) {
        if (fgetc(target_fp)!= ch) {
            printf("Files are different.\n");
            exit(1);
        }
    }

    printf("Files are synchronized.\n");
    exit(0);
}

int main() {
    char source_file[50], target_file[50];

    // Get file names from user
    printf("Enter source file name: ");
    scanf("%s", source_file);
    printf("Enter target file name: ");
    scanf("%s", target_file);

    // Synchronize files
    sync_files(source_file, target_file);

    return 0;
}