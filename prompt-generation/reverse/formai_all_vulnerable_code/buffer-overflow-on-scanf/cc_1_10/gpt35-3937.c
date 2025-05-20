//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_BACKUPS 10
#define MAX_FILENAME_LEN 256

typedef struct Backup {
    time_t backup_time;
    char filename[MAX_FILENAME_LEN];
} Backup;

Backup backups[MAX_BACKUPS];
int current_backup_index = 0;

void create_backup(char* filename) {
    // Ensure that the maximum number of backups is not exceeded
    if (current_backup_index >= MAX_BACKUPS) {
        current_backup_index = 0;
    }
    
    // Create a Backup struct with the current time and filename
    Backup new_backup;
    new_backup.backup_time = time(NULL);
    strcpy(new_backup.filename, filename);
    
    // Add the backup to the array and increment the current backup index
    backups[current_backup_index] = new_backup;
    current_backup_index++;
    
    printf("Backup created for %s at %s\n", filename, ctime(&new_backup.backup_time));
}

void list_backups() {
    printf("Listing backups:\n");
    
    for (int i = 0; i < MAX_BACKUPS; i++) {
        if (backups[i].backup_time != 0) {
            printf("%d. %s backed up at %s", i+1, backups[i].filename, ctime(&backups[i].backup_time));
        }
    }
}

void backup_file(char* filename) {
    printf("Backing up %s...\n", filename);
    
    // Call create_backup to add the backup to the backups array
    create_backup(filename);
    
    printf("Backup complete!\n");
}

void restore_backup(int backup_index) {
    printf("Restoring backup %d...\n", backup_index);
    
    // Get the backup at the specified index and print its details
    Backup backup_to_restore = backups[backup_index-1];
    printf("Restoring %s backed up at %s", backup_to_restore.filename, ctime(&backup_to_restore.backup_time));
    
    // Sleep for a few seconds to simulate the restore process
    printf("Restoring...");
    sleep(3);
    printf("done!\n");
}

int main() {
    char input[10];
    
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);
        
        if (strcmp(input, "backup") == 0) {
            char filename[MAX_FILENAME_LEN];
            printf("Enter filename to backup: ");
            scanf("%s", filename);
            backup_file(filename);
        } else if (strcmp(input, "list") == 0) {
            list_backups();
        } else if (strcmp(input, "restore") == 0) {
            int backup_index;
            printf("Enter backup index to restore: ");
            scanf("%d", &backup_index);
            restore_backup(backup_index);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    return 0;
}