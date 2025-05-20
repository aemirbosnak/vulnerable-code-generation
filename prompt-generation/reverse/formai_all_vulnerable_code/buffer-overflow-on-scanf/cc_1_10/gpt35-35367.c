//FormAI DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the file exists
bool fileExists(char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return true;
    }
    return false;
}

// Function to create a backup file with the specified name
void createBackup(char *fileName) {
    printf("Creating backup for %s...\n", fileName);
    char backupName[256];
    strcpy(backupName, fileName);
    strcat(backupName, ".bak");
    FILE *file1, *file2;
    file1 = fopen(fileName, "r");
    file2 = fopen(backupName, "w");
    char ch;
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file2);
    }
    fclose(file1);
    fclose(file2);
    printf("Backup created successfully!\n");
}

int main() {
    char fileName[256]; // Maximum length of file name is 256 characters
    printf("Enter the file name (with extension): ");
    scanf("%s", fileName);
    if (fileExists(fileName)) {
        printf("File found!\n");
        bool backupExists = fileExists(strcat(fileName, ".bak"));
        if (backupExists) {
            printf("Backup file already exists!\n");
        } else {
            createBackup(fileName);
        }
    } else {
        printf("File not found. Please try again.\n");
    }
    return 0;
}