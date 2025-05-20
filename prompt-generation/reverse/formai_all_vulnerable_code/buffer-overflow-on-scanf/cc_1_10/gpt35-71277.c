//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1024

// Function to generate a random integer between 1 and 5 (inclusive)
int getRandomNumber() {
    srand(time(NULL));
    return (rand() % 5) + 1;
}

// Function to simulate the medieval backup system
void medievalBackupSystem(char *fileName) {
    char backupFileName[MAX_FILE_NAME];
    int backupCount = 1;
    FILE *file, *backupFile;

    // Create a new backup file with the backup count appended to the file name
    snprintf(backupFileName, MAX_FILE_NAME, "%s.%d", fileName, backupCount);
    backupFile = fopen(backupFileName, "w");

    // Check if the backup file was created successfully
    if (!backupFile) {
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }

    // Open the original file in read-only mode
    file = fopen(fileName, "r");

    // Check if the original file was opened successfully
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the contents of the original file one byte at a time
    int c = fgetc(file);
    while (c != EOF) {
        // Write the byte to the backup file
        fputc(c, backupFile);

        // With a probability of 20%, introduce errors in the backup file
        int randomNumber = getRandomNumber();
        if (randomNumber == 1) {
            int errorPosition = ftell(backupFile);
            fseek(backupFile, errorPosition - 1, SEEK_SET);
            fputc(getRandomNumber(), backupFile);
            fseek(backupFile, errorPosition, SEEK_SET);
        }

        // Read the next byte from the original file
        c = fgetc(file);

        // If the backup file size exceeds 1KB, create a new backup file
        if (ftell(backupFile) >= MAX_FILE_SIZE) {
            fclose(backupFile);
            backupCount++;
            snprintf(backupFileName, MAX_FILE_NAME, "%s.%d", fileName, backupCount);
            backupFile = fopen(backupFileName, "w");
            if (!backupFile) {
                perror("Error creating backup file");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Close the original file and the last backup file
    fclose(file);
    fclose(backupFile);

    printf("Backup of %s completed successfully\n", fileName);
}

int main() {
    char fileName[MAX_FILE_NAME];
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", fileName);
    medievalBackupSystem(fileName);
    return 0;
}