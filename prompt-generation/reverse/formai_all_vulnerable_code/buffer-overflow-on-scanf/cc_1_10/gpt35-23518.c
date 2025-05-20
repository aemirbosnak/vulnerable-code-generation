//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct backup {
    char* fileName;
    char* fileContent;
    char* creationTime;
    struct backup* next;
} Backup;

Backup* head = NULL;

void backupFile(char* fileName, char* fileContent) {
    Backup* backup = (Backup*)malloc(sizeof(Backup));
    backup->fileName = (char*)malloc(strlen(fileName) + 1);
    backup->fileContent = (char*)malloc(strlen(fileContent) + 1);
    backup->creationTime = (char*)malloc(20);

    strcpy(backup->fileName, fileName);
    strcpy(backup->fileContent, fileContent);

    time_t currentTime = time(NULL);
    strftime(backup->creationTime, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    backup->next = head;
    head = backup;
}

void printBackup(Backup* backup) {
    printf("Backup for \"%s\" created on %s:\n", backup->fileName, backup->creationTime);
    printf("%s\n", backup->fileContent);
}

void printAllBackups() {
    if (head == NULL) {
        printf("No backups available.\n");
        return;
    }

    Backup* current = head;
    int i = 1;

    while (current != NULL) {
        printf("%d. ", i);
        printBackup(current);
        current = current->next;
        i++;
    }
}

int main() {
    char fileName[50];
    char fileContent[100];

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter file content: ");
    scanf("%s", fileContent);

    backupFile(fileName, fileContent);

    printf("Backup created successfully!\n");

    printf("Do you want to view all backups? (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y') {
        printf("--- All Backups ---\n");
        printAllBackups();
    }

    return 0;
}