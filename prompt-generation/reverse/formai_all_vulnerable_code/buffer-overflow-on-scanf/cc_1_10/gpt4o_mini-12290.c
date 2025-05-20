//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES 100

void print_menu() {
    printf("=== File Backup System ===\n");
    printf("1. Backup a File\n");
    printf("2. Restore a File\n");
    printf("3. List Backups\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

void create_backup(const char *src_path) {
    char backup_path[MAX_PATH_LENGTH];
    snprintf(backup_path, sizeof(backup_path), "%s.bak", src_path);
    
    FILE *src_file = fopen(src_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *backup_file = fopen(backup_path, "wb");
    if (!backup_file) {
        perror("Failed to create backup file");
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    fclose(src_file);
    fclose(backup_file);
    printf("Backup created: %s\n", backup_path);
}

void restore_backup(const char *src_path) {
    char backup_path[MAX_PATH_LENGTH];
    snprintf(backup_path, sizeof(backup_path), "%s.bak", src_path);
    
    FILE *backup_file = fopen(backup_path, "rb");
    if (!backup_file) {
        perror("Backup file does not exist");
        return;
    }

    FILE *restored_file = fopen(src_path, "wb");
    if (!restored_file) {
        perror("Failed to restore file");
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), backup_file)) > 0) {
        fwrite(buffer, 1, bytes, restored_file);
    }

    fclose(backup_file);
    fclose(restored_file);
    printf("File restored from backup: %s\n", backup_path);
}

void list_backups() {
    printf("\n=== List of Backups ===\n");
    struct stat buffer;
    for (int i = 0; i < MAX_FILES; ++i) {
        char backup_name[MAX_PATH_LENGTH];
        snprintf(backup_name, sizeof(backup_name), "file%d.bak", i);
        
        if (stat(backup_name, &buffer) == 0) {
            printf("Backup found: %s\n", backup_name);
        }
    }
    printf("=========================\n");
}

int main() {
    int choice;
    char file_path[MAX_PATH_LENGTH];

    while (1) {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the path of the file to backup: ");
                scanf("%s", file_path);
                create_backup(file_path);
                break;
            case 2:
                printf("Enter the path of the file to restore: ");
                scanf("%s", file_path);
                restore_backup(file_path);
                break;
            case 3:
                list_backups();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}