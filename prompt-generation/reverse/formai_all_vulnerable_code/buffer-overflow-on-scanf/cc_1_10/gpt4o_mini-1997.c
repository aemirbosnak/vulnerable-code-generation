//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function prototypes
void backup_file(const char *source_file, const char *backup_dir);
void display_backups(const char *backup_dir);
void restore_file(const char *backup_file, const char *restore_dir);
void create_backup_directory(const char *backup_dir);

int main() {
    char source_file[256];
    char backup_dir[256] = "./backups";
    char restore_dir[256] = "./restore";
    int choice;

    create_backup_directory(backup_dir);

    while (1) {
        printf("\nFile Backup System\n");
        printf("1. Backup a file\n");
        printf("2. Display backups\n");
        printf("3. Restore a backup\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter source file path to backup: ");
                fgets(source_file, sizeof(source_file), stdin);
                source_file[strcspn(source_file, "\n")] = '\0'; // Remove newline
                backup_file(source_file, backup_dir);
                break;

            case 2:
                display_backups(backup_dir);
                break;

            case 3:
                printf("Enter backup file name to restore: ");
                fgets(source_file, sizeof(source_file), stdin);
                source_file[strcspn(source_file, "\n")] = '\0'; // Remove newline
                restore_file(source_file, restore_dir);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Function to back up a file
void backup_file(const char *source_file, const char *backup_dir) {
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    char backup_file[512];
    snprintf(backup_file, sizeof(backup_file), "%s/%s.bak", backup_dir, strrchr(source_file, '/') + 1);
    
    FILE *backup = fopen(backup_file, "wb");
    if (backup == NULL) {
        perror("Error opening backup file");
        fclose(source);
        return;
    }

    size_t bytes;
    unsigned char buffer[BUFFER_SIZE];

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, backup);
    }

    fclose(source);
    fclose(backup);
    printf("Backup completed for: %s to %s\n", source_file, backup_file);
}

// Function to display backups in the backup directory
void display_backups(const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(backup_dir);

    if (dp == NULL) {
        perror("Error opening backup directory");
        return;
    }

    printf("\nBackups in %s:\n", backup_dir);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // skip hidden files
            printf("- %s\n", entry->d_name);
        }
    }
    
    closedir(dp);
}

// Function to restore a backup file
void restore_file(const char *backup_file, const char *restore_dir) {
    char backup_file_path[512];
    snprintf(backup_file_path, sizeof(backup_file_path), "./backups/%s", backup_file);

    FILE *backup = fopen(backup_file_path, "rb");
    if (backup == NULL) {
        perror("Error opening backup file");
        return;
    }

    char restore_file_path[512];
    snprintf(restore_file_path, sizeof(restore_file_path), "%s/%s", restore_dir, backup_file);

    FILE *restore = fopen(restore_file_path, "wb");
    if (restore == NULL) {
        perror("Error opening restore file");
        fclose(backup);
        return;
    }

    size_t bytes;
    unsigned char buffer[BUFFER_SIZE];
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), backup)) > 0) {
        fwrite(buffer, 1, bytes, restore);
    }

    fclose(backup);
    fclose(restore);
    printf("Restored backup: %s to %s\n", backup_file, restore_file_path);
}

// Function to create a backup directory if it does not exist
void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
    }
}