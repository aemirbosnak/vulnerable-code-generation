//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_FILE_SIZE 1024*1024*10 // 10MB

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    size_t fileSize;
    char fileContent[MAX_FILE_SIZE];
} FileBackup;

int main() {
    FileBackup backup;
    int choice;
    char fileName[MAX_FILE_NAME_LENGTH];
    FILE *file;

    do {
        printf("Choose an option:\n");
        printf("1. Backup file\n");
        printf("2. Restore file\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", backup.fileName);
                file = fopen(backup.fileName, "rb");

                if (file == NULL) {
                    printf("File not found\n");
                } else {
                    fseek(file, 0, SEEK_END);
                    backup.fileSize = ftell(file);
                    rewind(file);
                    fread(backup.fileContent, backup.fileSize, 1, file);
                    fclose(file);

                    printf("File backed up successfully\n");
                }
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", fileName);

                if (strcmp(fileName, backup.fileName) == 0) {
                    printf("Restoring file...\n");
                    file = fopen(fileName, "wb");

                    if (file == NULL) {
                        printf("File could not be created\n");
                    } else {
                        fwrite(backup.fileContent, backup.fileSize, 1, file);
                        fclose(file);

                        printf("File restored successfully\n");
                    }
                } else {
                    printf("File not found\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}