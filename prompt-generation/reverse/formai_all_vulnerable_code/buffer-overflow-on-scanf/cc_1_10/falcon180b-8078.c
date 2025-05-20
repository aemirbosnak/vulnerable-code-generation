//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
    size_t file_size;
} FileInfo;

int main() {
    FILE *backup_file;
    FileInfo file_info;
    char backup_filename[MAX_FILE_NAME_LENGTH];
    char *backup_dir = "backup/";
    time_t current_time;

    printf("Welcome to the Cheerful File Backup System!\n");

    // Get the current time
    time(&current_time);

    // Get the file name from user input
    printf("Please enter the file name to backup: ");
    scanf("%s", file_info.file_name);

    // Get the file size
    file_info.file_size = 0;
    backup_file = fopen(file_info.file_name, "rb");
    if (backup_file!= NULL) {
        fseek(backup_file, 0, SEEK_END);
        file_info.file_size = ftell(backup_file);
        fclose(backup_file);
    }

    // Create the backup filename
    strcpy(backup_filename, backup_dir);
    strcat(backup_filename, file_info.file_name);
    strcat(backup_filename, ".");
    strcat(backup_filename, ctime(&current_time));

    // Open the backup file
    backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: could not open backup file %s.\n", backup_filename);
        return 1;
    }

    // Backup the file
    backup_file = fopen(file_info.file_name, "rb");
    if (backup_file == NULL) {
        printf("Error: could not open file %s.\n", file_info.file_name);
        return 1;
    }
    fwrite(file_info.file_name, 1, MAX_FILE_NAME_LENGTH, backup_file);
    fwrite(&file_info.last_modified, sizeof(time_t), 1, backup_file);
    fwrite(&file_info.file_size, sizeof(size_t), 1, backup_file);
    fwrite(file_info.file_name, 1, MAX_FILE_NAME_LENGTH, backup_file);
    fwrite(file_info.file_name, 1, file_info.file_size, backup_file);
    fclose(backup_file);

    // Print success message
    printf("Backup completed successfully!\n");

    return 0;
}