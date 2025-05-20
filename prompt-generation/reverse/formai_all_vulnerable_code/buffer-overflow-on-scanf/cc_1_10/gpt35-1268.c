//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUPS 5

int current_backup_id = 0;

void generate_backup_file_name(char *file_name, char *backup_file_name) {
    char backup_id[5];
    sprintf(backup_id, "%d", current_backup_id);
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");
    strcat(backup_file_name, backup_id);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];

    printf("Welcome to the Unique C File Backup System!\n");

    while(1) {
        printf("Enter the name of the file to backup: ");
        scanf("%s", file_name);

        FILE *file = fopen(file_name, "r");
        if(file == NULL) {
            printf("Error: Cannot find file %s\n", file_name);
            continue;
        }

        fclose(file);

        generate_backup_file_name(file_name, backup_file_name);
        printf("Backing up file %s to %s...\n", file_name, backup_file_name);

        // code to backup file goes here

        printf("Backup complete!\n");

        current_backup_id++;
        if(current_backup_id >= MAX_BACKUPS) {
            current_backup_id = 0;
        }

        printf("Do you want to backup another file? (y/n): ");
        char choice;
        scanf("%s", &choice);

        if(choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("Thank you for using the Unique C File Backup System!\n");

    return 0;
}