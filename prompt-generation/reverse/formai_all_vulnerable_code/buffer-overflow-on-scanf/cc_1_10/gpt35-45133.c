//FormAI DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUPS 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t backup_time;
} Backup;

Backup backups[MAX_BACKUPS];
int num_backups = 0;

void backup(char* filename) {
    
    // If maximum number of backups has been reached, delete oldest backup
    if(num_backups == MAX_BACKUPS) {
        int oldest_backup_index = 0;
        for(int i = 1; i < num_backups; i++) {
            if (backups[i].backup_time < backups[oldest_backup_index].backup_time) {
                oldest_backup_index = i;
            }
        }
        printf("Maximum number of backups reached. Deleting oldest backup (%s).\n", backups[oldest_backup_index].filename);
        remove(backups[oldest_backup_index].filename);
        for(int i = oldest_backup_index; i < num_backups-1; i++) {
            backups[i] = backups[i+1];
        }
        num_backups--;
    }
    
    // Create new backup
    time_t current_time = time(NULL);
    char* time_string = ctime(&current_time);
    char backup_filename[MAX_FILENAME_LENGTH+30];
    strcpy(backup_filename, "backup_");
    strcat(backup_filename, time_string);
    backup_filename[strlen(backup_filename)-6] = '_'; // Remove new line character
    strcat(backup_filename, filename);
    FILE* original_file = fopen(filename, "rb");
    FILE* backup_file = fopen(backup_filename, "wb");
    if(original_file == NULL || backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        return;
    }
    char c;
    while((c = fgetc(original_file)) != EOF) {
        fputc(c, backup_file);
    }
    fclose(original_file);
    fclose(backup_file);
    Backup new_backup;
    strcpy(new_backup.filename, backup_filename);
    new_backup.backup_time = current_time;
    backups[num_backups] = new_backup;
    num_backups++;
    printf("Backup created: %s\n", backup_filename);
}

int main() {
    printf("Welcome to the Backup System.\n");
    char option;
    char filename[MAX_FILENAME_LENGTH];
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Backup a file\n");
        printf("2. Quit\n");
        scanf(" %c", &option);
        if(option == '1') {
            printf("Enter filename: ");
            scanf("%s", filename);
            backup(filename);
        }
        else if(option == '2') {
            printf("Goodbye!\n");
            exit(0);
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}