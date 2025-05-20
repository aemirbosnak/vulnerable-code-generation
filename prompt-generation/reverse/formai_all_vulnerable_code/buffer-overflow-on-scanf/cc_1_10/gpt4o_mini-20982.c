//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to create a directory if it does not exist
void create_directory(const char *path) {
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
        printf("🎨 Created backup directory at: %s\n", path);
    }
}

// Function to copy a file from source to destination
int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("🛑 Failed to open source file");
        return -1;
    }
    
    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("🛑 Failed to create destination file");
        fclose(src);
        return -1;
    }

    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("✅ Successfully backed up: %s to %s\n", source, destination);
    return 0;
}

// Main function
int main() {
    char file_to_backup[256];
    char backup_directory[256];
    char backup_path[512];

    printf("✨ Welcome to the Artistic File Backup System! 🎉\n");
    
    // Prompt user for file to backup
    printf("🔍 Please enter the path of the file you wish to backup: ");
    scanf("%s", file_to_backup);

    // Prompt user for backup directory
    printf("📁 Please enter the backup directory: ");
    scanf("%s", backup_directory);

    // Create backup directory if it does not exist
    create_directory(backup_directory);

    // Construct the backup file path
    snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", backup_directory, strrchr(file_to_backup, '/') ? strrchr(file_to_backup, '/') + 1 : file_to_backup);

    // Remove existing backup if it exists
    if (remove(backup_path) == 0) {
        printf("🗑️ Removed existing backup: %s\n", backup_path);
    }

    // Copy the file to the backup directory
    if (copy_file(file_to_backup, backup_path) == -1) {
        printf("❌ File backup process failed.\n");
        return EXIT_FAILURE;
    }
    
    printf("🎆 Your file has been backed up with flair!\n");
    return EXIT_SUCCESS;
}