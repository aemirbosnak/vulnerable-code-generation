//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct File {
    char name[MAX_FILE_SIZE];
    int size;
    struct File* next;
} File;

void BackupSystem() {
    File* head = NULL;
    char filename[MAX_FILE_SIZE];
    int filesize;

    printf("Welcome to the C File Backup System!\n");
    printf("Please enter the name of the file you want to backup: ");
    scanf("%s", filename);

    printf("Please enter the size of the file in KB: ");
    scanf("%d", &filesize);

    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, filename);
    newFile->size = filesize;
    newFile->next = NULL;

    if (head == NULL) {
        head = newFile;
    } else {
        head->next = newFile;
    }

    printf("File backup successful!\n");
    printf("List of backed up files:");

    File* currentFile = head;
    while (currentFile) {
        printf("\n- %s (%d KB)", currentFile->name, currentFile->size);
        currentFile = currentFile->next;
    }
}

int main() {
    BackupSystem();

    return 0;
}