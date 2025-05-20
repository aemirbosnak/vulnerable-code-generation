//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
} File;

int main() {
    int num_files;
    char **filenames;
    File *files;

    // Read in the list of filenames
    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);
    filenames = malloc(num_files * sizeof(char*));
    for (int i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i+1);
        filenames[i] = malloc(MAX_LINE_LENGTH);
        scanf("%s", filenames[i]);
    }

    // Open each file
    files = malloc(num_files * sizeof(File));
    for (int i = 0; i < num_files; i++) {
        files[i].filename = filenames[i];
        files[i].fp = fopen(filenames[i], "r");
        if (files[i].fp == NULL) {
            printf("Error opening file %s\n", filenames[i]);
            exit(1);
        }
    }

    // Synchronize the files
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, files[0].fp)!= NULL) {
        for (int i = 1; i < num_files; i++) {
            if (fgets(buffer, MAX_LINE_LENGTH, files[i].fp) == NULL) {
                printf("Error reading file %s\n", filenames[i]);
                exit(1);
            }
            while (strcmp(buffer, files[0].filename)!= 0) {
                if (fgets(buffer, MAX_LINE_LENGTH, files[i].fp) == NULL) {
                    printf("Error reading file %s\n", filenames[i]);
                    exit(1);
                }
            }
        }
        for (int i = 1; i < num_files; i++) {
            if (fputs(buffer, files[i].fp) == EOF) {
                printf("Error writing to file %s\n", filenames[i]);
                exit(1);
            }
        }
    }

    // Close the files
    for (int i = 0; i < num_files; i++) {
        if (fclose(files[i].fp)!= 0) {
            printf("Error closing file %s\n", filenames[i]);
            exit(1);
        }
        free(files[i].filename);
        free(filenames[i]);
    }
    free(files);
    free(filenames);

    return 0;
}