//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert file size from bytes to human-readable format
char* formatSizeUnits(double fileSize) {
    static char formattedSize[10];
    if (fileSize >= 1024 * 1024 * 1024) {
        sprintf(formattedSize, "%.2lf GB", fileSize / (1024 * 1024 * 1024));
    } else if (fileSize >= 1024 * 1024) {
        sprintf(formattedSize, "%.2lf MB", fileSize / (1024 * 1024));
    } else if (fileSize >= 1024) {
        sprintf(formattedSize, "%.2lf KB", fileSize / 1024);
    } else {
        sprintf(formattedSize, "%.2lf bytes", fileSize);
    }
    return formattedSize;
}

int main() {
    char command[100], fileName[100], fileExtension[10], filePath[100];
    int option;
    double fileSize;
    
    // infinite loop until user enters '5' to exit
    while (1) {
        printf("\n--------------- C System Administration ----------------\n");
        printf("\n1. List current directory\n");
        printf("2. Create a file\n");
        printf("3. Create a directory\n");
        printf("4. Get file information\n");
        printf("5. Exit\n");
        printf("\nEnter an option (1-5): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("\nCurrent directory:\n");
                system("ls -l");
                break;
            case 2:
                printf("\nEnter file name: ");
                scanf("%s", fileName);
                printf("Enter file extension: ");
                scanf("%s", fileExtension);
                sprintf(filePath, "%s.%s", fileName, fileExtension);
                FILE *fp = fopen(filePath, "w");
                if (fp == NULL) {
                    printf("\nError creating file!\n");
                } else {
                    printf("\nFile '%s' created successfully!\n", filePath);
                    fclose(fp);
                }
                break;
            case 3:
                printf("\nEnter directory name: ");
                scanf("%s", fileName);
                if (mkdir(fileName) == -1) {
                    printf("\nError creating directory '%s'!\n", fileName);
                } else {
                    printf("\nDirectory '%s' created successfully!\n", fileName);
                }
                break;
            case 4:
                printf("\nEnter file name: ");
                scanf("%s", fileName);
                FILE *fp2 = fopen(fileName, "r");
                if (fp2 == NULL) {
                    printf("\nFile '%s' does not exist.\n", fileName);
                } else {
                    fseek(fp2, 0L, SEEK_END);
                    fileSize = ftell(fp2);
                    printf("\nInformation for file '%s':\n", fileName);
                    printf("Size: %s\n", formatSizeUnits(fileSize));
                    fclose(fp2);
                }
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid option! Please enter an option between 1-5.\n");
                break;
        }
    }
    return 0;
}