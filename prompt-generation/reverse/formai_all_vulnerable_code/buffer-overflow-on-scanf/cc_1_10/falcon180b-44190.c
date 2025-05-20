//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_path[MAX_FILE_NAME_LENGTH];
} file_backup_t;

void backup_file(file_backup_t *backup_info) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(backup_file_name, MAX_FILE_NAME_LENGTH, "%Y-%m-%d_%H-%M-%S", tm);

    strcat(backup_info->backup_path, backup_file_name);
    strcat(backup_info->backup_path, ".bak");

    FILE *backup_file = fopen(backup_info->backup_path, "w");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_info->backup_path);
        return;
    }

    FILE *file = fopen(backup_info->file_name, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", backup_info->file_name);
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup file %s created successfully\n", backup_info->backup_path);
}

int main() {
    int num_files;
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    file_backup_t backup_info[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name for %d: ", i+1);
        scanf("%s", backup_info[i].file_name);

        printf("Enter the backup path for %s: ", backup_info[i].file_name);
        scanf("%s", backup_info[i].backup_path);
    }

    for (int i = 0; i < num_files; i++) {
        backup_file(&backup_info[i]);
    }

    return 0;
}