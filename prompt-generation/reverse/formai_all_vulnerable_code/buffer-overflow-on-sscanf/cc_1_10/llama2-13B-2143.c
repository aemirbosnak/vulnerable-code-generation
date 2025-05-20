//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 50
#define MAX_LINE_LENGTH 100

// Structure to hold the file metadata
typedef struct {
    char name[MAX_FILE_NAME];
    long size;
    long lastModified;
} fileMeta;

// Function to read the file metadata
fileMeta readFileMeta(const char *filePath) {
    fileMeta meta;
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(filePath, "r");

    // Read the file name and size
    fgets(line, MAX_LINE_LENGTH, file);
    sscanf(line, "%s %ld", meta.name, &meta.size);

    // Read the last modified time
    fgets(line, MAX_LINE_LENGTH, file);
    sscanf(line, "%ld", &meta.lastModified);

    fclose(file);
    return meta;
}

// Function to write the file metadata
void writeFileMeta(const char *filePath, const fileMeta *meta) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(filePath, "w");

    // Write the file name
    fprintf(file, "%s\n", meta->name);

    // Write the file size
    fprintf(file, "%ld\n", meta->size);

    // Write the last modified time
    fprintf(file, "%ld\n", meta->lastModified);

    fclose(file);
}

int main() {
    // Example usage of the file metadata functions
    fileMeta meta;
    char filePath[MAX_FILE_NAME];

    // Read the file metadata for a random file
    sprintf(filePath, "%s/random_file.txt", getenv("HOME"));
    meta = readFileMeta(filePath);
    printf("File name: %s\n", meta.name);
    printf("File size: %ld\n", meta.size);
    printf("Last modified: %ld\n", meta.lastModified);

    // Modify the file metadata for the same file
    meta.lastModified = time(NULL) + 1000;
    writeFileMeta(filePath, &meta);

    // Read the updated file metadata
    meta = readFileMeta(filePath);
    printf("Updated file name: %s\n", meta.name);
    printf("Updated file size: %ld\n", meta.size);
    printf("Updated last modified: %ld\n", meta.lastModified);

    return 0;
}