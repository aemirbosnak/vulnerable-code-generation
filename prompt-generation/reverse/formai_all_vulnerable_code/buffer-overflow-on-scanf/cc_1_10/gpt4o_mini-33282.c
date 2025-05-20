//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to check if a directory exists, if not create it
int create_directory(const char *dir) {
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        if (mkdir(dir, 0700) == -1) {
            perror("Error creating directory");
            return 0;
        }
    }
    return 1;
}

// Function to backup a file
void backup_file(const char *src, const char *dest) {
    FILE *sourceFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    sourceFile = fopen(src, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Create backup file path
    char backupPath[PATH_MAX];
    snprintf(backupPath, sizeof(backupPath), "%s/%s.bak", dest, strrchr(src, '/') ? strrchr(src, '/') + 1 : src);

    destFile = fopen(backupPath, "wb");
    if (destFile == NULL) {
        perror("Error creating backup file");
        fclose(sourceFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("Backup of '%s' created at '%s'\n", src, backupPath);
}

// Function to display the backup menu
void display_menu() {
    printf("\nFile Backup System\n");
    printf("1. Backup a file\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    char sourceFile[PATH_MAX];
    char destinationDir[PATH_MAX];
    int option;

    printf("Welcome to the File Backup System!\n");

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the full path of the source file: ");
                scanf("%s", sourceFile);
                printf("Enter the destination directory for backup: ");
                scanf("%s", destinationDir);

                if (create_directory(destinationDir)) {
                    backup_file(sourceFile, destinationDir);
                }
                break;
            case 2:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}