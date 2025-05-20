//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define BUFFER_SIZE 256

void createFile(const char *filename);
void readFile(const char *filename);
void deleteFile(const char *filename);
void displayMenu();

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the invalid input
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n----- File Handling Menu -----\n");
    printf("1. Create a new file\n");
    printf("2. Read a file\n");
    printf("3. Delete a file\n");
    printf("4. Exit\n");
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }

    printf("Enter text to write to the file (type 'exit' to stop):\n");
    char buffer[BUFFER_SIZE];
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        // Strip new line character from input
        buffer[strcspn(buffer, "\n")] = 0;
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        fprintf(file, "%s\n", buffer);
    }

    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error reading file");
        return;
    }

    printf("Contents of the file '%s':\n", filename);
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
}