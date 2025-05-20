//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a backup of the specified file
void create_backup(const char *filename) {
    // Check if the file exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File %s not found.\n", filename);
        return;
    }

    // Get the current time
    time_t now = time(NULL);

    // Create a backup file name
    char backup_filename[100];
    sprintf(backup_filename, "%s.%ld.bak", filename, now);

    // Open the backup file for writing
    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Could not create backup file %s.\n", backup_filename);
        fclose(file);
        return;
    }

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        fputs(buffer, backup_file);
    }

    // Close both files
    fclose(file);
    fclose(backup_file);

    // Print a success message
    printf("Backup of file %s created successfully as %s.\n", filename, backup_filename);
}

int main() {
    // Ask the user for the file to back up
    char filename[100];
    printf("Enter the name of the file to back up: ");
    scanf("%s", filename);

    // Create a backup of the file
    create_backup(filename);

    return EXIT_SUCCESS;
}