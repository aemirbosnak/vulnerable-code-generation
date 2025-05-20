//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File {
    char name[50];
    char content[500];
};

int main() {
    struct File files[5];
    int numFiles = 0;
    int numReads = 0;
    int numWrites = 0;

    // Read files from a text file
    FILE *fp = fopen("files.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(fp, "%s %s", files[numFiles].name, files[numFiles].content) == 2) {
        numFiles++;
    }
    fclose(fp);

    // Print out the file system
    printf("Files in file system:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s - %s\n", files[i].name, files[i].content);
    }

    // Read files from the file system
    fp = fopen("files.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(fp, "%s %s", files[numReads].name, files[numReads].content) == 2) {
        numReads++;
    }
    fclose(fp);

    // Print out the read files
    printf("\nFiles read from file system:\n");
    for (int i = 0; i < numReads; i++) {
        printf("%s - %s\n", files[i].name, files[i].content);
    }

    // Write files to a new file
    fp = fopen("new_files.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < numFiles; i++) {
        fprintf(fp, "%s %s\n", files[i].name, files[i].content);
    }
    fclose(fp);

    // Print out the new files
    fp = fopen("new_files.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(fp, "%s %s", files[numWrites].name, files[numWrites].content) == 2) {
        numWrites++;
    }
    fclose(fp);

    // Print out the write files
    printf("\nFiles written to new file system:\n");
    for (int i = 0; i < numWrites; i++) {
        printf("%s - %s\n", files[i].name, files[i].content);
    }

    return 0;
}