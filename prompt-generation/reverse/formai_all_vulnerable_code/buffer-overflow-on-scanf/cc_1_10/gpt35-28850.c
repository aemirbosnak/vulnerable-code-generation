//FormAI DATASET v1.0 Category: File Backup System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PATH_LENGTH 1024
#define MAX_DATA_LENGTH 1024

// Function for creating a backup file
void createBackup(char* filePath);

// Function for restoring a backup file
void restoreBackup(char* filePath);

int main()
{
    char filePath[MAX_PATH_LENGTH];
    
    printf("Enter the file path: ");
    scanf("%s", filePath);
    
    printf("Menu:\n");
    printf("1. Create Backup\n");
    printf("2. Restore Backup\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            createBackup(filePath);
            break;
        case 2:
            restoreBackup(filePath);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

void createBackup(char* filePath)
{
    // Open the file
    FILE* fp = fopen(filePath, "r");
    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }
    
    // Create the backup file
    char backupFilePath[MAX_PATH_LENGTH];
    strcpy(backupFilePath, filePath);
    strcat(backupFilePath, ".bak");
    FILE* backupfp = fopen(backupFilePath, "w");
    if(backupfp == NULL)
    {
        printf("Unable to create backup file!\n");
        fclose(fp);
        return;
    }
    
    // Copy the contents from the original file to the backup file
    char data[MAX_DATA_LENGTH];
    while(fgets(data, MAX_DATA_LENGTH, fp) != NULL)
    {
        fputs(data, backupfp);
    }
    
    // Close the files
    fclose(fp);
    fclose(backupfp);
    
    printf("Backup created successfully!\n");
}

void restoreBackup(char* filePath)
{
    // Open the backup file
    char backupFilePath[MAX_PATH_LENGTH];
    strcpy(backupFilePath, filePath);
    strcat(backupFilePath, ".bak");
    
    FILE* backupfp = fopen(backupFilePath, "r");
    if(backupfp == NULL)
    {
        printf("Backup file does not exist!\n");
        return;
    }
    
    // Create the original file
    FILE* fp = fopen(filePath, "w");
    if(fp == NULL)
    {
        printf("Unable to create original file!\n");
        fclose(backupfp);
        return;
    }
    
    // Copy the contents from the backup file to the original file
    char data[MAX_DATA_LENGTH];
    while(fgets(data, MAX_DATA_LENGTH, backupfp) != NULL)
    {
        fputs(data, fp);
    }
    
    // Close the files
    fclose(fp);
    fclose(backupfp);
    
    printf("Backup restored successfully!\n");
}