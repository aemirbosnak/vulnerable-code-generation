//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to backup file
void backup_file(char *filename) {
    FILE *file_in, *file_out;
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Error opening file %s for reading\n", filename);
        exit(1);
    }
    file_out = fopen(backup_filename, "w");
    if (file_out == NULL) {
        printf("Error opening file %s for writing\n", backup_filename);
        exit(1);
    }
    while (fgets(filename, 100, file_in)!= NULL) {
        fputs(filename, file_out);
    }
    fclose(file_in);
    fclose(file_out);
    printf("Backup of %s created successfully\n", filename);
}

// Function to restore file
void restore_file(char *filename) {
    FILE *file_in, *file_out;
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Error opening file %s for reading\n", filename);
        exit(1);
    }
    file_out = fopen(backup_filename, "r");
    if (file_out == NULL) {
        printf("Error opening file %s for reading\n", backup_filename);
        exit(1);
    }
    while (fgets(filename, 100, file_in)!= NULL) {
        fputs(filename, file_out);
    }
    fclose(file_in);
    fclose(file_out);
    printf("Restore of %s completed successfully\n", filename);
}

// Function to delete backup file
void delete_backup_file(char *filename) {
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    remove(backup_filename);
    printf("Backup file %s deleted successfully\n", backup_filename);
}

int main() {
    char filename[100], choice;
    do {
        printf("Enter filename: ");
        scanf("%s", filename);
        printf("Enter your choice:\n1. Backup file\n2. Restore file\n3. Delete backup file\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                backup_file(filename);
                break;
            case '2':
                restore_file(filename);
                break;
            case '3':
                delete_backup_file(filename);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}