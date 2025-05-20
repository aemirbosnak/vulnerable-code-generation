//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 20

void create_backup(char *file_name) {
    char buffer[1000];
    char backup_file_name[MAX_FILE_NAME_LENGTH + 6];
    FILE *file_ptr, *backup_ptr;
    int len = strlen(file_name);

    // add .bak extension to file name
    strncpy(backup_file_name, file_name, len-4);
    strcpy(&backup_file_name[len-4], ".bak");

    // open original file as read mode
    file_ptr = fopen(file_name, "r");

    // if original file is not found, exit program with error message
    if (file_ptr == NULL) {
        printf("Error opening file. File Does Not Exist!\n");
        exit(EXIT_FAILURE);
    }

    // open backup file as write mode
    backup_ptr = fopen(backup_file_name, "w");

    // copy content from original file to backup file
    while (fgets(buffer, sizeof(buffer), file_ptr)) {
        fputs(buffer, backup_ptr);
    }

    printf("Backup created successfully!\n");

    // close original and backup files
    fclose(file_ptr);
    fclose(backup_ptr);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter name of file to backup (with extension): ");
    scanf("%s", file_name);

    create_backup(file_name);

    return 0;
}