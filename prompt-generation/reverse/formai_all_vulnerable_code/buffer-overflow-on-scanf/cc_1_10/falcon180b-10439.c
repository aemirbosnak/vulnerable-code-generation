//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_DIR "backup"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} file_info_t;

int backup_file(char *file_name) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, BACKUP_DIR);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, file_name);

    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s\n", backup_file_name);
        return 1;
    }

    FILE *original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error opening original file %s\n", file_name);
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
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    file_info_t file_info;
    strcpy(file_info.file_name, file_name);
    file_info.last_modified = time(NULL);

    FILE *file_info_file = fopen("file_info.txt", "a");
    if (file_info_file == NULL) {
        printf("Error opening file_info.txt\n");
        return 1;
    }

    fprintf(file_info_file, "%s %ld\n", file_info.file_name, file_info.last_modified);
    fclose(file_info_file);

    backup_file(file_name);

    return 0;
}