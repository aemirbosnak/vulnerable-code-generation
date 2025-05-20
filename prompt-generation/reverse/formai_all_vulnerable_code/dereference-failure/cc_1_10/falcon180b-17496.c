//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // Buffer size for reading and writing files

void sync_files(char *source_file, char *destination_file) {
    FILE *source_fp, *destination_fp;
    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    // Open source and destination files
    source_fp = fopen(source_file, "rb");
    if (source_fp == NULL) {
        printf("Error: Could not open source file %s\n", source_file);
        exit(1);
    }

    destination_fp = fopen(destination_file, "wb");
    if (destination_fp == NULL) {
        printf("Error: Could not open destination file %s\n", destination_file);
        exit(1);
    }

    // Read from source file and write to destination file
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_fp)) > 0) {
        bytes_written = fwrite(buffer, sizeof(char), bytes_read, destination_fp);
        if (bytes_written!= bytes_read) {
            printf("Error: Failed to write to destination file %s\n", destination_file);
            exit(1);
        }
    }

    // Close source and destination files
    fclose(source_fp);
    fclose(destination_fp);

    printf("Files synchronized successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}