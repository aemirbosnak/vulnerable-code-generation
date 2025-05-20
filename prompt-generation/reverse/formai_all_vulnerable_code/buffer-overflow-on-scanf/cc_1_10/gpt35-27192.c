//FormAI DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

// Definition of our puzzle function
void run_puzzle();

int main() {
    printf("Welcome to the C File Backup System Puzzle!\n");
    printf("Can you solve it? Let's find out...\n\n");

    // Run the puzzle function
    run_puzzle();

    printf("\nCongratulations! You solved the C File Backup System Puzzle!\n");
    printf("Here's your reward: \n");

    // Print out a secret code as reward
    printf("2400-9F4B-37BD-4C1E\n");

    return 0;
}

void run_puzzle() {
    // Create an array to hold file names
    char file_names[10][MAX_FILE_NAME_LENGTH];

    printf("Please enter the names of the 10 files that need to be backed up: \n");

    // Prompt user to enter the file names
    for(int i = 0; i < 10; i++) {
        printf("File %d: ", i+1);
        scanf("%s", file_names[i]);
    }

    // Positive reinforcement
    printf("Excellent! Now, let's back up these files...\n");

    // Loop through each file and back them up
    for(int i = 0; i < 10; i++) {
        char command[200];
        sprintf(command, "cp %s %s.bak", file_names[i], file_names[i]);
        system(command);
    }

    // Mix things up by reversing the file names
    for(int i = 0; i < 5; i++) {
        char temp[MAX_FILE_NAME_LENGTH];
        strcpy(temp, file_names[i]);
        strcpy(file_names[i], file_names[9-i]);
        strcpy(file_names[9-i], temp);
    }

    // Prompt user to enter the name of the file to restore
    char file_to_restore[MAX_FILE_NAME_LENGTH];
    printf("Which file would you like to restore? Please enter the name: ");
    scanf("%s", file_to_restore);

    // Check if the file exists and prompt user to try again if not
    int file_found = 0;
    while(file_found == 0) {
        for(int i = 0; i < 10; i++) {
            if(strcmp(file_to_restore, file_names[i]) == 0) {
                file_found = 1;
                break;
            }
        }

        if(file_found == 0) {
            printf("Sorry, the file \"%s\" does not exist. Please try again: ", file_to_restore);
            scanf("%s", file_to_restore);
        }
    }

    // Prompt user to enter the name of the backup file to restore from
    char backup_to_restore_from[MAX_FILE_NAME_LENGTH];
    printf("Great! Now, which backup file would you like to restore from? Please enter the name: ");
    scanf("%s", backup_to_restore_from);

    printf("Restoring \"%s\" from backup file \"%s.bak\"...\n", file_to_restore, backup_to_restore_from);

    // Check if the backup file exists and restore the file if found
    int backup_found = 0;
    for(int i = 0; i < 10; i++) {
        if(strcmp(backup_to_restore_from, file_names[i]) == 0) {
            char command[200];
            sprintf(command, "cp %s.bak %s", backup_to_restore_from, file_to_restore);
            system(command);
            backup_found = 1;
            printf("File \"%s\" has been successfully restored from backup file \"%s.bak\"\n", file_to_restore, backup_to_restore_from);
            break;
        }
    }

    // If backup file not found, display error message
    if(backup_found == 0) {
        printf("Sorry, backup file \"%s.bak\" not found.\n", backup_to_restore_from);
    }
}