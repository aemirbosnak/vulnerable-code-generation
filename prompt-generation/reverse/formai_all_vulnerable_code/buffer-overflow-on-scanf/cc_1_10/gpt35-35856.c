//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

void backup_file(char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    
    printf("Enter the name of the file to backup:\n");
    scanf("%s", filename);
    
    backup_file(filename);
    
    printf("File backed up successfully!\n");
    
    return 0;
}

void backup_file(char *filename) {
    char *extensions[] = {".bak", ".bak1", ".bak2", ".bak3", ".bak4", ".bak5"};
    char file_contents[MAX_FILE_CONTENT_LENGTH];
    int i, j, found_file, bak_count;
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    fgets(file_contents, MAX_FILE_CONTENT_LENGTH, fp);
    
    fclose(fp);
    
    found_file = 0;
    bak_count = 0;
    for(i = 0; i < 6; i++) {
        char backup_filename[MAX_FILENAME_LENGTH];
        strcpy(backup_filename, filename);
        strcat(backup_filename, extensions[i]);
        
        fp = fopen(backup_filename, "r");
        if(fp != NULL) {
            fclose(fp);
            bak_count++;
        } else if(found_file == 0) {
            found_file = 1;
            fp = fopen(backup_filename, "w");
            if(fp == NULL) {
                printf("Error creating backup file!\n");
                exit(1);
            }
            fputs(file_contents, fp);
            fclose(fp);
        }
    }
    
    if(found_file == 0 && bak_count == 6) {
        char oldest_backup[MAX_FILENAME_LENGTH];
        strcpy(oldest_backup, filename);
        strcat(oldest_backup, extensions[0]);
        
        remove(oldest_backup);
        
        for(i = 1; i < 6; i++) {
            char old_backup[MAX_FILENAME_LENGTH];
            strcpy(old_backup, filename);
            strcat(old_backup, extensions[i-1]);
            char new_backup[MAX_FILENAME_LENGTH];
            strcpy(new_backup, filename);
            strcat(new_backup, extensions[i]);
            
            rename(old_backup, new_backup);
        }
        
        fp = fopen(oldest_backup, "w");
        if(fp == NULL) {
            printf("Error creating oldest backup file!\n");
            exit(1);
        }
        fputs(file_contents, fp);
        fclose(fp);
    }
}