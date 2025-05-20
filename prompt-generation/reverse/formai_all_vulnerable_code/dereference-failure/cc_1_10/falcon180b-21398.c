//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

// Function to get current time as string
char *get_current_time() {
    time_t now = time(NULL);
    return ctime(&now);
}

// Function to create a backup file with current timestamp
void create_backup_file(char *filename) {
    char backup_filename[strlen(filename) + 20]; // Add 20 for timestamp
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    strcat(backup_filename, get_current_time());

    FILE *backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_filename);
        exit(1);
    }

    fclose(backup_file);
}

// Function to copy file contents to backup file
void backup_file(FILE *src_file, FILE *dest_file) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    if (ferror(src_file)) {
        printf("Error: Failed to read from source file\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    char *src_filename = argv[1];
    char *dest_filename = argv[2];

    // Create backup file
    create_backup_file(dest_filename);

    // Open source and destination files
    FILE *src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        printf("Error: Failed to open source file %s\n", src_filename);
        exit(1);
    }

    FILE *dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        printf("Error: Failed to open destination file %s\n", dest_filename);
        exit(1);
    }

    // Backup file
    backup_file(src_file, dest_file);

    // Close files
    fclose(src_file);
    fclose(dest_file);

    printf("Backup completed successfully\n");

    return 0;
}