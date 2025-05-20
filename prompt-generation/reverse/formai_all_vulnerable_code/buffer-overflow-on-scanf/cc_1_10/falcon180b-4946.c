//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BACKUP_DIR 50
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME];
    char backup_dir[MAX_BACKUP_DIR];
    int file_size;
} FileInfo;

int main(int argc, char *argv[]) {
    FILE *file;
    char backup_dir[MAX_BACKUP_DIR];
    char line[MAX_FILE_NAME];
    char *delim = ",";
    FileInfo file_info;
    int count = 0;

    // Get the backup directory from user input
    printf("Enter the backup directory: ");
    scanf("%s", backup_dir);

    // Open the file to read
    file = fopen("file.csv", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_FILE_NAME, file)!= NULL) {
        count++;

        // Split the line into fields
        char *token = strtok(line, delim);
        strcpy(file_info.file_name, token);
        token = strtok(NULL, delim);
        strcpy(file_info.backup_dir, token);
        token = strtok(NULL, delim);
        file_info.file_size = atoi(token);

        // Create the backup directory if it does not exist
        char backup_dir_path[MAX_FILE_NAME];
        strcpy(backup_dir_path, backup_dir);
        strcat(backup_dir_path, "/");
        strcat(backup_dir_path, file_info.backup_dir);
        mkdir(backup_dir_path, 0777);

        // Backup the file
        char backup_file_path[MAX_FILE_NAME];
        strcpy(backup_file_path, backup_dir_path);
        strcat(backup_file_path, "/");
        strcat(backup_file_path, file_info.file_name);
        FILE *backup_file = fopen(backup_file_path, "w");

        if (backup_file == NULL) {
            printf("Error creating backup file.\n");
            exit(1);
        }

        char ch;
        while ((ch = fgetc(file))!= EOF) {
            fputc(ch, backup_file);
        }

        fclose(backup_file);
        fclose(file);
        printf("Backup complete for %s.\n", line);
    }

    printf("Total number of files backed up: %d\n", count);

    return 0;
}