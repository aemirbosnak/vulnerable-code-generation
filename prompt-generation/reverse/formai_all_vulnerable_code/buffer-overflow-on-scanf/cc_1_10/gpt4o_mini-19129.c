//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define MAX_CONTENT 1024
#define SUCCESS 0
#define FAILURE 1

void writeToFile(const char* filename);
void readFromFile(const char* filename);
void showMenu();

int main() {
    int choice;
    char filename[MAX_FILENAME];

    printf("Welcome to the File Handling Program!\n");
    printf("Please enter the filename to be used: ");
    fgets(filename, MAX_FILENAME, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the newline character

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFromFile(filename);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return SUCCESS;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}

void showMenu() {
    printf("\nMenu:\n");
    printf("1. Write to File\n");
    printf("2. Read from File\n");
    printf("3. Exit\n");
}

void writeToFile(const char* filename) {
    FILE *file = fopen(filename, "a"); // Open the file in append mode
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char content[MAX_CONTENT];
    printf("Enter content to write to the file (end with a period):\n");
    fgets(content, MAX_CONTENT, stdin);
    content[strcspn(content, "\n")] = 0; // Remove the newline character

    // Check for end of input
    if (strcmp(content, ".") == 0) {
        printf("No content entered. Aborting write operation.\n");
    } else {
        fprintf(file, "%s\n", content);
        printf("Content written to file successfully.\n");
    }

    fclose(file);
}

void readFromFile(const char* filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char line[MAX_CONTENT];
    printf("Contents of the file:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}