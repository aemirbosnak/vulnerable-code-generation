//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BACKUP_FILES 10
#define MAX_FILENAME_LENGTH 50

/* Function to backup a file */
void backup_file(char *filename) {
    char backup_filename[MAX_FILENAME_LENGTH];
    char backup_extension[] = ".bak";
    FILE *fp, *fp_backup;
    int c;

    /* Create the backup filename by appending the extension to the original filename */
    strcpy(backup_filename, filename);
    strcat(backup_filename, backup_extension);

    /* Open the original file for reading and the backup file for writing */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open %s for reading.\n", filename);
        return;
    }
    fp_backup = fopen(backup_filename, "w");
    if (fp_backup == NULL) {
        printf("Error: Could not create backup file %s.\n", backup_filename);
        fclose(fp);
        return;
    }

    /* Copy the contents of the original file to the backup file */
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, fp_backup);
    }

    /* Close both files */
    fclose(fp);
    fclose(fp_backup);

    printf("Backup of %s created as %s.\n", filename, backup_filename);
}

/* Function to display the list of backup files */
void list_backup_files(char **backup_files, int num_files) {
    int i;

    printf("List of Backup Files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s\n", backup_files[i]);
    }
}

/* Main function */
int main() {
    char filename[MAX_FILENAME_LENGTH];
    char **backup_files;
    int num_files = 0;
    int choice;

    /* Allocate memory for the backup_files array */
    backup_files = (char **)malloc(MAX_BACKUP_FILES * sizeof(char *));
    if (backup_files == NULL) {
        printf("Error: Could not allocate memory for backup files array.\n");
        return 1;
    }

    while (1) {
        printf("\nFile Backup System Menu:\n");
        printf("1. Backup a File\n");
        printf("2. List Backup Files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to backup: ");
                scanf("%s", filename);

                /* Check if the file has already been backed up */
                if (num_files >= MAX_BACKUP_FILES) {
                    printf("Error: Maximum number of backup files reached.\n");
                } else {
                    backup_file(filename);
                    /* Add the backup filename to the backup_files array */
                    backup_files[num_files] = (char *)malloc((strlen(filename) + 4) * sizeof(char));
                    if (backup_files[num_files] == NULL) {
                        printf("Error: Could not allocate memory for backup filename.\n");
                    } else {
                        strcpy(backup_files[num_files], filename);
                        strcat(backup_files[num_files], ".bak");
                        num_files++;
                    }
                }
                break;
            case 2:
                list_backup_files(backup_files, num_files);
                break;
            case 3:
                printf("Goodbye!\n");
                /* Free the memory allocated for backup_files array */
                for (int i = 0; i < num_files; i++) {
                    free(backup_files[i]);
                }
                free(backup_files);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}