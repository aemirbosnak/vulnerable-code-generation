//FormAI DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH_LENGTH 256
#define MAX_BACKUPS 5

void createBackup(char* filePath, char* backupDir){
    char command[MAX_PATH_LENGTH+50];
    char backupName[MAX_PATH_LENGTH+20];
    time_t currTime;
    struct tm* timeInfo;
    struct stat fileInfo;
    int i;

    // Get file info
    if(stat(filePath, &fileInfo) == -1){
        fprintf(stderr, "Error: Failed to get file info\n");
        exit(EXIT_FAILURE);
    }

    // Get current time
    currTime = time(NULL);
    timeInfo = localtime(&currTime);

    // Create backup directory path
    sprintf(backupDir, "./backups/%04d-%02d-%02d", timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday);

    // Create backup directory if it doesn't exist
    if(stat(backupDir, &fileInfo) == -1){
        if(mkdir(backupDir, 0777) == -1){
            fprintf(stderr, "Error: Failed to create backup directory\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create backup name
    sprintf(backupName, "%s/%04d-%02d-%02d-%02d-%02d-%02d%s",
        backupDir,
        timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday,
        timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec,
        strrchr(filePath, '.') // File extension
    );

    // Create backup command
    sprintf(command, "cp %s %s", filePath, backupName);

    // Execute backup command
    if(system(command) == -1){
        fprintf(stderr, "Error: Failed to execute backup command\n");
        exit(EXIT_FAILURE);
    }

    // Remove oldest backup if exceeding maximum number of backups
    for(i = 1; i <= MAX_BACKUPS; i++){
        sprintf(command, "./backups/%s-%02d.tar.gz", backupName, i);
        if(access(command, F_OK) == -1)
            break;
    }
    if(i > MAX_BACKUPS){
        sprintf(command, "rm %s", command);
        if(system(command) == -1){
            fprintf(stderr, "Error: Failed to remove oldest backup\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char** argv){
    char filePath[MAX_PATH_LENGTH];
    char backupDir[MAX_PATH_LENGTH];
    int interval;

    // Get file path and backup interval from command line arguments
    if(argc != 3){
        fprintf(stderr, "Usage: %s <file_path> <backup_interval>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(filePath, argv[1]);
    interval = atoi(argv[2]);

    while(1){
        createBackup(filePath, backupDir);
        sleep(interval);
    }

    return 0;
}