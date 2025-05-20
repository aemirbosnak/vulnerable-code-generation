//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_PATH_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_path[MAX_FILE_PATH_LENGTH];
    time_t last_modified_time;
} File;

void backup_file(File* file) {
    char backup_file_path[MAX_FILE_PATH_LENGTH];
    strcpy(backup_file_path, file->file_path);
    strcat(backup_file_path, ".bak");

    FILE* backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file '%s'\n", backup_file_path);
        exit(1);
    }

    FILE* input_file = fopen(file->file_path, "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file '%s'\n", file->file_path);
        fclose(backup_file);
        exit(1);
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(input_file);
    fclose(backup_file);
}

int main() {
    int num_files;
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    File files[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name and path for file #%d:\n", i + 1);
        scanf(" %s", files[i].file_name);
        scanf(" %s", files[i].file_path);

        FILE* file = fopen(files[i].file_path, "r");
        if (file == NULL) {
            printf("Error: Failed to open file '%s'\n", files[i].file_path);
            exit(1);
        }

        fclose(file);
        files[i].last_modified_time = time(NULL);
    }

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_files; i++) {
            if (difftime(current_time, files[i].last_modified_time) > 3600) {
                backup_file(&files[i]);
                files[i].last_modified_time = current_time;
            }
        }

        sleep(3600); // Wait for 1 hour before checking again
    }

    return 0;
}