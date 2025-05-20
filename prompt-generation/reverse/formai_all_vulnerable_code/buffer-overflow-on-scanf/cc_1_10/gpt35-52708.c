//FormAI DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_BACKUP_COUNT 5

// Backup struct to store backup related information
struct Backup {
    char filename[MAX_FILENAME_LEN];
    char backup_filenames[MAX_BACKUP_COUNT][MAX_FILENAME_LEN];
    int count;
};

// Function to create backup of the file
void create_backup(struct Backup *backup) {
    // Check if maximum number of backups allowed has been reached
    if (backup->count >= MAX_BACKUP_COUNT) {
        // Delete oldest backup
        remove(backup->backup_filenames[0]);
        // Shift all other backups
        for (int i = 1; i < MAX_BACKUP_COUNT; i++) {
            strcpy(backup->backup_filenames[i-1], backup->backup_filenames[i]);
        }
        // Decrement backup count
        backup->count--;
    }
    // Create new backup
    char backup_filename[MAX_FILENAME_LEN];
    sprintf(backup_filename, "%s.bak%d", backup->filename, backup->count+1);
    FILE *src = fopen(backup->filename, "rb");
    FILE *dst = fopen(backup_filename, "wb");
    int c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dst);
    }
    fclose(src);
    fclose(dst);
    // Add backup filename to backup_filenames array
    strcpy(backup->backup_filenames[backup->count], backup_filename);
    // Increment backup count
    backup->count++;
}

int main() {
    // Initialize backup struct
    struct Backup backup;
    printf("Enter filename to backup: ");
    scanf("%s", backup.filename);
    // Initialize backup count to 0
    backup.count = 0;
    // Create initial backup
    create_backup(&backup);
    char option;
    do {
        printf("Do you want to create another backup? (y/n): ");
        scanf(" %c", &option);
        if (option == 'y') {
            create_backup(&backup);
        }
    } while (option == 'y');
    printf("Backup count: %d\n", backup.count);
    printf("Backup filenames:\n");
    for (int i = 0; i < backup.count; i++) {
        printf("%s\n", backup.backup_filenames[i]);
    }
    return 0;
}