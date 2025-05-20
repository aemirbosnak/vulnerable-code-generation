//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    printf("Enter text to write to the file (type 'exit' to finish):\n");
    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        fputs(buffer, file);
    }

    fclose(file);
    printf("Data written to '%s' successfully.\n", filename);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    printf("Contents of '%s':\n", filename);
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
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

void menu() {
    printf("\nFile Handling Menu:\n");
    printf("1. Create a new file\n");
    printf("2. Write to a file\n");
    printf("3. Read a file\n");
    printf("4. Delete a file\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char filename[100];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter the filename to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                createFile(filename);
                break;
            case 2:
                printf("Enter the filename to write to: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                writeFile(filename);
                break;
            case 3:
                printf("Enter the filename to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                readFile(filename);
                break;
            case 4:
                printf("Enter the filename to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                deleteFile(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}