//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the File Synchronizer program!\n");
    printf("Two folders will be compared to ensure their files match.\n");
    printf("If a file in Folder 1 is missing in Folder 2, a copy will be made.\n");
    printf("If a file in Folder 2 is missing in Folder 1, it will be deleted from Folder 2.\n");
    printf("Let's get started!\n\n");
    
    // File path inputs
    char folder1[100];
    printf("Enter the path for Folder 1: ");
    scanf("%s", folder1);
    
    char folder2[100];
    printf("Enter the path for Folder 2: ");
    scanf("%s", folder2);
    
    // Access folders and compare files
    FILE *fp1, *fp2;
    char file1[100], file2[100];
    char f1, f2;
    int flag = 0;
    
    fp1 = fopen(folder1, "r");
    fp2 = fopen(folder2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error! Unable to open folders.\n");
        exit(1);
    }
    
    // Compare files in folder 1
    while (fscanf(fp1, "%s", file1) != EOF) {
        f1 = fgetc(fp1);
        rewind(fp2);
        flag = 0;
        
        // Check if file exists in folder 2
        while (fscanf(fp2, "%s", file2) != EOF) {
            f2 = fgetc(fp2);
            if (strcmp(file1, file2) == 0) {
                flag = 1;
                break;
            }
        }
        
        // Copy file from folder 1 to folder 2 if not found
        if (flag == 0) {
            char command[100];
            sprintf(command, "cp %s %s", file1, folder2);
            system(command);
            printf("Added \"%s\" to Folder 2.\n", file1);
        }
    }
    
    // Compare files in folder 2
    rewind(fp1);
    while (fscanf(fp2, "%s", file2) != EOF) {
        f2 = fgetc(fp2);
        rewind(fp1);
        flag = 0;
        
        // Check if file exists in folder 1
        while (fscanf(fp1, "%s", file1) != EOF) {
            f1 = fgetc(fp1);
            if (strcmp(file2, file1) == 0) {
                flag = 1;
                break;
            }
        }
        
        // Delete file from folder 2 if not found in folder 1
        if (flag == 0) {
            char command[100];
            sprintf(command, "rm %s", file2);
            system(command);
            printf("\"%s\" was deleted from Folder 2.\n", file2);
        }
    }
    
    // Closing statements
    printf("\nFile synchronization complete!\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}