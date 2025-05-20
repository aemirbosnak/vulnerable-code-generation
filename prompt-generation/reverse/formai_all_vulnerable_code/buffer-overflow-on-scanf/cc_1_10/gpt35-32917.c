//FormAI DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 100000

typedef struct backup_file_t {
    char name[MAX_FILENAME_LENGTH];
    char* content;
    int size;
    struct backup_file_t* next;
} BackupFile;

BackupFile* head = NULL;

void backupFile(char* filename) {
    FILE* file = fopen(filename, "rb");
    if(!file) {
        printf("%s: File not found.\n", filename);
        return;
    }
    BackupFile* backup = (BackupFile*) malloc(sizeof(BackupFile));
    strncpy(backup->name, filename, MAX_FILENAME_LENGTH);
    backup->size = 0;
    backup->next = NULL;
    backup->content = (char*) malloc(MAX_FILE_SIZE);
    while(!feof(file)) {
        backup->content[backup->size++] = fgetc(file);
    }
    fclose(file);
    if(head == NULL) {
        head = backup;
    } else {
        BackupFile* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = backup;
    }
}

void restoreFile(char* filename) {
    BackupFile* backup = head;
    while(backup != NULL) {
        if(strcmp(backup->name, filename) == 0) {
            FILE* file = fopen(filename, "wb");
            if(!file) {
                printf("%s: Unable to restore file.\n", filename);
                return;
            }
            fwrite(backup->content, sizeof(char), backup->size, file);
            fclose(file);
            return;
        }
        backup = backup->next;
    }
    printf("%s: File not found.\n", filename);
}

void listFiles() {
    BackupFile* backup = head;
    printf("Backup files:\n");
    while(backup != NULL) {
        printf("- %s (%d bytes)\n", backup->name, backup->size);
        backup = backup->next;
    }
}

int main() {
    char command[10], filename[MAX_FILENAME_LENGTH];
    while(1) {
        printf("Enter a command (backup/restore/list/exit):\n");
        scanf("%s", command);
        if(strcmp(command, "backup") == 0) {
            printf("Enter a filename to backup:\n");
            scanf("%s", filename);
            backupFile(filename);
        } else if(strcmp(command, "restore") == 0) {
            printf("Enter a filename to restore:\n");
            scanf("%s", filename);
            restoreFile(filename);
        } else if(strcmp(command, "list") == 0) {
            listFiles();
        } else if(strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}