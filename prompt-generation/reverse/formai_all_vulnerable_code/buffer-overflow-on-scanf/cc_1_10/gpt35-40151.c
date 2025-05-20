//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void backupFile(char *filename);
void displayMenu();

int main() {
    char choice;
    char filename[100];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter filename to backup: ");
                scanf("%s", &filename);
                backupFile(filename);
                printf("File %s has been backed up successfully!\n", filename);
                break;
            case '2':
                printf("Program terminated.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '2');

    return 0;
}

/* Function to backup a file */
void backupFile(char *filename) {
    FILE *fp, *copyfp;
    char backupName[100];
    char buffer[1000];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    /* Create backup file with current date and time appended to filename */
    sprintf(backupName, "%s - %04d-%02d-%02d-%02d:%02d:%02d.bak", filename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    /* Open the original file for reading */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s for reading.\n", filename);
        return;
    }

    /* Open the backup file for writing */
    copyfp = fopen(backupName, "w");
    if (copyfp == NULL) {
        printf("Failed to create backup file %s.\n", backupName);
        fclose(fp);
        return;
    }

    /* Copy contents of original file to backup file */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fputs(buffer, copyfp);
    }

    /* Close open files */
    fclose(fp);
    fclose(copyfp);
}

/* Function to display menu */
void displayMenu() {
    printf("C File Backup System\n");
    printf("--------------------\n");
    printf("1. Backup a file\n");
    printf("2. Exit\n");
}