//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to backup a file
void backup_file(char *filename) {
    char backup_filename[strlen(filename) + 5]; // Backup filename with ".bak" extension
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // Open the original file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s for reading.\n", filename);
        exit(1);
    }

    // Open the backup file for writing
    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Could not open %s for writing.\n", backup_filename);
        fclose(file);
        exit(1);
    }

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        fputs(buffer, backup_file);
    }

    // Close both files
    fclose(file);
    fclose(backup_file);

    printf("Backup of %s created as %s.\n", filename, backup_filename);
}

// Function to restore a file from a backup
void restore_file(char *filename) {
    char backup_filename[strlen(filename) + 5]; // Backup filename with ".bak" extension
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // Open the backup file for reading
    FILE *backup_file = fopen(backup_filename, "r");
    if (backup_file == NULL) {
        printf("Error: Could not open %s for reading.\n", backup_filename);
        exit(1);
    }

    // Open the original file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open %s for writing.\n", filename);
        fclose(backup_file);
        exit(1);
    }

    // Copy the contents of the backup file to the original file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), backup_file)!= NULL) {
        fputs(buffer, file);
    }

    // Close both files
    fclose(backup_file);
    fclose(file);

    printf("File %s restored from backup %s.\n", filename, backup_filename);
}

int main() {
    char filename[1024];
    printf("Enter the name of the file to backup or restore: ");
    scanf("%s", filename);

    if (strcmp(filename, "backup") == 0) {
        backup_file(filename);
    } else if (strcmp(filename, "restore") == 0) {
        restore_file(filename);
    } else {
        printf("Error: Invalid option selected.\n");
        exit(1);
    }

    return 0;
}