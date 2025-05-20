//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20

typedef struct {
    char name[MAX_FILE_NAME];
    char *content;
} file;

file files[MAX_FILES];

int num_files = 0;

/**
 * Function to backup a file to the backup directory.
 */
void backup_file(char *filename) {
    char backup_filename[MAX_FILE_NAME + 8];   // +8 because "_backup" plus null terminator
    
    // Copy the original filename to the backup filename
    strcpy(backup_filename, filename);
    
    // Add the "_backup" suffix to the backup filename
    strcat(backup_filename, "_backup");
    
    // Open the original file for reading
    FILE *original_file = fopen(filename, "r");
    if (original_file == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", filename);
        return;
    }
    
    // Open the backup file for writing
    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", backup_filename);
        fclose(original_file);
        return;
    }
    
    // Copy the contents of the original file to the backup file
    int c;
    while ((c = fgetc(original_file)) != EOF) {
        fputc(c, backup_file);
    }
    
    // Close the files
    fclose(original_file);
    fclose(backup_file);
    
    printf("File '%s' backed up to '%s'\n", filename, backup_filename);
}

/**
 * Function to add a file to the backup system.
 */
void add_file() {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files exceeded (%d).\n", MAX_FILES);
        return;
    }
    
    char filename[MAX_FILE_NAME];
    printf("Enter filename: ");
    scanf("%s", filename);
    
    // Check if the file already exists
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("Error: File '%s' already exists.\n", filename);
            return;
        }
    }
    
    // Open the file for reading
    FILE *file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", filename);
        return;
    }
    
    // Get the size of the file
    fseek(file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    rewind(file_pointer);
    
    // Allocate memory for the file contents
    char *file_contents = (char *) malloc(file_size);
    if (file_contents == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file_pointer);
        return;
    }
    
    // Read the file contents into memory
    int num_read = fread(file_contents, 1, file_size, file_pointer);
    if (num_read != file_size) {
        printf("Error: Could not read file contents.\n");
        fclose(file_pointer);
        free(file_contents);
        return;
    }
    
    // Close the file
    fclose(file_pointer);
    
    // Add the file to the files array
    strcpy(files[num_files].name, filename);
    files[num_files].content = file_contents;
    num_files++;
    
    printf("File '%s' added to backup system.\n", filename);
}

/**
 * Function to list all files in the backup system.
 */
void list_files() {
    printf("Backup System Files:\n");
    int i;
    for (i = 0; i < num_files; i++) {
        printf(" - %s\n", files[i].name);
    }
}

int main() {
    int choice;
    do {
        printf("\nBackup System\n");
        printf("1. Add file\n");
        printf("2. List files\n");
        printf("3. Backup file\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_file();
                break;
            case 2:
                list_files();
                break;
            case 3: {
                char filename[MAX_FILE_NAME];
                printf("Enter filename to backup: ");
                scanf("%s", filename);
                
                // Check if the file exists
                int i;
                for (i = 0; i < num_files; i++) {
                    if (strcmp(files[i].name, filename) == 0) {
                        // Backup the file
                        backup_file(filename);
                        break;
                    }
                }
                
                if (i >= num_files) {
                    printf("Error: File '%s' not found.\n", filename);
                }
                
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 4);
    
    // Free memory allocated for file contents
    int i;
    for (i = 0; i < num_files; i++) {
        free(files[i].content);
    }
    
    return 0;
}