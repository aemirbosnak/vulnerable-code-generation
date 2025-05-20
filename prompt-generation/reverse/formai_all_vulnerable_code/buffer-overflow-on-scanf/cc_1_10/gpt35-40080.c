//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATH_LENGTH 100
#define MAX_BUFFER_SIZE 1024
#define MAX_BACKUPS 10

void create_backup(char* path, char* backup_name) {
    char backup_dir[MAX_PATH_LENGTH] = "Backups/";
    strcat(backup_dir, backup_name);
    
    char command[MAX_BUFFER_SIZE] = "";
    sprintf(command, "mkdir %s", backup_dir);
    system(command);
    
    strcat(backup_dir, "/");
    strcat(path, "*");
    sprintf(command, "cp -r %s %s", path, backup_dir);
    system(command);
}

void delete_backup(char* backup_name) {
    char backup_dir[MAX_PATH_LENGTH] = "Backups/";
    strcat(backup_dir, backup_name);
    
    char command[MAX_BUFFER_SIZE] = "";
    sprintf(command, "rm -r %s", backup_dir);
    system(command);
}

int main() {
    char path[MAX_PATH_LENGTH];
    char backup_name[MAX_PATH_LENGTH];
    
    printf("Enter a path to the directory you would like to backup:\n");
    scanf("%s", path);
    
    printf("Enter a name for your backup:\n");
    scanf("%s", backup_name);
    
    create_backup(path, backup_name);
    
    printf("Backup created successfully!\n");
    
    printf("Would you like to delete a backup? (yes/no)\n");
    char delete_backup_choice[MAX_PATH_LENGTH];
    scanf("%s", delete_backup_choice);
    
    if(strcmp(delete_backup_choice, "yes") == 0) {
        printf("Which backup would you like to delete?\n");
        char backup_to_delete[MAX_PATH_LENGTH];
        scanf("%s", backup_to_delete);
        
        delete_backup(backup_to_delete);
        
        printf("Backup deleted successfully!\n");
    }
    
    return 0;
}