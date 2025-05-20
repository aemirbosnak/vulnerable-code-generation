//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    time_t last_modified;
} FileInfo;

int backup_file(char *backup_dir, char *file_name) {
    char backup_file_path[MAX_FILE_NAME_LEN];
    strcpy(backup_file_path, backup_dir);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_name);

    FILE *backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_file_path);
        return 1;
    }

    FILE *original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error: Failed to open original file %s\n", file_name);
        fclose(backup_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    return 0;
}

int main() {
    char backup_dir[MAX_FILE_NAME_LEN];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backup_file(backup_dir, file_name);

    return 0;
}