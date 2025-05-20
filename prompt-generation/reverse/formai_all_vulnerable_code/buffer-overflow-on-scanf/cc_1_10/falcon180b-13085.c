//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
} backup_file_t;

void backup_file(char* file_name) {
    backup_file_t* backup = (backup_file_t*)malloc(sizeof(backup_file_t));
    strcpy(backup->file_name, file_name);
    time(&backup->backup_time);
    printf("Backed up file: %s\n", backup->file_name);
}

void restore_file(char* backup_file_name) {
    backup_file_t* backup = (backup_file_t*)malloc(sizeof(backup_file_t));
    strcpy(backup->file_name, backup_file_name);
    time_t current_time = time(NULL);
    if (difftime(current_time, backup->backup_time) > 86400) {
        printf("Sorry, backup is too old.\n");
    } else {
        printf("Restored file: %s\n", backup->file_name);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (backup/restore/exit): ");
        scanf("%s", input);
        if (strcmp(input, "backup") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name to backup: ");
            scanf("%s", file_name);
            backup_file(file_name);
        } else if (strcmp(input, "restore") == 0) {
            char backup_file_name[MAX_FILE_NAME_LENGTH];
            printf("Enter backup file name to restore: ");
            scanf("%s", backup_file_name);
            restore_file(backup_file_name);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}