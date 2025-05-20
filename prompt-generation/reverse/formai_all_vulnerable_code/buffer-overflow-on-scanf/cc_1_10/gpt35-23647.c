//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 100
#define MAX_BACKUP_COUNT 100

/**
 * A struct to store the backup file information
 */
typedef struct {
    char name[MAX_FILENAME_LEN];
    time_t backup_time;
} BackupFile;

/**
 * A function to print the list of backup files
 * @param backups Pointer to the array of backup files
 * @param count Number of backup files in the array
 */
void print_backups(BackupFile *backups, int count) {
    printf("List of Backup Files:\n");
    printf("======================\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s", i+1, backups[i].name, ctime(&backups[i].backup_time));
    }
    printf("\n");
}

/**
 * A function to create a backup file
 * @param filename Name of the file to backup
 * @param backups Pointer to the array of backup files
 * @param count Pointer to the number of backup files in the array
 */
void create_backup(char *filename, BackupFile *backups, int *count) {
    // Create the backup filename based on current time
    time_t now = time(NULL);
    char backup_filename[MAX_FILENAME_LEN];
    strftime(backup_filename, MAX_FILENAME_LEN, "%Y%m%d%H%M%S", localtime(&now));
    strcat(backup_filename, "_");
    strcat(backup_filename, filename);

    // Copy the file to the backup filename
    FILE *src_file = fopen(filename, "rb");
    FILE *dest_file = fopen(backup_filename, "wb");
    if (src_file && dest_file) {
        char buffer[1024];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file))) {
            fwrite(buffer, 1, bytes_read, dest_file);
        }
        fclose(src_file);
        fclose(dest_file);

        // Add the backup file information to the list of backup files
        BackupFile backup = {
            .backup_time = now
        };
        strncpy(backup.name, backup_filename, MAX_FILENAME_LEN);
        backups[*count] = backup;
        (*count)++;
    }
}

int main() {
    // Initialize the array of backup files
    BackupFile backups[MAX_BACKUP_COUNT];
    int backup_count = 0;

    // Loop until the user chooses to exit
    int choice;
    char filename[MAX_FILENAME_LEN];
    do {
        printf("C File Backup System\n");
        printf("====================\n");
        printf("1. Create backup\n");
        printf("2. List backups\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter filename to backup: ");
            scanf("%s", filename);
            create_backup(filename, backups, &backup_count);
            printf("Backup created successfully\n\n");
            break;
        case 2:
            print_backups(backups, backup_count);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
            break;
        }
    } while (choice != 3);

    return 0;
}