//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BACKUP_DIR_SIZE 100

// Structure to hold file information
typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char backup_dir[MAX_BACKUP_DIR_SIZE];
} FileInfo;

void backup_file(FileInfo* file_info) {
    FILE* backup_file = fopen(file_info->backup_dir, "a");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    FILE* input_file = fopen(file_info->file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(input_file);
    fclose(backup_file);
}

int main() {
    FileInfo file_info;

    // Get user input for file name and backup directory
    printf("Enter file name: ");
    scanf("%s", file_info.file_name);

    printf("Enter backup directory: ");
    scanf("%s", file_info.backup_dir);

    // Backup the file
    backup_file(&file_info);

    return 0;
}