//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 255
#define MAX_BACKUP_NUMBER 10

void createBackup(char* fileName);
void rollback(char* fileName, int version);

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Please provide a file name to backup!\n");
        return -1;
    }

    // Create a backup folder if necessary
    system("mkdir -p backup");

    // Create a backup for the given file
    createBackup(argv[1]);

    // Demonstrate rollback feature
    char fileName[MAX_FILENAME_LEN];
    printf("Enter the file name you want to rollback: ");
    scanf("%s", fileName);
    rollback(fileName, 2);

    return 0;
}

void createBackup(char* fileName) {
    // Generate backup file name
    char backupName[MAX_FILENAME_LEN];
    time_t now = time(NULL);
    strftime(backupName, MAX_FILENAME_LEN, "backup/%Y-%m-%d_%H-%M-%S_", localtime(&now));
    strcat(backupName, fileName);

    // Check if maximum number of backups is reached
    char command[256];
    sprintf(command, "ls backup | grep %s | wc -l", fileName);
    FILE* p = popen(command, "r");
    int backupCount;
    fscanf(p, "%d", &backupCount);
    if(backupCount == MAX_BACKUP_NUMBER) {
        printf("Maximum number of backups reached, older backups will be removed!\n");

        // Remove the oldest backup
        sprintf(command, "ls -tr backup/%s* | head -n 1 | xargs rm", fileName);
        system(command);
    }

    // Copy the file to backup folder
    sprintf(command, "cp %s %s", fileName, backupName);
    system(command);

    printf("Backup created: %s\n", backupName);
}

void rollback(char* fileName, int version) {
    // Find the backup file to be used
    char command[256];
    sprintf(command, "ls backup/%s* | sort -r | head -n %d | tail -n 1", fileName, version);
    FILE* p = popen(command, "r");
    char backupName[MAX_FILENAME_LEN];
    fgets(backupName, MAX_FILENAME_LEN, p);
    backupName[strlen(backupName)-1] = '\0'; // Remove the trailing newline character

    // Restore the file from backup
    sprintf(command, "cp %s %s", backupName, fileName);
    system(command);

    printf("Rollback completed: %s\n", fileName);
}