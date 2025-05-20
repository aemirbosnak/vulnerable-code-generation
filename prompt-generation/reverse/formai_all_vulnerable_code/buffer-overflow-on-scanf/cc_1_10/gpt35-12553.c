//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
    char filename[20], temp[20], choice;
    int backup_num = 0;

    printf("\nWelcome to the C File Backup System!\n\n");

    // Getting filename from user
    printf("Enter the filename to backup: ");
    scanf("%s", filename);

    // Adding '.bak' extension to filename
    strcat(filename, ".bak");

    // Checking if backup already exists
    FILE *check_file = fopen(filename, "r");

    if (check_file) {
        // If backup exists, ask user if they want to overwrite it
        printf("\nA backup of this file already exists. Do you want to overwrite it? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            // If user chooses not to overwrite, exit program
            printf("\nBackup operation cancelled. Exiting program.\n");
            return 0;
        }
        // If user chooses to overwrite, proceed with backup operation
        printf("\nOverwriting existing backup file.\n");
        fclose(check_file);
    }

    // Opening original file for reading
    FILE *original_file = fopen(temp, "r");

    if (!original_file) {
        printf("\nUnable to open file. Backup operation cancelled. Exiting program.\n");
        return 0;
    }

    // Creating backup filename with number suffix
    do {
        ++backup_num;
        sprintf(temp, "%s%d", filename, backup_num);
    } while (fopen(temp, "r"));

    // Copying contents of original file to backup file
    FILE *backup_file = fopen(temp, "w");
    char c;

    while ((c = getc(original_file)) != EOF) {
        putc(c, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("\nBackup successful! Filename: %s\n", temp);

    return 0;
}