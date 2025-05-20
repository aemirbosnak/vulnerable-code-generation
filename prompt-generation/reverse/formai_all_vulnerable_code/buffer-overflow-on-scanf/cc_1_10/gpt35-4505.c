//FormAI DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to the Wacky File System Simulation!\n\n");
    printf("Instructions:\n");
    printf("1. Type 'ls' to display the current directory.\n");
    printf("2. Type 'cd [directory name]' to change your current directory.\n");
    printf("3. Type 'mkdir [directory name]' to create a new directory.\n");
    printf("4. Type 'touch [file name]' to create a new file.\n");
    printf("5. Type 'rm [file/directory name]' to remove a file or directory.\n");
    printf("6. Type 'exit' to quit the program.\n\n");

    // Initializing the root directory
    char current_directory[] = "/";
    printf("Current Directory: %s\n", current_directory);

    while (1) {
        printf(">> ");
        char input[50];
        scanf("%s", input);

        // User exits the program
        if (strcmp(input, "exit") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        }
        // User wants to view current directory
        else if (strcmp(input, "ls") == 0) {
            printf("\nCurrent Directory: %s\n", current_directory);
            printf("FILES:\n");
            // Add code to display all files in current directory
        }
        // User wants to change directory
        else if (strcmp(input, "cd") == 0) {
            char new_directory[50];
            scanf("%s", new_directory);
            printf("\nChanging directory to %s\n", new_directory);
            // Add code to change the current directory
        }
        // User wants to create a new directory
        else if (strcmp(input, "mkdir") == 0) {
            char new_directory[50];
            scanf("%s", new_directory);
            printf("\nCreating new directory %s\n", new_directory);
            // Add code to create a new directory in current directory
        }
        // User wants to create a new file
        else if (strcmp(input, "touch") == 0) {
            char new_file[50];
            scanf("%s", new_file);
            printf("\nCreating new file %s\n", new_file);
            // Add code to create a new file in current directory
        }
        // User wants to remove a file/directory
        else if (strcmp(input, "rm") == 0) {
            char file_to_remove[50];
            scanf("%s", file_to_remove);
            printf("\nRemoving %s\n", file_to_remove);
            // Add code to remove file/directory
        }
        // Invalid input
        else {
            printf("\nInvalid input, please try again.\n");
        }
    }

    return 0;
}