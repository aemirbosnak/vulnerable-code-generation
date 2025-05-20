//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare files
int compareFiles(const void *a, const void *b) {
    const char *filename1 = (const char *)a;
    const char *filename2 = (const char *)b;
    
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");
    
    int count1 = 0;
    int count2 = 0;
    
    while (fscanf(file1, "%d", &count1)!= EOF && fscanf(file2, "%d", &count2)!= EOF) {
        if (count1!= count2) {
            return 1;
        }
    }
    
    fclose(file1);
    fclose(file2);
    
    return 0;
}

// Function to copy files
void copyFiles(const char *source, const char *destination) {
    FILE *sourceFile = fopen(source, "r");
    FILE *destinationFile = fopen(destination, "w");
    
    int count = 0;
    
    while (fscanf(sourceFile, "%d", &count)!= EOF) {
        fprintf(destinationFile, "%d\n", count);
    }
    
    fclose(sourceFile);
    fclose(destinationFile);
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";
    
    if (strcmp(source, destination) == 0) {
        printf("Files are the same.\n");
    } else {
        qsort(source, strlen(source), sizeof(const char *), compareFiles);
        copyFiles(source, destination);
        printf("Files copied.\n");
    }
    
    return 0;
}