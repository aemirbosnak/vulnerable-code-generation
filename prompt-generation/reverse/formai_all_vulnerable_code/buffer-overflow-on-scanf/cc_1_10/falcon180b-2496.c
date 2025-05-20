//Falcon-180B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to check if a file exists and is readable
int file_exists(char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        error("File does not exist or cannot be accessed");
    }
    return 0;
}

// Function to read a file and return its contents as a string
char *read_file(char *filename) {
    FILE *file;
    char *content = NULL;
    size_t file_size = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        error("File cannot be opened");
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for file content
    content = malloc(file_size + 1);
    if (content == NULL) {
        error("Memory allocation failed");
    }

    // Read file content
    fread(content, file_size, 1, file);
    content[file_size] = '\0'; // Add null terminator

    fclose(file);
    return content;
}

// Function to write content to a file
int write_file(char *filename, char *content) {
    FILE *file;

    file = fopen(filename, "w");
    if (file == NULL) {
        error("File cannot be opened");
    }

    fwrite(content, strlen(content), 1, file);
    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    char filename[MAX_PATH];
    char *content = NULL;

    // Check if correct number of arguments are provided
    if (argc!= 2) {
        error("Incorrect number of arguments");
    }

    // Copy filename argument to filename variable
    strcpy(filename, argv[1]);

    // Check if file exists and is readable
    file_exists(filename);

    // Read file content
    content = read_file(filename);

    // Print file content to console
    printf("File content:\n%s", content);

    // Ask user if they want to modify the file
    char choice;
    printf("Do you want to modify the file? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Ask user for new content
        printf("Enter new content: ");
        scanf("%s", content);

        // Write new content to file
        write_file(filename, content);
        printf("File modified successfully\n");
    }

    free(content);
    return 0;
}