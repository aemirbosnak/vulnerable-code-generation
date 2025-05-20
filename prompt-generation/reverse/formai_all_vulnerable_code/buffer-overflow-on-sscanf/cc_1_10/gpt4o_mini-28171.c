//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define FILE_NAME_LENGTH 256
#define MAX_RECOVERED_FILES 50

typedef struct {
    char name[FILE_NAME_LENGTH];
    long size;
    long address;
} FileMetadata;

void printHeader() {
    printf("***** Simple Data Recovery Tool *****\n");
    printf("~~~ Recovering lost files from disk ~~~\n\n");
}

void readDiskBlock(FILE *disk, long offset, char *buffer) {
    fseek(disk, offset, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, disk);
}

int parseFileMetadata(char *buffer, FileMetadata *file) {
    if (strncmp(buffer, "FILE", 4) == 0) {
        sscanf(buffer + 4, "%s %ld", file->name, &file->size);
        file->address = strlen(buffer); // simplistic simulation for the demo
        return 1;
    }
    return 0;
}

void displayRecoveredFiles(FileMetadata **files, int count) {
    printf("\nRecovered Files:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Size: %ld bytes, Address: %ld\n", files[i]->name, files[i]->size, files[i]->address);
    }
}

void freeRecoveredFiles(FileMetadata **files, int count) {
    for (int i = 0; i < count; i++) {
        free(files[i]);
    }
}

int recoverFiles(const char *diskPath) {
    FILE *disk = fopen(diskPath, "rb");
    if (disk == NULL) {
        perror("Failed to open disk");
        return -1;
    }

    char buffer[BLOCK_SIZE];
    FileMetadata *recoveredFiles[MAX_RECOVERED_FILES];
    int fileCount = 0;

    for (long offset = 0; offset < BLOCK_SIZE * MAX_FILES; offset += BLOCK_SIZE) {
        readDiskBlock(disk, offset, buffer);
        FileMetadata *file = (FileMetadata *)malloc(sizeof(FileMetadata));
        if (parseFileMetadata(buffer, file)) {
            if (fileCount < MAX_RECOVERED_FILES) {
                recoveredFiles[fileCount++] = file;
            } else {
                free(file);
            }
        } else {
            free(file); // Free if no valid file metadata found
        }
    }

    fclose(disk);
    displayRecoveredFiles(recoveredFiles, fileCount);
    freeRecoveredFiles(recoveredFiles, fileCount);
    return 0;
}

int main(int argc, char *argv[]) {
    printHeader();

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <disk_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (recoverFiles(argv[1]) != 0) {
        fprintf(stderr, "Recovery process failed.\n");
        return EXIT_FAILURE;
    }

    printf("\nRecovery process completed successfully!\n");
    return EXIT_SUCCESS;
}