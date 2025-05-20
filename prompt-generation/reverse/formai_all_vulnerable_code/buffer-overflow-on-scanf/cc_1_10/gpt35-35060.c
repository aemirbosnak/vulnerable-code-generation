//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUPS 10

typedef struct backup {
    char filename[MAX_FILENAME_LENGTH];
    time_t timestamp;
} backup;

void make_backup(char* filename, backup* backups, int* num_backups) {
    if (*num_backups >= MAX_BACKUPS) {
        printf("Sorry, you have reached the maximum number of backups!\n");
        return;
    }
    backup new_backup;
    strcpy(new_backup.filename, filename);
    new_backup.timestamp = time(NULL);
    backups[*num_backups] = new_backup;
    *num_backups += 1;
    printf("Backup created successfully!\n");
}

void list_backups(backup* backups, int num_backups) {
    if (num_backups == 0) {
        printf("You have no backups!\n");
        return;
    }
    printf("Backups:\n");
    for (int i = 0; i < num_backups; i++) {
        printf("%s - %s\n", backups[i].filename, ctime(&backups[i].timestamp));
    }
}

void delete_backup(char* filename, backup* backups, int* num_backups) {
    int delete_index = -1;
    for (int i = 0; i < *num_backups; i++) {
        if (strcmp(backups[i].filename, filename) == 0) {
            delete_index = i;
        }
    }
    if (delete_index == -1) {
        printf("Could not find a backup with that filename!\n");
        return;
    }
    for (int i = delete_index; i < (*num_backups)-1; i++) {
        backups[i] = backups[i+1];
    }
    *num_backups -= 1;
    printf("Backup deleted successfully!\n");
}

int main() {
    int num_backups = 0;
    backup backups[MAX_BACKUPS];
    char filename[MAX_FILENAME_LENGTH];
    while (1) {
        printf("Enter a command (backup, list, delete, quit):\n");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "backup") == 0) {
            printf("Enter filename to backup:\n");
            scanf("%s", filename);
            make_backup(filename, backups, &num_backups);
        } else if (strcmp(command, "list") == 0) {
            list_backups(backups, num_backups);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter filename to delete backup of:\n");
            scanf("%s", filename);
            delete_backup(filename, backups, &num_backups);
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}