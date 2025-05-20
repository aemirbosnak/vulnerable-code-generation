//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 50

typedef struct {
    char filename[MAX_LEN];
    char content[MAX_LEN];
    time_t timestamp;
} File;

void backup(File* files, int numFiles);
void printFiles(File* files, int numFiles);

int main() {
    // get number of files to backup from user
    int numFiles;
    printf("Enter number of files to backup: ");
    scanf("%d", &numFiles);

    // create array of files
    File* files = (File*) malloc(sizeof(File) * numFiles);

    // get file names and content from user
    for (int i = 0; i < numFiles; i++) {
        printf("\nEnter file %d name: ", i+1);
        scanf("%s", files[i].filename);
        printf("Enter file %d content: ", i+1);
        scanf("%s", files[i].content);
        files[i].timestamp = time(NULL);
    }

    // backup the files
    backup(files, numFiles);

    // print the files
    printFiles(files, numFiles);

    // free the memory allocated for the files
    free(files);

    return 0;
}

void backup(File* files, int numFiles) {
    // create backup file
    FILE* backupFile = fopen("backup.txt", "w");

    // write each file's name, content, and timestamp to backup file
    for (int i = 0; i < numFiles; i++) {
        fprintf(backupFile, "File name: %s\n", files[i].filename);
        fprintf(backupFile, "File content: %s\n", files[i].content);
        fprintf(backupFile, "Timestamp: %ld\n", files[i].timestamp);
    }

    // close backup file
    fclose(backupFile);
}

void printFiles(File* files, int numFiles) {
    // iterate through files and print name, content, and timestamp
    for (int i = 0; i < numFiles; i++) {
        printf("\nFile name: %s\n", files[i].filename);
        printf("File content: %s\n", files[i].content);
        printf("Timestamp: %ld\n", files[i].timestamp);
    }
}