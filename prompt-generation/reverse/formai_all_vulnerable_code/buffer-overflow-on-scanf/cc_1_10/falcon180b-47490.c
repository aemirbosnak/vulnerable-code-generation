//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char fileContent[MAX_FILE_CONTENT_LENGTH];
} File;

int main() {
    File backupFile;
    strcpy(backupFile.fileName, "backup.txt");
    strcpy(backupFile.fileContent, "This is a sample backup file.");

    printf("\n\n");
    printf("*** C File Backup System ***\n\n");
    printf("1. Backup file\n");
    printf("2. Restore file\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter the name of the file to backup: ");
            scanf("%s", backupFile.fileName);

            printf("\nEnter the content of the file: ");
            scanf("%s", backupFile.fileContent);

            printf("\nBackup Successful!\n");

            break;

        case 2:
            printf("\nEnter the name of the file to restore: ");
            scanf("%s", backupFile.fileName);

            printf("\nContent of the file:\n%s\n", backupFile.fileContent);

            break;

        case 3:
            printf("\nExiting...\n");

            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}