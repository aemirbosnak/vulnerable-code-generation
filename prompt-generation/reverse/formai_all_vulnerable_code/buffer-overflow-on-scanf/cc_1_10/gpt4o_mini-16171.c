//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024

void list_files(const char *path);
int copy_file(const char *src, const char *dest);
void backup_files(const char *src_dir, const char *backup_dir);
void create_backup_directory(const char *backup_dir);
int file_exists(const char *filepath);
void show_instructions();

int main() {
    char source_directory[256];
    char backup_directory[256];

    show_instructions();

    printf("Enter the source directory path: ");
    scanf("%s", source_directory);
    
    printf("Enter the backup directory path: ");
    scanf("%s", backup_directory);
    
    create_backup_directory(backup_directory);
    
    printf("Files in source directory:\n");
    list_files(source_directory);
    
    backup_files(source_directory, backup_directory);
    
    printf("Backup completed successfully!\n");
    
    return 0;
}

void show_instructions() {
    printf("=== C File Backup System ===\n");
    printf("This program allows you to back up files from a source directory...\n");
    printf("To use this program, you will need to specify the source and backup directory paths.\n");
    printf("All files from the source directory will be copied to the backup directory.\n\n");
}

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        printf("Could not open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            printf("%s\n", entry->d_name);
        }
    }
    
    closedir(dp);
}

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};

    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
        printf("Backup directory created: %s\n", backup_dir);
    } else {
        printf("Backup directory already exists: %s\n", backup_dir);
    }
}

int copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    
    if (source == NULL || destination == NULL) {
        printf("Error opening files for copying: %s to %s\n", src, dest);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    
    return 0;
}

void backup_files(const char *src_dir, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);
    
    if (dp == NULL) {
        printf("Could not open source directory: %s\n", src_dir);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char src_path[512];
            char dest_path[512];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, entry->d_name);

            if (copy_file(src_path, dest_path) == 0) {
                printf("Copied: %s to %s\n", src_path, dest_path);
            } else {
                printf("Failed to copy: %s\n", src_path);
            }
        }
    }
    
    closedir(dp);
}