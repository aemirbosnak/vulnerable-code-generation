//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function prototypes
void backupFile(const char *source, const char *destination);
void displayMenu();
void clearInputBuffer();

int main() {
    char sourceFile[256];
    char destinationFile[256];
    int choice;

    while (1) {
        displayMenu();

        printf("Please enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the source file path: ");
                clearInputBuffer();
                fgets(sourceFile, sizeof(sourceFile), stdin);
                sourceFile[strcspn(sourceFile, "\n")] = 0;  // Remove newline character

                printf("Enter the destination file path: ");
                fgets(destinationFile, sizeof(destinationFile), stdin);
                destinationFile[strcspn(destinationFile, "\n")] = 0;  // Remove newline character

                backupFile(sourceFile, destinationFile);
                break;
            case 2:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void backupFile(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open source file for reading
    srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open destination file for writing
    destFile = fopen(destination, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return;
    }

    // Begin copying the file in chunks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    printf("Backup completed successfully: %s -> %s\n", source, destination);

    // Close both files
    fclose(srcFile);
    fclose(destFile);
}

void displayMenu() {
    printf("\n=== File Backup System ===\n");
    printf("1. Backup a file\n");
    printf("2. Exit\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}