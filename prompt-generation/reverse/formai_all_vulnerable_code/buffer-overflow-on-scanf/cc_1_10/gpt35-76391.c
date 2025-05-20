//FormAI DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function declarations */
void analyzeLog(char *filename);

int main()
{
    char filename[100];

    /* get filename from user */
    printf("Welcome to the Kingdom of Logs!\n");
    printf("Please enter the name of the log file you would like to analyze: ");
    scanf("%s", filename);

    analyzeLog(filename);

    /* exit program */
    printf("\nThank you for visiting the Kingdom of Logs!\n");
    return 0;
}

/*
 * analyzeLog - function to analyze a given log file
 * @filename: the name of the log file to analyze
 */
void analyzeLog(char *filename)
{
    FILE *filePointer;
    char line[100];
    int numEntries = 0, numErrors = 0, numWarnings = 0, numInfo = 0;

    /* open file and ensure it exists */
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Oops! The log file you entered could not be found. Please try again.\n");
        exit(1);
    }

    /* read file line by line */
    while (fgets(line, sizeof(line), filePointer)) {
        numEntries++;

        /* check for errors */
        if (strstr(line, "ERROR")) {
            numErrors++;
        }

        /* check for warnings */
        else if (strstr(line, "WARNING")) {
            numWarnings++;
        }

        /* check for info messages */
        else if (strstr(line, "INFO")) {
            numInfo++;
        }
    }

    /* print summary of log file */
    printf("\nHear ye, hear ye! The log file \"%s\" has been analyzed.\n", filename);
    printf("It contains %d total entries.\n", numEntries);

    /* check if any errors were found */
    if (numErrors > 0) {
        printf("There are %d ERRORS in the log file! Take heed, lest thy code be flimsy.\n", numErrors);
    } else {
        printf("There are no ERRORS in the log file. Well done, coding knights!\n");
    }

    /* check if any warnings were found */
    if (numWarnings > 0) {
        printf("There are %d WARNINGS in the log file. Be wary of the upcoming forewarnings.\n", numWarnings);
    } else {
        printf("There are no WARNINGS in the log file. Keep up the good work, code knights!\n");
    }

    /* check if any info messages were found */
    if (numInfo > 0) {
        printf("There are %d INFO messages in the log file. Your code be curious, sire.\n", numInfo);
    } else {
        printf("There are no INFO messages in the log file. Your code be shrouded in mystery...\n");
    }

    /* close file */
    fclose(filePointer);
}