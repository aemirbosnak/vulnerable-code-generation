//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void createBackup(const char *sourceFile, const char *backupFile) {
    FILE *srcFile, *destFile;
    char buffer[1024];
    size_t bytesRead;

    // Open the source file in read mode
    srcFile = fopen(sourceFile, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the destination file in write mode
    destFile = fopen(backupFile, "wb");
    if (destFile == NULL) {
        perror("Error opening backup file");
        fclose(srcFile);
        return;
    }

    // Copy the content from source file to destination file
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destFile);
    }

    printf("Backup of '%s' created as '%s'\n", sourceFile, backupFile);

    // Close both files
    fclose(srcFile);
    fclose(destFile);
}

int main() {
    char sourceFile[256];
    char backupFile[256];
    char userInput;

    printf("Welcome to the File Backup System!\n");
    do {
        printf("Enter the path of the source file: ");
        scanf("%s", sourceFile);

        printf("Enter the path of the backup file: ");
        scanf("%s", backupFile);

        createBackup(sourceFile, backupFile);
        
        printf("Do you want to create another backup? (y/n): ");
        scanf(" %c", &userInput);

    } while (userInput == 'y' || userInput == 'Y');

    printf("Exiting the File Backup System. Goodbye!\n");
    return 0;
}