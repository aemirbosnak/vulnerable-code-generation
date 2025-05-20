//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH 1024
#define MAX_NAME 50

void createBackup(char *sourceFile, char *backupName) {
    FILE *source, *backup;
    char destination[MAX_PATH];

    strcpy(destination, "Backups/");
    strcat(destination, backupName);
    strcat(destination, ".bkp");

    source = fopen(sourceFile, "rb");
    if (source == NULL) {
        printf("Error: Unable to open the source file.\n");
        return;
    }

    backup = fopen(destination, "wb");
    if (backup == NULL) {
        printf("Error: Unable to create the backup file.\n");
        fclose(source);
        return;
    }

    fseek(source, 0, SEEK_END);
    long fileSize = ftell(source);
    fseek(source, 0, SEEK_SET);

    char buffer[1024];
    while (fread(buffer, 1, 1024, source) > 0) {
        fwrite(buffer, 1, 1024, backup);
    }

    fclose(source);
    fclose(backup);

    printf("Backup created successfully.\n");
}

int main() {
    char fileName[MAX_PATH];
    char backupName[MAX_NAME];

    printf("Enter the name of the file to be backed up: ");
    scanf("%s", fileName);

    printf("Enter the name for the backup file: ");
    scanf("%s", backupName);

    for (int i = 0; i < strlen(backupName); i++) {
        if (isalpha(backupName[i])) {
            backupName[i] = toupper(backupName[i]);
        }
    }

    createBackup(fileName, backupName);

    return 0;
}