//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_DIR_LEN 256

typedef struct {
    char name[MAX_DIR_LEN];
    time_t timestamp;
} FileInfo;

void backupFile(char* src, char* dest) {
    FILE* in = fopen(src, "rb");
    FILE* out = fopen(dest, "wb");

    if (in == NULL || out == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        fwrite(buffer, 1, bytesRead, out);
    }

    fclose(in);
    fclose(out);
}

int main() {
    char backupDir[MAX_DIR_LEN];
    char* files[MAX_FILES];
    int numFiles = 0;

    // Get backup directory from user
    printf("Enter backup directory: ");
    scanf("%s", backupDir);

    // Get list of files to backup
    while (numFiles < MAX_FILES && scanf("%s", files[numFiles])!= EOF) {
        numFiles++;
    }

    // Create backup directory if it doesn't exist
    char* mode = "0777";
    mkdir(backupDir, atoi(mode));

    // Backup each file
    for (int i = 0; i < numFiles; i++) {
        char dest[MAX_DIR_LEN];
        sprintf(dest, "%s/%s", backupDir, files[i]);

        backupFile(files[i], dest);

        FileInfo fileInfo;
        strcpy(fileInfo.name, files[i]);
        fileInfo.timestamp = time(NULL);

        FILE* infoFile = fopen(".fileinfo", "ab");
        if (infoFile == NULL) {
            printf("Error opening fileinfo file\n");
            exit(1);
        }

        fwrite(&fileInfo, sizeof(fileInfo), 1, infoFile);
        fclose(infoFile);
    }

    printf("Backup complete\n");

    return 0;
}