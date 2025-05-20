//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to backup a file
int backup_file(const char* src_file, const char* dest_file) {
    FILE* src_fp = fopen(src_file, "rb");
    if (src_fp == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE* dest_fp = fopen(dest_file, "wb");
    if (dest_fp == NULL) {
        perror("Error opening destination file");
        fclose(src_fp);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_fp)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dest_fp)!= bytes_read) {
            perror("Error writing to destination file");
            fclose(src_fp);
            fclose(dest_fp);
            remove(dest_file);
            return 1;
        }
    }

    if (ferror(src_fp)) {
        perror("Error reading from source file");
        fclose(src_fp);
        fclose(dest_fp);
        remove(dest_file);
        return 1;
    }

    if (fclose(src_fp)!= 0 || fclose(dest_fp)!= 0) {
        perror("Error closing files");
        remove(dest_file);
        return 1;
    }

    return 0;
}

int main() {
    const char* backup_dir = "backups";
    const char* src_file = "important_file.txt";
    const char* dest_file = "backup_file.txt";

    // Create backup directory if it doesn't exist
    if (mkdir(backup_dir, 0777) == -1) {
        if (errno!= EEXIST) {
            perror("Error creating backup directory");
            return 1;
        }
    }

    // Backup file
    if (backup_file(src_file, dest_file)!= 0) {
        return 1;
    }

    // Move backup file to backup directory
    char backup_path[strlen(backup_dir) + strlen(dest_file) + 2];
    strcpy(backup_path, backup_dir);
    strcat(backup_path, "/");
    strcat(backup_path, dest_file);

    if (rename(dest_file, backup_path)!= 0) {
        perror("Error moving backup file");
        return 1;
    }

    printf("Backup complete!\n");
    return 0;
}