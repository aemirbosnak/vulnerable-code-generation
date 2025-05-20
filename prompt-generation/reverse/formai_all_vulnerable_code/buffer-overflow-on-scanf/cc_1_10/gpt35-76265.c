//FormAI DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void print_menu() {
    printf("\n\nWelcome to the C File Backup System!\n");
    printf("Please select an option below:\n");
    printf("1. Create a backup\n");
    printf("2. Restore a backup\n");
    printf("3. View all backups\n");
    printf("4. Exit\n");
}

void create_backup() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Please enter the filename (including extension) of the file you wish to backup: ");
    scanf("%s", filename);
    
    FILE *original_file = fopen(filename, "r");
    if(original_file == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        return;
    }
    
    char backup_filename[MAX_FILENAME_LENGTH + 4];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    
    FILE *backup_file = fopen(backup_filename, "w");
    if(backup_file == NULL) {
        printf("Error: could not open file '%s' for writing.\n", backup_filename);
        fclose(original_file);
        return;
    }
    
    char buffer[1024];
    size_t read;
    while((read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, read, 1, backup_file);
    }
    
    printf("Backup created successfully!\n");
    
    fclose(original_file);
    fclose(backup_file);
}

void restore_backup() {
    char backup_filename[MAX_FILENAME_LENGTH];
    printf("Please enter the filename (including extension) of the backup you wish to restore: ");
    scanf("%s", backup_filename);
    
    char filename[MAX_FILENAME_LENGTH];
    char *extension = strchr(backup_filename, '.');
    if(extension == NULL || strcmp(extension, ".bak") != 0) {
        printf("Error: '%s' is not a valid backup filename.\n", backup_filename);
        return;
    }
    strncpy(filename, backup_filename, extension - backup_filename);
    filename[extension - backup_filename] = '\0';
    
    FILE *backup_file = fopen(backup_filename, "r");
    if(backup_file == NULL) {
        printf("Error: could not open file '%s' for reading.\n", backup_filename);
        return;
    }
    
    FILE *original_file = fopen(filename, "w");
    if(original_file == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        fclose(backup_file);
        return;
    }
    
    char buffer[1024];
    size_t read;
    while((read = fread(buffer, 1, sizeof(buffer), backup_file)) > 0) {
        fwrite(buffer, read, 1, original_file);
    }
    
    printf("Backup restored successfully!\n");
    
    fclose(original_file);
    fclose(backup_file);
}

void view_backups() {
    printf("Filename\t\tDate Created\n");
    printf("----------------------------------------\n");
    
    system("ls -l *.bak | awk '{print $9 \"\t\t\" $6 \" \" $7 \", \" $8}'");
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_backup();
                break;
            case 2:
                restore_backup();
                break;
            case 3:
                view_backups();
                break;
            case 4:
                printf("Thanks for using the C File Backup System!\n");
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}