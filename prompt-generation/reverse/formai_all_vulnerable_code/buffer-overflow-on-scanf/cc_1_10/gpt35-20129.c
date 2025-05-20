//FormAI DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

// Function to read the file content into the buffer
char* read_file_content(char* filename) {
    FILE *fp = fopen(filename, "r");
    char *fileContent = (char*) malloc(sizeof(char) * MAXLEN);
    if(fp != NULL){
        size_t newLen = fread(fileContent, sizeof(char), MAXLEN, fp);
        if ( ferror( fp ) != 0 ) {
            fputs("Error reading file", stderr);
        } else {
            fileContent[newLen++] = '\0';
        }
        fclose(fp);
    }
    return fileContent;
}

// Function to backup the given file
void backup_file(char* filename) {
    char* fileContent = read_file_content(filename);

    // Creating backup file name
    char backupFile[MAXLEN];
    strcpy(backupFile, filename);
    strcat(backupFile, ".back");

    // Writing content to backup file
    FILE* backupFilePtr = fopen(backupFile, "w");
    if(backupFilePtr != NULL){
        fputs(fileContent, backupFilePtr);
        fclose(backupFilePtr);
        printf("File %s backed up successfully!\n", filename);
    } else {
        printf("Error creating backup file for %s!\n", filename);
    }
}

int main() {
    printf("Sherlock Holmes: The C File Backup System\n\n");

    // Reading the file name
    char filename[MAXLEN];
    printf("Enter the file name to backup: ");
    scanf("%s", filename);

    // Backing up the file
    backup_file(filename);

    return 0;
}