//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_FILE_EXTENSION ".bak"

void backup_file(char *file_name) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s\n", backup_file_name);
        exit(1);
    }

    FILE *original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error opening original file %s\n", file_name);
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_name> <backup_directory>\n", argv[0]);
        exit(1);
    }

    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, argv[1]);

    char backup_directory[MAX_FILE_NAME_LENGTH];
    strcpy(backup_directory, argv[2]);

    strcat(backup_directory, "/");

    if (mkdir(backup_directory, 0777)!= 0) {
        printf("Error creating backup directory %s\n", backup_directory);
        exit(1);
    }

    backup_file(file_name);

    return 0;
}