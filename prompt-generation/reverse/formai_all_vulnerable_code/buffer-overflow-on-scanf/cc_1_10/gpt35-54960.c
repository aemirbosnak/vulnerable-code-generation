//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1024*1024
 
// Function to check if file exists
int doesFileExist(char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}
 
// Function to create backup of a file
void createBackup(char *filename) {
    char backupFilename[MAX_FILENAME_LENGTH+5];
    strcpy(backupFilename, filename);
    strcat(backupFilename, ".bak");
    if(doesFileExist(backupFilename)) {
        remove(backupFilename);
    }
    rename(filename, backupFilename);
}
 
int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    if(!doesFileExist(filename)) {
        printf("Error: %s does not exist\n", filename);
        return 1;
    }
    if(fopen(filename, "r") == NULL) {
        printf("Error: unable to open %s for reading\n", filename);
        return 1;
    }
    char *fileData = (char*) malloc(sizeof(char) * MAX_FILE_SIZE);
    FILE *fp;
    fp = fopen(filename, "r");
    fseek(fp, 0L, SEEK_END);
    long int fileSize = ftell(fp);
    rewind(fp);
    fread(fileData, sizeof(char), fileSize, fp);
    fclose(fp);
    createBackup(filename);
    char choice;
    printf("Do you want to rename the original file (y/n)? ");
    scanf("%c", &choice);
    getchar();
    if(choice == 'y' || choice == 'Y') {
        char newFilename[MAX_FILENAME_LENGTH];
        printf("Enter new filename: ");
        scanf("%s", newFilename);
        fp = fopen(newFilename, "w");
        fwrite(fileData, sizeof(char), fileSize, fp);
        fclose(fp);
        printf("File backed up and renamed successfully\n");
    }
    else {
        fp = fopen(filename, "w");
        fwrite(fileData, sizeof(char), fileSize, fp);
        fclose(fp);
        printf("File backed up successfully\n");
    }
    free(fileData);
    return 0;
}