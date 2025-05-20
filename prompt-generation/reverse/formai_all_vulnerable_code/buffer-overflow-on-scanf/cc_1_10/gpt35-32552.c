//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

void backup(char* filename);
void restore(char* filename);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    int choice;

    printf("Welcome to the C File Backup System\n");
    printf("Please choose an option:\n");
    printf("1 - Backup a file\n");
    printf("2 - Restore a file\n");
    printf("3 - Quit\n");

    do {
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter filename to backup: ");
                scanf("%s", filename);
                backup(filename);
                break;
            case 2:
                printf("Enter filename to restore: ");
                scanf("%s", filename);
                restore(filename);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while(choice != 3);

    return 0;
}

void backup(char* filename) {
    printf("Backing up file %s...\n", filename);

    // Open original file for reading
    FILE* original = fopen(filename, "r");
    if(original == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Create backup filename
    char backup_filename[MAX_FILENAME_LENGTH + 4];
    sprintf(backup_filename, "%s.bak", filename);

    // Open backup file for writing
    FILE* backup = fopen(backup_filename, "w");
    if(backup == NULL) {
        printf("Error: Unable to create backup file %s\n", backup_filename);
        fclose(original);
        return;
    }

    // Copy original file to backup file
    int c;
    while((c = getc(original)) != EOF) {
        putc(c, backup);
    }

    printf("Backup complete!\n");

    // Close files
    fclose(original);
    fclose(backup);
}

void restore(char* filename) {
    printf("Restoring file %s...\n", filename);

    // Create backup filename
    char backup_filename[MAX_FILENAME_LENGTH + 4];
    sprintf(backup_filename, "%s.bak", filename);

    // Open backup file for reading
    FILE* backup = fopen(backup_filename, "r");
    if(backup == NULL) {
        printf("Error: Unable to open backup file %s\n", backup_filename);
        return;
    }

    // Open original file for writing
    FILE* original = fopen(filename, "w");
    if(original == NULL) {
        printf("Error: Unable to create file %s\n", filename);
        fclose(backup);
        return;
    }

    // Copy backup file to original file
    int c;
    while((c = getc(backup)) != EOF) {
        putc(c, original);
    }

    printf("Restore complete!\n");

    // Close files
    fclose(backup);
    fclose(original);
}