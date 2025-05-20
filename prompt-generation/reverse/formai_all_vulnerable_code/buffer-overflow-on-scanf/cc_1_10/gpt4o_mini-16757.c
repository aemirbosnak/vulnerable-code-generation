//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 255

void get_current_time(char *buffer, size_t length) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, length, "%Y%m%d%H%M%S", tm_info);
}

void create_backup(const char *filename) {
    char backup_filename[FILENAME_LENGTH];
    char timestamp[20];
    get_current_time(timestamp, sizeof(timestamp));

    snprintf(backup_filename, sizeof(backup_filename), "%s_backup_%s", filename, timestamp);
    
    FILE *source_file = fopen(filename, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return;
    }

    FILE *backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        perror("Error creating backup file");
        fclose(source_file);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    printf("Backup created: %s\n", backup_filename);

    fclose(source_file);
    fclose(backup_file);
}

void list_backups(const char *filename) {
    printf("Backup files for: %s\n", filename);
    
    char command[256];
    snprintf(command, sizeof(command), "ls %s_backup_* 2>/dev/null", filename);
    system(command);
}

void delete_old_backups(const char *filename, int max_backups) {
    char command[256];
    snprintf(command, sizeof(command), "ls -t %s_backup_* 2>/dev/null | tail -n +%d | xargs rm -f", filename, max_backups + 1);
    system(command);
}

int main() {
    char filename[FILENAME_LENGTH];
    int max_backups;

    printf("Enter the file to back up: ");
    scanf("%s", filename);
    
    struct stat buffer;
    if (stat(filename, &buffer) != 0) {
        perror("File does not exist");
        return EXIT_FAILURE;
    }

    printf("Enter the maximum number of backups to keep: ");
    scanf("%d", &max_backups);
    
    while (1) {
        printf("\nOptions:\n");
        printf("1. Create Backup\n");
        printf("2. List Backups\n");
        printf("3. Delete Old Backups\n");
        printf("4. Exit\n");
        
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_backup(filename);
                break;
            case 2:
                list_backups(filename);
                break;
            case 3:
                delete_old_backups(filename, max_backups);
                break;
            case 4:
                printf("Exiting the backup system.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return EXIT_SUCCESS;
}