//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 64
#define MAX_BACKUP_COUNT 10

int main() {
    printf("==============================================\n");
    printf("|      Welcome to the Funny File Backup!      |\n");
    printf("==============================================\n\n");

    char filename[MAX_FILENAME_LEN];
    printf("Enter the name of the file to backup: ");
    gets(filename);

    printf("\nCreating backup file... ");
    char backup_filename[MAX_FILENAME_LEN];
    strcpy(backup_filename, filename);
    strcat(backup_filename, "_backup");
    FILE* backup_file = fopen(backup_filename, "w");
    if(backup_file == NULL) {
        printf(" Uh oh, something went wrong. Try again later :)\n");
        return -1;
    }
    printf("Done!\n");

    printf("Writing data to backup file... ");
    char backup_data[MAX_BACKUP_COUNT][MAX_FILENAME_LEN];
    sprintf(backup_data[0], "The file %s has been backed up.", filename);
    fprintf(backup_file, "%s\n", backup_data[0]);
    printf("Done!\n");

    printf("Making sure it's safe... ");
    fclose(backup_file);
    printf("Yep, all good!\n");

    printf("And now, for your viewing pleasure, the contents of the file...\n");
    printf("===============================================================\n\n");

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Oops, couldn't open the file to read :(\n");
        return -1;
    }

    char line[MAX_FILENAME_LEN];
    while(fgets(line, MAX_FILENAME_LEN, file)) {
        printf("%s", line);
    }
    fclose(file);

    printf("\n\nThanks for using the Funny File Backup! Don't forget to tip your programmer :)\n");

    return 0;
}