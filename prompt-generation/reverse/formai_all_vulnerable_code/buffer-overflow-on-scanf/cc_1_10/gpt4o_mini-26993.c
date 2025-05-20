//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILENAME 256
#define MAX_BACKUPS 10

void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", t);
}

void backup_file(const char *filename) {
    char backup_filename[MAX_FILENAME];
    char timestamp[20];
    
    get_current_time(timestamp, sizeof(timestamp));
    snprintf(backup_filename, sizeof(backup_filename), "%s_backup_%s", filename, timestamp);
    
    FILE *original_file = fopen(filename, "rb");
    if (!original_file) {
        perror("Error opening original file");
        return;
    }
    
    FILE *backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        perror("Error creating backup file");
        fclose(original_file);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }
    
    fclose(original_file);
    fclose(backup_file);
    
    printf("Backup created: %s\n", backup_filename);
}

void list_backups(const char *filename) {
    char command[MAX_FILENAME + 20];
    snprintf(command, sizeof(command), "ls -1 %s_backup_* 2> /dev/null", filename);
    printf("Backups for %s:\n", filename);
    system(command);
}

void restore_backup(const char *original_filename, const char *backup_filename) {
    FILE *backup_file = fopen(backup_filename, "rb");
    if (!backup_file) {
        perror("Error opening backup file");
        return;
    }

    FILE *original_file = fopen(original_filename, "wb");
    if (!original_file) {
        perror("Error opening original file for writing");
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), backup_file)) > 0) {
        fwrite(buffer, 1, bytes, original_file);
    }

    fclose(backup_file);
    fclose(original_file);
    
    printf("Restored %s from %s\n", original_filename, backup_filename);
}

void display_menu() {
    printf("File Backup System\n");
    printf("1. Backup file\n");
    printf("2. List backups\n");
    printf("3. Restore backup\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char filename[MAX_FILENAME];
    int choice;
    
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                backup_file(filename);
                break;
            case 2:
                list_backups(filename);
                break;
            case 3: {
                char backup_name[MAX_FILENAME];
                printf("Enter the name of the backup file to restore: ");
                scanf("%s", backup_name);
                restore_backup(filename, backup_name);
                break;
            }
            case 4:
                printf("Exiting the File Backup System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}