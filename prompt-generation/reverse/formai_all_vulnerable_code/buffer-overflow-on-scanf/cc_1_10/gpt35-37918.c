//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_LEN 128
#define MAX_COMMAND_LEN 16
#define MAX_BACKUPS 5

typedef struct {
    time_t timestamp;
    char filename[MAX_FILE_LEN];
} Backup;

void display_menu() {
    printf("\n");
    printf("1. Create backup\n");
    printf("2. List backups\n");
    printf("3. Restore backup\n");
    printf("4. Exit\n");
    printf("\nEnter choice: ");
}

void create_backup(Backup backups[], int *num_backups) {
    char filename[MAX_FILE_LEN];
    time_t current_time;

    printf("\nEnter filename to backup: ");
    scanf("%s", filename);

    // Open the original file
    FILE* original_file = fopen(filename, "r");
    if (!original_file) {
        printf("\nError: Could not open file %s", filename);
        return;
    }

    // Create a backup filename
    char backup_filename[MAX_FILE_LEN + 20];
    sprintf(backup_filename, "%s_%ld.backup", filename, time(NULL));

    // Open the backup file
    FILE* backup_file = fopen(backup_filename, "w");
    if (!backup_file) {
        printf("\nError: Could not create backup file %s", backup_filename);
        fclose(original_file);
        return;
    }

    // Copy the contents of the original file to backup file
    int ch;
    while ((ch = fgetc(original_file)) != EOF) {
        fputc(ch, backup_file);
    }
    fclose(original_file);
    fclose(backup_file);

    // Save the backup to the list of backups
    current_time = time(NULL);
    Backup new_backup = {current_time, backup_filename};
    backups[*num_backups] = new_backup;
    *num_backups = (*num_backups + 1) % MAX_BACKUPS;

    printf("\nBackup created successfully: %s", backup_filename);
}

void list_backups(Backup backups[], int num_backups) {
    printf("\n");
    printf("Timestamp\t\tFilename\n");
    for (int i = 0; i < num_backups; i++) {
        char timestamp_str[128];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&backups[i].timestamp));
        printf("%s\t%s\n", timestamp_str, backups[i].filename);
    }
}

void restore_backup(Backup backups[], int num_backups) {
    int backup_idx;
    printf("\nEnter backup index to restore: ");
    scanf("%d", &backup_idx);

    if (backup_idx < 1 || backup_idx > num_backups) {
        printf("\nError: Invalid backup index");
        return;
    }

    char confirm_command[MAX_COMMAND_LEN];
    printf("\nDo you want to restore the backup '%s'? (y/n): ", backups[backup_idx - 1].filename);
    scanf("%s", confirm_command);

    if (strcmp(confirm_command,"y") != 0) {
        printf("\nBackup restore cancelled");
        return;
    }

    // Remove the original file
    if (remove(backups[backup_idx - 1].filename) != 0) {
        printf("\nError: Could not remove original file %s", backups[backup_idx - 1].filename);
        return;
    }

    // Restore the backup file
    FILE* backup_file = fopen(backups[backup_idx - 1].filename, "r");
    if (!backup_file) {
        printf("\nError: Could not open backup file %s", backups[backup_idx - 1].filename);
        return;
    }

    FILE* original_file = fopen(strtok(backups[backup_idx - 1].filename, "_"), "w");
    if (!original_file) {
        printf("\nError: Could not create original file %s", strtok(backups[backup_idx - 1].filename, "_"));
        fclose(backup_file);
        return;
    }

    int ch;
    while ((ch = fgetc(backup_file)) != EOF) {
        fputc(ch, original_file);
    }
    fclose(backup_file);
    fclose(original_file);

    printf("\nBackup '%s' restored successfully", backups[backup_idx - 1].filename);
}

int main() {
    Backup backups[MAX_BACKUPS];
    int num_backups = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_backup(backups, &num_backups);
                break;
            case 2:
                list_backups(backups, num_backups);
                break;
            case 3:
                restore_backup(backups, num_backups);
                break;
            case 4:
                printf("\nExiting backup system");
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}