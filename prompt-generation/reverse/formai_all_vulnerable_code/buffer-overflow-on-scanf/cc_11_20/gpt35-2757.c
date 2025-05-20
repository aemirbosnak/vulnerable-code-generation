//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Surprise! You're in a C File System Simulation!\n");

    // Define variables
    int num_blocks, block_size, user_choice, file_count = 0;
    char** blocks_array;

    // Get user input for number of blocks and block size
    printf("How many blocks would you like in the file system?: ");
    scanf("%d", &num_blocks);

    printf("What should be the size of each block?: ");
    scanf("%d", &block_size);

    // Allocate memory for blocks
    blocks_array = malloc(num_blocks * sizeof(char*));
    for (int i = 0; i < num_blocks; i++) {
        blocks_array[i] = malloc(block_size * sizeof(char));
    }

    // Loop for user to interact with the file system
    while (1) {
        // Display menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. View files\n");
        printf("4. Exit\n");

        // Get user choice
        printf("\nEnter choice: ");
        scanf("%d", &user_choice);

        // Perform action based on user choice
        switch (user_choice) {
            case 1:
                // Create file
                if (file_count >= num_blocks) {
                    printf("Cannot create file. File system full.\n");
                    break;
                }

                // Get file name from user
                char file_name[20];
                printf("Enter file name: ");
                scanf("%s", file_name);

                // Find first empty block and write file name to that block
                for (int i = 0; i < num_blocks; i++) {
                    if (blocks_array[i][0] == '\0') {
                        snprintf(blocks_array[i], block_size, "%s", file_name);
                        printf("File created successfully.\n");
                        file_count++;
                        break;
                    }
                }
                break;
            case 2:
                // Delete file
                if (file_count == 0) {
                    printf("No files to delete.\n");
                    break;
                }

                // Get file name from user
                char file_to_delete[20];
                printf("Enter file name to delete: ");
                scanf("%s", file_to_delete);

                // Find block with file to delete and clear the block
                for (int i = 0; i < num_blocks; i++) {
                    if (strcmp(blocks_array[i], file_to_delete) == 0) {
                        blocks_array[i][0] = '\0';
                        printf("File deleted successfully.\n");
                        file_count--;
                        break;
                    }
                }
                break;
            case 3:
                // View files
                if (file_count == 0) {
                    printf("No files to view.\n");
                    break;
                }

                printf("Files in file system:\n");
                for (int i = 0; i < num_blocks; i++) {
                    if (blocks_array[i][0] != '\0') {
                        printf("%s\n", blocks_array[i]);
                    }
                }
                break;
            case 4:
                // Exit program
                printf("Exiting C File System Simulation. Goodbye!\n");
                return 0;
            default:
                // Invalid user choice
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
}