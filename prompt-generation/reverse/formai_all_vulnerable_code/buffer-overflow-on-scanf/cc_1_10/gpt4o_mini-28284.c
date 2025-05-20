//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define BUFFER_SIZE 4096

void get_timestamp(char *buffer, int size) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, size, "%Y%m%d%H%M%S", timeinfo);
}

void backup_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    
    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src))) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

void create_backup(const char *directory, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    char timestamp[15];
    get_timestamp(timestamp, sizeof(timestamp));

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only process regular files
            char source_path[PATH_MAX];
            char destination_path[PATH_MAX];
            
            snprintf(source_path, sizeof(source_path), "%s/%s", directory, entry->d_name);
            snprintf(destination_path, sizeof(destination_path), "%s/%s_%s.bak", backup_dir, entry->d_name, timestamp);
            
            printf("Backing up %s to %s\n", source_path, destination_path);
            backup_file(source_path, destination_path);
        }
    }
    closedir(dp);
}

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        if (mkdir(backup_dir, 0700) == -1) {
            perror("Failed to create backup directory");
        }
    }
}

void display_menu() {
    printf("---------- File Backup System ----------\n");
    printf("1. Create Backup\n");
    printf("2. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    char source_directory[PATH_MAX];
    char backup_directory[PATH_MAX];

    printf("Enter the source directory for backup: ");
    fgets(source_directory, sizeof(source_directory), stdin);
    source_directory[strcspn(source_directory, "\n")] = 0; // Remove newline

    snprintf(backup_directory, sizeof(backup_directory), "%s_backup", source_directory);
    create_backup_directory(backup_directory);

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_backup(source_directory, backup_directory);
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 2);
   
    return 0;
}