//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 100
#define MAX_PATH 1000

struct file_info {
    char name[MAX_FILE_NAME];
    char path[MAX_PATH];
    time_t modified_time;
};

int main() {
    FILE *backup_file;
    struct file_info file_list[1000];
    int num_files = 0;
    char backup_path[MAX_PATH];
    time_t current_time;
    struct tm *time_info;

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);

    // Get backup path
    printf("Enter backup path: ");
    scanf("%s", backup_path);

    // Open backup file
    backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        exit(1);
    }

    // Get list of files to backup
    printf("Enter file names to backup (press enter when done):\n");
    while (fgets(file_list[num_files].name, MAX_FILE_NAME, stdin)!= NULL) {
        num_files++;
    }

    // Backup files
    for (int i = 0; i < num_files; i++) {
        strcpy(file_list[i].path, "");
        if (file_list[i].name[0]!= '/') {
            strcat(file_list[i].path, "./");
        }
        strcat(file_list[i].path, file_list[i].name);

        if (file_exists(file_list[i].path)) {
            backup_file = fopen(backup_path, "a");
            fprintf(backup_file, "%s\n", file_list[i].path);
            fclose(backup_file);

            printf("Backed up file: %s\n", file_list[i].path);
        } else {
            printf("File not found: %s\n", file_list[i].path);
        }
    }

    // Close backup file
    fclose(backup_file);

    printf("Backup complete.\n");
    return 0;
}

int file_exists(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file!= NULL) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}