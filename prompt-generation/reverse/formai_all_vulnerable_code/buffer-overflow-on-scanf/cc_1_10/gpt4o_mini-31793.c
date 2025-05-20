//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function to read and display the contents of a file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file '%s': %s\n", filename, strerror(errno));
    }

    fclose(file);
}

// Function to write to a file
void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        return;
    }

    if (fputs(content, file) == EOF) {
        fprintf(stderr, "Error writing to file '%s': %s\n", filename, strerror(errno));
    }

    fclose(file);
}

// Function to simulate file operations
void fileOperation(int operation, const char *filename, const char *data) {
    switch (operation) {
        case 1:
            writeFile(filename, data);
            break;
        case 2:
            readFile(filename);
            break;
        default:
            fprintf(stderr, "Invalid operation.\n");
            break;
    }
}

// Main menu display function
void displayMenu() {
    printf("File Management System\n");
    printf("1. Write to file\n");
    printf("2. Read from file\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_BUFFER_SIZE];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter filename to write to: ");
                scanf("%s", filename);
                printf("Enter content to write: ");
                getchar(); // clear newline from buffer
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character
                fileOperation(1, filename, content);
                break;
            case 2:
                printf("Enter filename to read from: ");
                scanf("%s", filename);
                fileOperation(2, filename, NULL);
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                fprintf(stderr, "Invalid choice. Try again.\n");
        }
    }
    return 0;
}