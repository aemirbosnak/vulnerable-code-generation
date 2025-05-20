//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the input command
void parse_command(char* command, char* argument, char* ebook) {
    // Find the first space to separate the command and argument
    char* space = strchr(command, ' ');

    // If there is a space, separate the command and argument
    if(space != NULL) {
        strncpy(argument, space + 1, strlen(space) - 1);
        *space = '\0';
    }

    // Copy the ebook name
    strcpy(ebook, command);
}

// Function to check if an ebook exists
int ebook_exists(char* ebook) {
    // Check if the file can be opened in read mode
    FILE* file = fopen(ebook, "r");

    // If the file exists, close it and return 1
    if(file != NULL) {
        fclose(file);
        return 1;
    }

    // If the file does not exist, return 0
    return 0;
}

// Function to print an ebook
void print_ebook(char* ebook) {
    // Open the ebook file in read mode
    FILE* file = fopen(ebook, "r");

    // If the file does not exist, print an error message and return
    if(file == NULL) {
        printf("Error: Ebook not found\n");
        return;
    }

    // Print the contents of the ebook
    char ch;
    while(fscanf(file, "%c", &ch) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    fclose(file);
}

int main() {
    char command[50];
    char argument[50];
    char ebook[50];

    while(1) {
        // Print the prompt
        printf("Welcome to the Medieval Ebook Reader!\n");
        printf("Type 'read <ebook name>' to read an ebook or 'quit' to exit: ");

        // Read the user input
        fgets(command, 50, stdin);

        // Remove the newline character from the user input
        char* newline = strchr(command, '\n');
        if(newline != NULL) {
            *newline = '\0';
        }

        // Parse the input command
        parse_command(command, argument, ebook);

        // Execute the command
        if(strcmp(command, "quit") == 0) {
            break;
        } else if(strcmp(command, "read") == 0) {
            int exists = ebook_exists(ebook);
            if(exists) {
                print_ebook(ebook);
            } else {
                printf("Error: Ebook not found\n");
            }
        } else {
            printf("Error: Invalid command\n");
        }

        // Print a blank line for formatting
        printf("\n");
    }

    return 0;
}