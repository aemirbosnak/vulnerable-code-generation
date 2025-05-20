//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH_LENGTH 512

int main() {
    char filePath[MAX_FILE_PATH_LENGTH] = "";
    int fileCount = 0;

    printf("Enter the directory path: ");
    scanf("%s", filePath);

    FILE *fp;
    fp = fopen(filePath, "r");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", filePath)!= EOF) {
        char fileName[MAX_FILE_PATH_LENGTH] = "";
        int fileSize = 0;

        fscanf(fp, "%s %d", fileName, &fileSize);

        printf("File Name: %s\n", fileName);
        printf("File Size: %d\n", fileSize);

        char backupPath[MAX_FILE_PATH_LENGTH] = "";
        sprintf(backupPath, "%s.backup", filePath);

        fp = fopen(backupPath, "w");
        if (fp == NULL) {
            printf("Error opening the backup file.\n");
            return 1;
        }

        fwrite(filePath, sizeof(char), strlen(filePath), fp);
        fwrite(fileName, sizeof(char), strlen(fileName), fp);
        fwrite(&fileSize, sizeof(int), 1, fp);
        fclose(fp);

        fileCount++;
    }

    printf("Total files backed up: %d\n", fileCount);

    fclose(fp);
    return 0;
}