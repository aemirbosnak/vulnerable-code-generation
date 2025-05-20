//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "example.txt"
#define MAX_BUFFER 256

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void createFile() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        handleError("Failed to create file");
    }

    printf("Enter text to write to the file (type 'exit' to finish):\n");
    char buffer[MAX_BUFFER];
    while (1) {
        fgets(buffer, MAX_BUFFER, stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        fputs(buffer, file);
    }
    fclose(file);
    printf("File created and data written successfully.\n");
}

void readFile() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        handleError("Failed to open file for reading");
    }

    printf("\nContents of the file:\n");
    char buffer[MAX_BUFFER];
    while (fgets(buffer, MAX_BUFFER, file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteFile() {
    if (remove(FILENAME) != 0) {
        handleError("Failed to delete file");
    }
    printf("File deleted successfully.\n");
}

void displayMenu() {
    printf("\nFile Management System\n");
    printf("1. Create a file and write data.\n");
    printf("2. Read the contents of the file.\n");
    printf("3. Delete the file.\n");
    printf("4. Exit.\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input. Please enter a number.");
        }
        
        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
        }
    }

    return 0;
}