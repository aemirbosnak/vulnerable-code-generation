//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_DIR_LENGTH 256
#define BUFFER_SIZE 1024

typedef struct {
    char *file_name;
    char *backup_dir;
    time_t last_modified;
} file_t;

void backup_file(file_t *file) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, file->file_name);
    strcat(backup_file_name, ".bak");
    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_file_name);
        exit(1);
    }
    FILE *source_file = fopen(file->file_name, "r");
    if (source_file == NULL) {
        printf("Error opening source file: %s\n", file->file_name);
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, source_file)!= NULL) {
        fputs(buffer, backup_file);
    }
    fclose(source_file);
    fclose(backup_file);
    printf("Backed up %s to %s\n", file->file_name, backup_file_name);
}

int main() {
    int num_files;
    printf("Enter number of files to backup: ");
    scanf("%d", &num_files);
    file_t *files = malloc(num_files * sizeof(file_t));
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i+1);
        scanf("%s", files[i].file_name);
        printf("Enter backup directory: ");
        scanf("%s", files[i].backup_dir);
        files[i].last_modified = 0;
    }
    while (1) {
        sleep(60);
        time_t current_time = time(NULL);
        for (int i = 0; i < num_files; i++) {
            if (current_time - files[i].last_modified >= 3600) {
                backup_file(&files[i]);
                files[i].last_modified = current_time;
            }
        }
    }
    return 0;
}