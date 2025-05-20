//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void create_directory(const char *dir_name) {
    struct stat st = {0};
    if (stat(dir_name, &st) == -1) {
        if (mkdir(dir_name, 0700) == -1) {
            perror("Failed to create directory");
            exit(EXIT_FAILURE);
        }
    }
}

void backup_file(const char *source_file, const char *backup_dir) {
    FILE *source = fopen(source_file, "rb");
    if (!source) {
        perror("Failed to open source file");
        return;
    }

    char backup_file_path[256];
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s.bak", backup_dir, source_file);
   
    FILE *backup = fopen(backup_file_path, "wb");
    if (!backup) {
        perror("Failed to create backup file");
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, backup);
    }

    printf("Backup of '%s' created at '%s'\n", source_file, backup_file_path);

    fclose(source);
    fclose(backup);
}

void list_files(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Files in directory '%s':\n", dir_name);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void backup_all_files(const char *dir_name, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            backup_file(file_path, backup_dir);
        }
    }
    closedir(dp);
}

int main() {
    char source_dir[256];
    char backup_dir[256];

    printf("Enter the source directory for backup: ");
    scanf("%255s", source_dir);

    printf("Enter the backup directory: ");
    scanf("%255s", backup_dir);

    create_directory(backup_dir);
    
    int choice;
    do {
        printf("\n1. List files in source directory\n");
        printf("2. Backup a specific file\n");
        printf("3. Backup all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                list_files(source_dir);
                break;
            case 2: {
                char file_name[256];
                printf("Enter the file name to backup: ");
                scanf("%255s", file_name);
                char file_path[256];
                snprintf(file_path, sizeof(file_path), "%s/%s", source_dir, file_name);
                backup_file(file_path, backup_dir);
                break;
            }
            case 3:
                backup_all_files(source_dir, backup_dir);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}