//FormAI DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20

// struct to store file information
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[100];
} File;

int main() {
    // create an array to store files
    File files[MAX_FILES];
    int num_files = 0;

    // user menu
    int choice;
    do {
        printf("\nFile Backup System Menu:\n");
        printf("1. Add a file\n");
        printf("2. List all files\n");
        printf("3. Backup all files to backup.txt\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // perform action based on user choice
        switch (choice) {
            case 1: // add a file
                if (num_files == MAX_FILES) {
                    printf("Maximum number of files reached.\n");
                } else {
                    printf("\nEnter file name: ");
                    scanf("%s", files[num_files].filename);
                    printf("Enter file data: ");
                    scanf("%s", files[num_files].data);

                    num_files++;
                    printf("File added successfully.\n");
                }
                break;

            case 2: // list all files
                if (num_files == 0) {
                    printf("No files added yet.\n");
                } else {
                    printf("\nList of files:\n");
                    for (int i = 0; i < num_files; i++) {
                        printf("%s\n", files[i].filename);
                    }
                }
                break;

            case 3: // backup all files to backup.txt
                if (num_files == 0) {
                    printf("No files added yet.\n");
                } else {
                    FILE* backup_file = fopen("backup.txt", "w");
                    if (backup_file == NULL) {
                        printf("Error opening backup file.\n");
                    } else {
                        for (int i = 0; i < num_files; i++) {
                            fprintf(backup_file, "%s, %s\n", files[i].filename, files[i].data);
                        }
                        fclose(backup_file);

                        printf("Files backed up successfully.\n");
                    }
                }
                break;

            case 4: // exit program
                printf("Program terminated.\n");
                break;

            default: // invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}