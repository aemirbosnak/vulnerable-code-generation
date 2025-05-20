//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to create backup file
void backup(char *source_file, char *backup_file)
{
    FILE *source_ptr, *backup_ptr;
    char buffer[MAX_SIZE];

    // Open source file for reading
    source_ptr = fopen(source_file, "r");

    if (source_ptr == NULL) {
        printf("Error: Unable to open file %s.\n", source_file);
        exit(1);
    }

    // Open backup file for writing
    backup_ptr = fopen(backup_file, "w");

    if (backup_ptr == NULL) {
        printf("Error: Unable to open file %s.\n", backup_file);
        exit(1);
    }

    // Copy content of source file to backup file
    while (fgets(buffer, MAX_SIZE, source_ptr)) {
        fputs(buffer, backup_ptr);
    }

    // Close files
    fclose(source_ptr);
    fclose(backup_ptr);

    printf("Backup created for file %s.\n", source_file);
}

// Main function
int main()
{
    char source_file[MAX_SIZE], backup_file[MAX_SIZE];

    printf("Enter name of the file to backup: ");
    scanf("%s", source_file);

    // Check if file exists
    FILE *file = fopen(source_file, "r");
    if (file == NULL) {
        printf("Unable to open file %s.\n", source_file);
        exit(1);
    }
    fclose(file);

    // Create backup file
    strcpy(backup_file, source_file);
    strcat(backup_file, ".bak");
    backup(source_file, backup_file);

    return 0;
}