//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_FILES 10   // Maximum number of backup files.

typedef struct{
    char* filename;
    time_t timestamp;
} BackupFile;

BackupFile backupFiles[MAX_FILES];
int currentFileIndex = 0;

void backupFile(char* filename){
    if(currentFileIndex == MAX_FILES) {
        printf("Sorry mate, I can't backup this file. I already have %d backups. Delete some old backups first.\n", MAX_FILES);
    }
    else {
        backupFiles[currentFileIndex].filename = filename;
        backupFiles[currentFileIndex].timestamp = time(NULL);
        printf("Creating backup of %s at %s\n", filename, ctime(&backupFiles[currentFileIndex].timestamp));
        currentFileIndex++;
    }
}

void printBackupFiles(){
    printf("Here are the backup files:\n");
    for(int i=0; i<currentFileIndex; i++){
        printf("%s - backed up on %s", backupFiles[i].filename, ctime(&backupFiles[i].timestamp));
    }
}

void deleteBackupFiles(){
    printf("Deleting all backup files...\n");
    for(int i=0; i<currentFileIndex; i++){
        printf("Deleted backup file %s\n", backupFiles[i].filename);
        free(backupFiles[i].filename);
    }
    currentFileIndex = 0;
}

int main(){
    printf("Welcome to the Unique C File Backup System!\n");
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Backup a file\n");
        printf("2. View existing backups\n");
        printf("3. Delete all backups\n");
        printf("4. Exit\n");
        int option;
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the filename to backup: ");
                char* filename = (char*)malloc(256*sizeof(char));
                scanf("%s", filename);
                backupFile(filename);
                break;

            case 2:
                printBackupFiles();
                break;

            case 3:
                deleteBackupFiles();
                break;

            case 4:
                printf("Goodbye! Thanks for using the Unique C File Backup System!\n");
                exit(0);
                break;

            default:
                printf("Invalid Option! Try again.\n");
                break;
        }
    }
    return 0;
}