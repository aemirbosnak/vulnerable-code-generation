//FormAI DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_NUM_FILES 1000
#define MAX_NUM_BACKUPS 10

//Structure to represent a backup
typedef struct backup {
    char fileName[MAX_FILE_NAME_LENGTH];
    char backupNames[MAX_NUM_BACKUPS][MAX_FILE_NAME_LENGTH];
    int numBackups;
} Backup;

//Initialize a backup with the given file name
Backup* initBackup(char* fileName) {
    Backup* newBackup = malloc(sizeof(Backup));
    strcpy(newBackup->fileName, fileName);
    newBackup->numBackups = 0;
    return newBackup;
}

//Add a backup to an existing backup
void addBackup(Backup* backup, char* backupName) {
    if(backup->numBackups == MAX_NUM_BACKUPS) {
        printf("Maximum number of backups reached for file %s.\n", backup->fileName);
        return;
    }
    strcpy(backup->backupNames[backup->numBackups++], backupName);
    printf("Backup created for file %s with name %s.\n", backup->fileName, backupName);
}

//Print all backups for a given file
void printBackupsForFile(Backup* backup) {
    printf("Backups for file %s:\n", backup->fileName);
    for(int i=0; i<backup->numBackups; i++) {
        printf("- %s\n", backup->backupNames[i]);
    }
}

//Print all backups for all files
void printAllBackups(Backup** backups, int numFiles) {
    printf("All backups:\n");
    for(int i=0; i<numFiles; i++) {
        printBackupsForFile(backups[i]);
    }
}

//Main function for the backup system
int main() {
    Backup* backups[MAX_NUM_FILES];
    int numBackups = 0;

    while(1) {
        printf("Enter command ('add', 'list', or 'quit'): ");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            char fileName[MAX_FILE_NAME_LENGTH];
            scanf("%s", fileName);

            Backup* backup = NULL;
            for(int i=0; i<numBackups; i++) {
                if(strcmp(backups[i]->fileName, fileName) == 0) {
                    backup = backups[i];
                    break;
                }
            }

            if(backup == NULL) {
                backup = initBackup(fileName);
                backups[numBackups++] = backup;
            }

            char backupName[MAX_FILE_NAME_LENGTH];
            time_t currentTime = time(NULL);
            strftime(backupName, MAX_FILE_NAME_LENGTH, "%Y-%m-%d-%H-%M-%S", localtime(&currentTime));
            addBackup(backup, backupName);
        }

        else if(strcmp(command, "list") == 0) {
            printAllBackups(backups, numBackups);
        }

        else if(strcmp(command, "quit") == 0) {
            printf("Exiting backup system.\n");
            break;
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}