//FormAI DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1000

// Define Structures
typedef struct backupFile {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_SIZE];
} BackupFile;

typedef struct backupNode {
    BackupFile file;
    struct backupNode* next;
} BackupNode;

typedef struct backupSystem {
    BackupNode* head;
    int numFiles;
} BackupSystem;

// Declare Functions
void addFile(BackupSystem* bs);
void removeFile(BackupSystem* bs);
void displayFiles(BackupSystem* bs);
void saveToFile(BackupSystem* bs);
void loadFromFile(BackupSystem* bs);

// Main Function
int main() {
    BackupSystem bs;
    bs.head = NULL;
    bs.numFiles = 0;

    printf("Welcome to the C File Backup System!\n");
    printf("Enter 'add' to add a file, 'remove' to remove a file,\n'display' to display the list of files, 'save' to save to file,\n'load' to load from file, and 'exit' to leave the program.\n");

    char input[10];
    while(1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if(strcmp(input, "add") == 0) {
            addFile(&bs);
        }
        else if(strcmp(input, "remove") == 0) {
            removeFile(&bs);
        }
        else if(strcmp(input, "display") == 0) {
            displayFiles(&bs);
        }
        else if(strcmp(input, "save") == 0) {
            saveToFile(&bs);
        }
        else if(strcmp(input, "load") == 0) {
            loadFromFile(&bs);
        }
        else if(strcmp(input, "exit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid input, please try again.\n");
        }
    }

    return 0;
}

// Function to add a file to the backup system
void addFile(BackupSystem* bs) {
    BackupNode* newNode = (BackupNode*)malloc(sizeof(BackupNode));
    newNode->next = NULL;

    printf("\nEnter file name (max %d characters): ", MAX_FILENAME_LENGTH);
    scanf("%s", newNode->file.name);

    printf("Enter file content (max %d characters): ", MAX_FILE_SIZE);
    getchar();
    fgets(newNode->file.content, MAX_FILE_SIZE, stdin);

    if(bs->head == NULL) {
        bs->head = newNode;
    }
    else {
        BackupNode* current = bs->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    bs->numFiles++;
    printf("\nFile added successfully!\n");
}

// Function to remove a file from the backup system
void removeFile(BackupSystem* bs) {
    if(bs->head == NULL) {
        printf("\nNo files to remove.\n");
        return;
    }

    printf("\nEnter file name to remove: ");
    char name[MAX_FILENAME_LENGTH];
    scanf("%s", name);

    BackupNode* current = bs->head;
    BackupNode* prev = NULL;
    while(current != NULL) {
        if(strcmp(current->file.name, name) == 0) {
            if(prev == NULL) {
                bs->head = current->next;
            }
            else {
                prev->next = current->next;
            }
            bs->numFiles--;
            free(current);
            printf("\nFile removed successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\nFile not found.\n");
}

// Function to display all files in the backup system
void displayFiles(BackupSystem* bs) {
    if(bs->head == NULL) {
        printf("\nNo files to display.\n");
        return;
    }

    printf("\nList of files:\n");
    BackupNode* current = bs->head;
    while(current != NULL) {
        printf("- %s\n", current->file.name);
        current = current->next;
    }
}

// Function to save the backup system to a file
void saveToFile(BackupSystem* bs) {
    if(bs->head == NULL) {
        printf("\nNo files to save.\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to save to: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "wb");
    if(file == NULL) {
        printf("\nError saving file.\n");
        return;
    }

    fwrite(&bs->numFiles, sizeof(int), 1, file);

    BackupNode* current = bs->head;
    while(current != NULL) {
        fwrite(&current->file, sizeof(BackupFile), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("\nBackup system saved successfully!\n");
}

// Function to load a backup system from a file
void loadFromFile(BackupSystem* bs) {
    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to load from: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("\nError loading file.\n");
        return;
    }

    int numFiles;
    fread(&numFiles, sizeof(int), 1, file);

    bs->head = NULL;
    bs->numFiles = 0;

    for(int i = 0; i < numFiles; i++) {
        BackupNode* newNode = (BackupNode*)malloc(sizeof(BackupNode));
        newNode->next = NULL;
        fread(&newNode->file, sizeof(BackupFile), 1, file);

        if(bs->head == NULL) {
            bs->head = newNode;
        }
        else {
            BackupNode* current = bs->head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        bs->numFiles++;
    }

    fclose(file);
    printf("\nBackup system loaded successfully!\n");
}