//FormAI DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_SIZE 1048576 //1 MB in bytes
#define MAX_BACKUPS 10

//Global variables
char filename[MAX_FILENAME_LEN];
int numBackups = 0;

//Function prototypes
void createBackup(char *filename);
void printFileContents(char *filename);

int main()
{
    //Random number generator initialization
    srand(time(NULL));

    //Get filename from user
    printf("Enter the filename to backup (max length %d characters): ", MAX_FILENAME_LEN);
    scanf("%s", filename);

    //Create initial backup if file exists
    createBackup(filename);

    //Main program loop
    int option;
    do {
        printf("\n1. Create backup\n2. Print file contents\n3. Quit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createBackup(filename);
                break;
            case 2:
                printFileContents(filename);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 3);

    return 0;
}

//Creates a backup of the specified file
void createBackup(char *filename)
{
    //Open file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    //Generate backup filename (add random number at end)
    char backupFilename[MAX_FILENAME_LEN];
    snprintf(backupFilename, MAX_FILENAME_LEN, "%s.%d", filename, rand()%1000);

    //Open backup file for writing
    FILE *backup = fopen(backupFilename, "w");
    if (backup == NULL) {
        printf("Failed to create backup file %s\n", backupFilename);
        fclose(fp);
        return;
    }

    //Copy contents of original file to backup file
    char buffer[MAX_FILE_SIZE];
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, fp)) > 0) {
        fwrite(buffer, 1, bytesRead, backup);
    }

    //Close files
    fclose(fp);
    fclose(backup);

    printf("Backup of %s created successfully (as %s)\n", filename, backupFilename);

    //Update number of backups
    numBackups++;

    //Remove oldest backup if limit reached
    if (numBackups > MAX_BACKUPS) {
        char oldestBackup[MAX_FILENAME_LEN];
        snprintf(oldestBackup, MAX_FILENAME_LEN, "%s.%d", filename, numBackups-MAX_BACKUPS);
        remove(oldestBackup);
        printf("Oldest backup (%s) deleted.\n", oldestBackup);
    }
}

//Prints the contents of the specified file
void printFileContents(char *filename)
{
    //Open file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    //Print contents of file to screen
    printf("Contents of %s:\n", filename);
    char buffer[MAX_FILE_SIZE];
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, fp)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout);
    }

    //Close file
    fclose(fp);
}