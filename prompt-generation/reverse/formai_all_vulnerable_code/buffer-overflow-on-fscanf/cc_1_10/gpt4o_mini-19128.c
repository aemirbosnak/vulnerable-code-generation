//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    long size;
} File;

void displayFiles(File files[], int count) {
    printf("O fair and gentle users, behold the files:\n");
    printf("==========================================\n");
    printf("| %-20s | %-10s |\n", "File Name", "Size (Bytes)");
    printf("==========================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-10ld |\n", files[i].name, files[i].size);
    }
    
    printf("==========================================\n");
}

long getTotalSize(File files[], int count) {
    long total = 0;
    for (int i = 0; i < count; i++) {
        total += files[i].size;
    }
    return total;
}

void analyzeDiskSpace(char *path) {
    FILE *fp;
    char command[FILENAME_LENGTH];
    
    snprintf(command, sizeof(command), "du -b %s/* > file_sizes.txt", path);
    system(command); // Runs the du command to get file sizes
    
    fp = fopen("file_sizes.txt", "r");
    if (!fp) {
        printf("Alas, the file_sizes.txt could not be opened.\n");
        return;
    }
    
    File files[MAX_FILES];
    int count = 0;
    
    while (fscanf(fp, "%ld %s", &files[count].size, files[count].name) != EOF && count < MAX_FILES) {
        count++;
    }
    
    fclose(fp);
    
    displayFiles(files, count);
    
    long totalSize = getTotalSize(files, count);
    printf("O sweetest fortune! The total disk space used is: %ld bytes\n", totalSize);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("O wretched assumption! Thou must supply a path to analyze!\n");
        printf("Usage: %s <path_to_directory>\n", argv[0]);
        return 1;
    }
    
    analyzeDiskSpace(argv[1]);
    
    return 0;
}