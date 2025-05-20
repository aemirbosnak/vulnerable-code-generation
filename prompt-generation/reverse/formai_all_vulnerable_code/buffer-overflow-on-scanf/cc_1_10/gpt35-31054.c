//FormAI DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAMES 100 // Maximum number of filenames the program can handle
#define MAX_FILENAME_LENGTH 20 // Maximum length of a single filename

/* Function to backup a file */
void backupFile(char* filename) {
    FILE* original_file = fopen(filename, "r"); // Open the original file in read mode
    if (original_file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    char backup_filename[MAX_FILENAME_LENGTH + 7]; // The backup filename will have "(backup)" appended to it
    strcpy(backup_filename, filename);
    strcat(backup_filename, "(backup)");

    FILE* backup_file = fopen(backup_filename, "w"); // Open the backup file in write mode
    if (backup_file == NULL) {
        printf("Error: Could not create backup file for '%s'\n", filename);
        fclose(original_file); // Close the original file
        return;
    }

    // Read data from the original file and write it to the backup file
    char c = fgetc(original_file);
    while (c != EOF) {
        fputc(c, backup_file);
        c = fgetc(original_file);
    }
    
    printf("Successfully backed up file '%s' to '%s'\n", filename, backup_filename);
    
    fclose(original_file); // Close both files
    fclose(backup_file);
}

int main() {
    char filenames[MAX_FILENAMES][MAX_FILENAME_LENGTH]; // Array to hold filenames
    int num_filenames = 0; // Variable to keep count of how many filenames have been added

    // Ask user for filenames
    while (num_filenames < MAX_FILENAMES) {
        printf("Enter filename (or 'q' to stop): ");
        scanf("%s", filenames[num_filenames]);

        if (strcmp(filenames[num_filenames], "q") == 0) {
            break;
        }

        num_filenames++;
    }

    // Backup each file
    for (int i = 0; i < num_filenames; i++) {
        backupFile(filenames[i]);
    }

    return 0;
}