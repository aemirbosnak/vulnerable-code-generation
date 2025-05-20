//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXFILES 100
#define MAXLEN 1000

static char *filenames[MAXFILES];
static char *filedates[MAXFILES];
static int filecounts[MAXFILES];
static FILE *files[MAXFILES];

// Knuthian file backup system
void backup(void)
{
    // Open the file to be backed up
    char filename[MAXLEN];
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[MAXLEN];
    strftime(date, MAXLEN, "%Y-%m-%d %H:%M:%S", tm);

    // Find a free slot in the file table
    int i;
    for (i = 0; i < MAXFILES && filenames[i] != NULL; i++)
        ;
    if (i == MAXFILES)
    {
        printf("File table is full\n");
        return;
    }

    // Allocate memory for the filename and date
    filenames[i] = malloc(strlen(filename) + 1);
    filedates[i] = malloc(strlen(date) + 1);

    // Copy the filename and date into the table
    strcpy(filenames[i], filename);
    strcpy(filedates[i], date);

    // Count the number of lines in the file
    int count = 0;
    char line[MAXLEN];
    while (fgets(line, MAXLEN, file) != NULL)
    {
        count++;
    }

    // Store the number of lines in the table
    filecounts[i] = count;

    // Open the backup file
    char backupname[MAXLEN];
    sprintf(backupname, "%s.%s.bak", filename, date);
    FILE *backup = fopen(backupname, "w");
    if (backup == NULL)
    {
        printf("Error opening backup file %s\n", backupname);
        return;
    }

    // Copy the file to the backup file
    rewind(file);
    while (fgets(line, MAXLEN, file) != NULL)
    {
        fputs(line, backup);
    }

    // Close the files
    fclose(file);
    fclose(backup);

    // Print the backup information
    printf("File %s backed up to %s on %s\n", filename, backupname, date);
}

// Knuthian file restore system
void restore(void)
{
    // Get the name of the backup file to be restored
    char backupname[MAXLEN];
    printf("Enter the name of the backup file to be restored: ");
    scanf("%s", backupname);

    // Open the backup file
    FILE *backup = fopen(backupname, "r");
    if (backup == NULL)
    {
        printf("Error opening backup file %s\n", backupname);
        return;
    }

    // Get the original filename and date from the backup file
    char filename[MAXLEN];
    char date[MAXLEN];
    fscanf(backup, "%s %s\n", filename, date);

    // Find the original file in the file table
    int i;
    for (i = 0; i < MAXFILES && filenames[i] != NULL && strcmp(filenames[i], filename) != 0; i++)
        ;
    if (i == MAXFILES)
    {
        printf("Original file %s not found\n", filename);
        return;
    }

    // Open the original file
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Copy the backup file to the original file
    int count = filecounts[i];
    char line[MAXLEN];
    while (count-- > 0)
    {
        fgets(line, MAXLEN, backup);
        fputs(line, file);
    }

    // Close the files
    fclose(file);
    fclose(backup);

    // Print the restore information
    printf("File %s restored from %s on %s\n", filename, backupname, date);
}

// Knuthian file management system
int main(void)
{
    int choice;
    do
    {
        printf("1. Backup a file\n");
        printf("2. Restore a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            backup();
            break;
        case 2:
            restore();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}