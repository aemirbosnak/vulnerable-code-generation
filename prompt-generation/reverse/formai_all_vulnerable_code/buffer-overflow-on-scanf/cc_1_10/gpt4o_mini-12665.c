//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function declarations
void displayMenu();
int backupFile(const char *source, const char *destination);
int checkFileExists(const char *filePath);

int main() {
    char sourcePath[256];
    char destinationPath[256];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // clearing newline after scanf

        switch (choice) {
            case 1:
                printf("Enter the source file path: ");
                fgets(sourcePath, sizeof(sourcePath), stdin);
                strtok(sourcePath, "\n");  // Remove newline character

                if (!checkFileExists(sourcePath)) {
                    printf("Source file does not exist.\n");
                    break;
                }

                printf("Enter the destination file path: ");
                fgets(destinationPath, sizeof(destinationPath), stdin);
                strtok(destinationPath, "\n");  // Remove newline character

                if (backupFile(sourcePath, destinationPath) == 0) {
                    printf("File backed up successfully!\n");
                } else {
                    printf("Failed to backup the file.\n");
                }
                break;
            case 2:
                printf("Exiting the backup system.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== File Backup System ===\n");
    printf("1. Backup a file\n");
    printf("2. Exit\n");
}

int backupFile(const char *source, const char *destination) {
    FILE *sourceFile = fopen(source, "rb");
    if (sourceFile == NULL) {
        return -1;  // Source file could not be opened
    }

    FILE *destinationFile = fopen(destination, "wb");
    if (destinationFile == NULL) {
        fclose(sourceFile);
        return -2;  // Destination file could not be created
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
    return 0;  // Successful backup
}

int checkFileExists(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file) {
        fclose(file);
        return 1;  // File exists
    }
    return 0;  // File does not exist
}