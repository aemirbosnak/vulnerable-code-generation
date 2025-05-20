//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH_LEN 256
#define MAX_CMD_LEN 512

// Function to list files in a directory
void listFiles(const char *path) {
    DIR *directory;
    struct dirent *entry;

    directory = opendir(path);
    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Files in directory '%s':\n", path);
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(directory);
}

// Function to create a directory
void createDirectory(const char *path) {
    if (mkdir(path, 0755) == -1) {
        perror("Error creating directory");
    } else {
        printf("Directory '%s' created successfully.\n", path);
    }
}

// Function to delete a directory
void deleteDirectory(const char *path) {
    if (rmdir(path) == -1) {
        perror("Error deleting directory");
    } else {
        printf("Directory '%s' deleted successfully.\n", path);
    }
}

// Function to copy a file
void copyFile(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char buffer[1024];
    size_t bytesRead;

    srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Source file not found");
        return;
    }

    destFile = fopen(destination, "wb");
    if (destFile == NULL) {
        perror("Error creating destination file");
        fclose(srcFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("File copied from '%s' to '%s' successfully.\n", source, destination);
}

// Function to display help
void displayHelp() {
    printf("Simple System Administration Tool\n");
    printf("Usage:\n");
    printf("  1. list <directory>       : List all files in the given directory\n");
    printf("  2. mkdir <directory>      : Create a new directory\n");
    printf("  3. rmdir <directory>      : Remove a directory\n");
    printf("  4. cp <source> <dest>     : Copy a file\n");
    printf("  5. exit                   : Exit the program\n");
}

// Main function to process user commands
int main() {
    char command[MAX_CMD_LEN];
    char arg1[MAX_PATH_LEN], arg2[MAX_PATH_LEN];

    displayHelp();

    while (1) {
        printf("\n> ");
        if (fgets(command, sizeof(command), stdin) != NULL) {
            // Remove trailing newline character
            command[strcspn(command, "\n")] = 0;

            // Parse command
            if (sscanf(command, "list %s", arg1) == 1) {
                listFiles(arg1);
            } else if (sscanf(command, "mkdir %s", arg1) == 1) {
                createDirectory(arg1);
            } else if (sscanf(command, "rmdir %s", arg1) == 1) {
                deleteDirectory(arg1);
            } else if (sscanf(command, "cp %s %s", arg1, arg2) == 2) {
                copyFile(arg1, arg2);
            } else if (strcmp(command, "exit") == 0) {
                printf("Exiting the program...\n");
                break;
            } else {
                printf("Invalid command. Type 'help' for a list of commands.\n");
            }
        } else {
            perror("Error reading command");
        }
    }

    return 0;
}