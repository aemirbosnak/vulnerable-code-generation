//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 1000

// Function to create a backup of a file
void create_backup(char* file_name) {
    char backup_name[MAX_FILE_NAME_LEN];
    strcpy(backup_name, file_name);
    strcat(backup_name, ".bak");

    FILE* backup_file = fopen(backup_name, "wb");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_name);
        return;
    }

    FILE* original_file = fopen(file_name, "rb");
    if (original_file == NULL) {
        printf("Error opening original file: %s\n", file_name);
        fclose(backup_file);
        remove(backup_name);
        return;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

// Function to check if a backup is needed
int check_backup(char* file_name, time_t last_modified) {
    struct stat file_stat;
    if (stat(file_name, &file_stat) == -1) {
        printf("Error getting file status: %s\n", file_name);
        return 0;
    }

    if (file_stat.st_mtime > last_modified) {
        printf("Backup needed for file: %s\n", file_name);
        return 1;
    }

    return 0;
}

// Function to get the modification time of a file
time_t get_file_modification_time(char* file_name) {
    struct stat file_stat;
    if (stat(file_name, &file_stat) == -1) {
        printf("Error getting file status: %s\n", file_name);
        return -1;
    }

    return file_stat.st_mtime;
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name: ");
    scanf("%s", file_name);

    time_t last_modified = get_file_modification_time(file_name);
    if (last_modified == -1) {
        return 1;
    }

    printf("Last modified: %s\n", ctime(&last_modified));

    int backup_needed = check_backup(file_name, last_modified);
    if (backup_needed) {
        create_backup(file_name);
    }

    return 0;
}