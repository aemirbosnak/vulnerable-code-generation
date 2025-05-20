//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_SIZE 10000

int main() {
    char filename[MAX_FILENAME_LEN];
    char backupFilename[MAX_FILENAME_LEN + 15];
    char fileContent[MAX_FILE_SIZE];
    char timestamp[30];

    FILE *file;
    FILE *backupFile;

    // get filename from user
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);

    // open file for reading
    file = fopen(filename, "r");

    // check if file exists
    if (!file) {
        printf("\nFile does not exist.\n");
        return 0;
    }

    // read file contents
    fread(fileContent, sizeof(char), MAX_FILE_SIZE, file);

    // close original file
    fclose(file);

    // generate backup filename based on timestamp
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, 30, "%Y-%m-%d_%H-%M-%S", timeinfo);
    sprintf(backupFilename, "backup_%s_%s", timestamp, filename);

    // open backup file for writing
    backupFile = fopen(backupFilename, "w");

    // check if backup file was created successfully
    if (!backupFile) {
        printf("\nError creating backup file.\n");
        return 0;
    }

    // write file contents to backup file
    fwrite(fileContent, sizeof(char), MAX_FILE_SIZE, backupFile);

    // close backup file
    fclose(backupFile);

    printf("\nBackup created successfully: %s\n", backupFilename);

    return 0;
}