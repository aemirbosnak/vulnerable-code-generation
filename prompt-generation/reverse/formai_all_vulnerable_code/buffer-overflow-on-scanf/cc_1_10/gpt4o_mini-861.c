//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

// Function prototypes
void display_menu();
void backup_file(const char *source, const char *destination);
void restore_file(const char *backup, const char *original);
void list_backups(const char *backup_dir);
int is_valid_path(const char *path);

// Entry point of the program
int main() {
    int choice;
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    char backup_dir[MAX_PATH_LENGTH] = "./backups/";

    // Create backup directory if it does not exist
    mkdir(backup_dir, 0777);

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file number to backup: ");
                scanf("%s", source);
                snprintf(destination, sizeof(destination), "%s%s.bak", backup_dir, source);
                backup_file(source, destination);
                break;
            case 2:
                printf("Enter backup file to restore: ");
                scanf("%s", source);
                printf("Enter original file name: ");
                scanf("%s", destination);
                restore_file(source, destination);
                break;
            case 3:
                list_backups(backup_dir);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to display the menu
void display_menu() {
    printf("\n--- C File Backup System ---\n");
    printf("1. Backup a file\n");
    printf("2. Restore a file\n");
    printf("3. List backups\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to back up a file from source to destination
void backup_file(const char *source, const char *destination) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!is_valid_path(source)) {
        printf("Invalid source file path.\n");
        return;
    }

    src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return;
    }

    dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        perror("Error creating backup file");
        fclose(src_file);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    printf("Backup successfully created at: %s\n", destination);

    fclose(src_file);
    fclose(dest_file);
}

// Function to restore a backup file to the original location
void restore_file(const char *backup, const char *original) {
    FILE *backup_file, *original_file;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!is_valid_path(backup)) {
        printf("Invalid backup file path.\n");
        return;
    }

    backup_file = fopen(backup, "rb");
    if (backup_file == NULL) {
        perror("Error opening backup file");
        return;
    }

    original_file = fopen(original, "wb");
    if (original_file == NULL) {
        perror("Error creating original file");
        fclose(backup_file);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), backup_file)) > 0) {
        fwrite(buffer, 1, bytes, original_file);
    }

    printf("File successfully restored to: %s\n", original);

    fclose(backup_file);
    fclose(original_file);
}

// Function to list all backup files in the backup directory
void list_backups(const char *backup_dir) {
    struct stat path_stat;
    if (stat(backup_dir, &path_stat) != 0 || !S_ISDIR(path_stat.st_mode)) {
        printf("Backup directory does not exist.\n");
        return;
    }

    printf("Backup files:\n");
    system("ls -1 ./backups/"); // Use system to list files
}

// Function to validate file paths
int is_valid_path(const char *path) {
    return (path != NULL && strlen(path) > 0 && access(path, F_OK) == 0);
}