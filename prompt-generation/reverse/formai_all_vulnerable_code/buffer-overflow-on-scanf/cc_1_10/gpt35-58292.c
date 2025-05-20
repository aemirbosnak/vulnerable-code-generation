//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_NAME_LENGTH 512
#define MAX_BACKUPS 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char backup_name[MAX_BACKUP_NAME_LENGTH];
    time_t timestamp;
} Backup;

Backup backups[MAX_BACKUPS];
int num_backups = 0;

int create_backup(char* filename) {
    if (num_backups >= MAX_BACKUPS) {
        printf("Cannot create backup, maximum number of backups reached.\n");
        return 0;
    }

    char* ext = strrchr(filename, '.');
    if (ext == NULL) {
        printf("Cannot create backup, filename has no extension.\n");
        return 0;
    }

    char timestamp_str[20];
    time_t rawtime;
    time(&rawtime);
    strftime(timestamp_str, 20, "%Y%m%d_%H%M%S", localtime(&rawtime));

    sprintf(backups[num_backups].backup_name, "%.*s_%s%s", (int)(ext - filename), filename, timestamp_str, ext);
    strcpy(backups[num_backups].filename, filename);
    backups[num_backups].timestamp = rawtime;

    num_backups++;

    printf("Created backup %s.\n", backups[num_backups-1].backup_name);

    return 1;
}

void list_backups() {
    if (num_backups == 0) {
        printf("No backups created yet.\n");
        return;
    }

    printf("Backup Name\t\tFilename\t\tTimestamp\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < num_backups; i++) {
        printf("%s\t\t%s\t\t%s", backups[i].backup_name, backups[i].filename, ctime(&backups[i].timestamp));
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char command[10];

    while(1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "backup") == 0) {
            scanf("%s", filename);
            create_backup(filename);
        } else if (strcmp(command, "list") == 0) {
            list_backups();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}