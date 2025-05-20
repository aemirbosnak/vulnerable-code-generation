//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum file name length
#define FILENAME_MAX_LEN 100

// Define the maximum number of files to be backed up
#define MAX_FILES 10

int main()
{
    // Declare the variables to store file names and data
    char fileNames[MAX_FILES][FILENAME_MAX_LEN];
    char backupFileNames[MAX_FILES][FILENAME_MAX_LEN];
    char inputFileName[FILENAME_MAX_LEN];
    char backupFileName[FILENAME_MAX_LEN];
    char data[MAX_FILES][1000];

    // Counter variables for array access and iteration    
    int i, j;

    // Declare the file pointers for input and output files
    FILE *fpIn, *fpOut;

    // Prompt the user to enter the number of files to be backed up
    int numFiles;
    printf("Enter the number of files to be backed up (max %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    // Loop through the files and prompt the user to enter their names
    for (i = 0; i < numFiles; i++)
    {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", inputFileName);

        // Attempt to open the input file for reading
        fpIn = fopen(inputFileName, "r");
        if (fpIn == NULL)
        {
            printf("Error opening file '%s'\n", inputFileName);
            return 1;
        }

        // Read the data from the input file and store it in the data array
        fgets(data[i], 1000, fpIn);

        // Close the input file
        fclose(fpIn);

        // Create the backup file name by appending '.bak' to the input file name
        strcpy(backupFileName, inputFileName);
        strcat(backupFileName, ".bak");

        // Append the file name and backup file name to their respective arrays
        strcpy(fileNames[i], inputFileName);
        strcpy(backupFileNames[i], backupFileName);
    }

    // Loop through the files and create backup files
    for (i = 0; i < numFiles; i++)
    {
        // Attempt to open the backup file for writing
        fpOut = fopen(backupFileNames[i], "w");
        if (fpOut == NULL)
        {
            printf("Error creating backup file '%s'\n", backupFileNames[i]);
            return 1;
        }

        // Write the data to the backup file
        fputs(data[i], fpOut);

        // Close the backup file
        fclose(fpOut);
    }

    // Print a message indicating the backup process is complete
    printf("Backup complete!\n");

    return 0;
}