//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void create_backup(const char *source_file, const char *backup_dir) {
    FILE *src, *dest;
    char backup_filename[256];
    char buffer[BUFFER_SIZE];
    size_t bytes;
    
    // Prepare the backup filename with timestamp
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(backup_filename, "%s/%s_backup_%04d%02d%02d_%02d%02d%02d.txt", 
            backup_dir, 
            source_file, 
            t->tm_year + 1900, 
            t->tm_mon + 1, 
            t->tm_mday, 
            t->tm_hour, 
            t->tm_min, 
            t->tm_sec);
    
    // Open source file for reading
    src = fopen(source_file, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }
    
    // Open destination file for writing
    dest = fopen(backup_filename, "wb");
    if (!dest) {
        perror("Error creating backup file");
        fclose(src);
        return;
    }
    
    // Copy the contents from source to backup file
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    // Close both files
    fclose(src);
    fclose(dest);
    
    printf("Backup created successfully: %s\n", backup_filename);
}

void create_backup_directory(const char *backup_dir) {
    // Create the backup directory if it doesn't exist
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
    }
}

int main() {
    char source_file[256];
    char backup_dir[256];
    
    printf("Enter the path of the file to back up: ");
    scanf("%s", source_file);
    
    printf("Enter the backup directory: ");
    scanf("%s", backup_dir);
    
    // Create the backup directory if it does not already exist
    create_backup_directory(backup_dir);
    
    // Begin the backup process
    create_backup(source_file, backup_dir);
    
    return 0;
}