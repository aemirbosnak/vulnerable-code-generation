//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_name[50], backup_file_name[50];
    int choice, overwrite_choice;
    
    // get file name and create backup file name
    printf("Enter file name to backup:\n");
    scanf("%s", file_name);
    sprintf(backup_file_name, "%s.backup", file_name);
    
    // check if file exists
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File does not exist\n");
        exit(1);
    }
    fclose(file);
    
    // check if a backup file already exists
    FILE* backup_file = fopen(backup_file_name, "r");
    if (backup_file != NULL) {
        printf("A backup file already exists\n");
        printf("Do you want to overwrite the existing backup file? (0/1)\n");
        scanf("%d", &overwrite_choice);
        if (overwrite_choice == 0) {
            exit(2);
        }
    } 
    
    // create backup file
    file = fopen(file_name, "r");
    backup_file = fopen(backup_file_name, "w");
    printf("Creating backup file...\n");
    char ch = fgetc(file);
    while (ch != EOF) {
        fputc(ch, backup_file);
        ch = fgetc(file);
    }
    fclose(file);
    fclose(backup_file);
    printf("Backup file created successfully!\n");
    
    // give user option to restore file from backup file
    printf("Do you want to restore the original file from the backup file? (0/1)\n");
    scanf("%d", &choice);
    if (choice == 1) {
        file = fopen(file_name, "w");
        backup_file = fopen(backup_file_name, "r");
        printf("Restoring file from backup...\n");
        ch = fgetc(backup_file);
        while (ch != EOF) {
            fputc(ch, file);
            ch = fgetc(backup_file);
        }
        fclose(file);
        fclose(backup_file);
        printf("File restored successfully!\n");
    }
    
    return 0;
}