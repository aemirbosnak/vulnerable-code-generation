//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock Holmes's file system simulator
int main() {
    // Initialize the file system
    char *files[100];
    int file_sizes[100];
    int num_files = 0;

    // Get the user's input
    char input[100];
    while (1) {
        printf("What would you like to do, Mr. Holmes? ");
        gets(input);

        // Parse the user's input
        char *command = strtok(input, " ");
        char *arg1 = strtok(NULL, " ");
        char *arg2 = strtok(NULL, " ");

        // Execute the command
        if (strcmp(command, "add") == 0) {
            // Add a file to the file system
            files[num_files] = malloc(strlen(arg1) + 1);
            strcpy(files[num_files], arg1);
            file_sizes[num_files] = atoi(arg2);
            num_files++;
        } else if (strcmp(command, "delete") == 0) {
            // Delete a file from the file system
            int i;
            for (i = 0; i < num_files; i++) {
                if (strcmp(files[i], arg1) == 0) {
                    free(files[i]);
                    for (int j = i; j < num_files - 1; j++) {
                        files[j] = files[j + 1];
                        file_sizes[j] = file_sizes[j + 1];
                    }
                    num_files--;
                    break;
                }
            }
        } else if (strcmp(command, "list") == 0) {
            // List the files in the file system
            for (int i = 0; i < num_files; i++) {
                printf("%s (%d bytes)\n", files[i], file_sizes[i]);
            }
        } else if (strcmp(command, "quit") == 0) {
            // Quit the program
            break;
        } else {
            // Invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i]);
    }

    return 0;
}