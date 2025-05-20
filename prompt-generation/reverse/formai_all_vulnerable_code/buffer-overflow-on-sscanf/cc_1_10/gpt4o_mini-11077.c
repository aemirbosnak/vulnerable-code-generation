//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Define maximum lengths for file names and paths
#define MAX_FILE_NAME 256
#define MAX_PATH_LENGTH 1024

// Function to create a directory
void create_directory(const char *dir_name) {
    if (mkdir(dir_name, 0755) == -1) {
        perror("Error creating directory");
    } else {
        printf("Directory '%s' created successfully.\n", dir_name);
    }
}

// Function to list files in a directory
void list_files(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Listing files in directory '%s':\n", dir_name);
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] != '.') { // Exclude hidden files
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

// Function to delete a directory
void delete_directory(const char *dir_name) {
    if (rmdir(dir_name) == -1) {
        perror("Error deleting directory");
    } else {
        printf("Directory '%s' deleted successfully.\n", dir_name);
    }
}

// Function to check if a path is a directory
int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to handle user commands
void handle_command(char *command) {
    char cmd[10];
    char arg[MAX_PATH_LENGTH];

    sscanf(command, "%s %s", cmd, arg);
    
    if (strcmp(cmd, "mkdir") == 0) {
        create_directory(arg);
    } else if (strcmp(cmd, "ls") == 0) {
        list_files(arg);
    } else if (strcmp(cmd, "rmdir") == 0) {
        delete_directory(arg);
    } else if (strcmp(cmd, "quit") == 0) {
        exit(0);
    } else {
        printf("Unknown command: '%s'. Available commands: mkdir, ls, rmdir, quit.\n", cmd);
    }
}

// Main function
int main() {
    char command[256];

    printf("Simple C System Administration Tool\n");
    printf("Enter commands to manage directories. Type 'quit' to exit.\n");

    while (1) {
        printf(">>> ");
        if (fgets(command, sizeof(command), stdin) != NULL) {
            // Remove the newline character
            command[strcspn(command, "\n")] = 0;
            handle_command(command);
        } else {
            perror("Error reading input");
        }
    }

    return 0;
}