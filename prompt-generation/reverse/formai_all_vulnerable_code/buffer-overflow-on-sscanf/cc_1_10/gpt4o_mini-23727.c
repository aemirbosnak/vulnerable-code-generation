//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

// Function prototypes
void list_files(const char *path);
void change_directory(const char *path);
void print_file_info(const char *filename);
void menu();
void exit_program();

// Main program
int main() {
    char command[256];
    menu();

    while (1) {
        printf("sysadmin> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            exit_program();
        }

        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        // Determine action
        if (strcmp(command, "exit") == 0) {
            exit_program();
        } else if (strncmp(command, "ls", 2) == 0) {
            char path[256];
            sscanf(command, "ls %s", path);
            list_files(strlen(path) > 0 ? path : ".");
        } else if (strncmp(command, "cd", 2) == 0) {
            char path[256];
            sscanf(command, "cd %s", path);
            change_directory(path);
        } else if (strncmp(command, "info", 4) == 0) {
            char filename[256];
            sscanf(command, "info %s", filename);
            print_file_info(filename);
        } else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
    
    return 0;
}

// Function implementations
void list_files(const char *path) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("Couldn't open directory");
        return;
    }

    printf("Listing files in directory: %s\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void change_directory(const char *path) {
    if (chdir(path) == 0) {
        printf("Changed directory to: %s\n", path);
    } else {
        perror("Failed to change directory");
    }
}

void print_file_info(const char *filename) {
    struct stat fileStat;

    if (stat(filename, &fileStat) < 0) {
        perror("Could not retrieve file info");
        return;
    }

    printf("Information for file: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
}

void menu() {
    printf("Welcome to the simple Linux system admin tool!\n");
    printf("Available commands:\n");
    printf("1. ls [path] - List files in the specified directory (default current directory).\n");
    printf("2. cd [path] - Change current working directory to the specified path.\n");
    printf("3. info [filename] - Show information about the specified file.\n");
    printf("4. exit - Exit the program.\n");
}

void exit_program() {
    printf("Exiting the system admin tool. Goodbye!\n");
    exit(0);
}