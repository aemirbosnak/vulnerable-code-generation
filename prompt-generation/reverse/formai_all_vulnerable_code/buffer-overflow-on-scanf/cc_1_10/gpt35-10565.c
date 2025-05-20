//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function prototypes
void backupFile(char* filePath, char* backupFolder);

int main() {
    char filePath[100];
    char backupFolder[100];
    char choice;

    printf("Welcome to the backup system! Please enter the path of the file you wish to backup:\n");
    scanf("%s", filePath);

    printf("Please enter the path of the folder where you wish to store the backup:\n");
    scanf("%s", backupFolder);

    //call backupFile function to create backup
    backupFile(filePath, backupFolder);

    printf("\nBackup created successfully!\n");

    printf("\nWould you like to view the contents of the backup folder? (Y/N)\n");
    scanf("%s", &choice);

    if (choice == 'Y' || choice == 'y') {
        char command[100] = "";
        strcat(command, "ls ");
        strcat(command, backupFolder);
        printf("\nBackup folder contents:\n");
        system(command);
    }

    return 0;
}

void backupFile(char* filePath, char* backupFolder) {
    FILE *file;
    FILE *backupFile;
    char backupFilePath[100] = "";
    char timestr[20];
    time_t now = time(NULL);
    strftime(timestr, 20, "%Y%m%d%H%M%S", localtime(&now));
    strcat(backupFilePath, backupFolder);
    strcat(backupFilePath, "/");
    strcat(backupFilePath, "backup_");
    strcat(backupFilePath, timestr);
    strcat(backupFilePath, ".txt");

    //open original file and create backup file
    file = fopen(filePath, "r");
    backupFile = fopen(backupFilePath, "w+");

    //check if files were opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    } else if (backupFile == NULL) {
        printf("Error: Unable to create backup file.\n");
        exit(1);
    }

    //read from the original file and write to the backup file
    char buffer[1000];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, n, backupFile);
    }

    //close both files
    fclose(file);
    fclose(backupFile);
}