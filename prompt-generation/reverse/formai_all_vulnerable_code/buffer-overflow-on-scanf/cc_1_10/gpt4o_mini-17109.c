//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function prototypes
void handleError(const char *message);
void writeToFile(const char *filename, const char *data);
void readFromFile(const char *filename);
void clearFile(const char *filename);
void displayMenu();
void handleUserChoice(int choice);

int main() {
    int choice;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input, please enter a number.");
            // Clear the input buffer
            while(getchar() != '\n');
            continue;
        }
        handleUserChoice(choice);
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- File Operations Menu ---\n");
    printf("1. Write to file\n");
    printf("2. Read from file\n");
    printf("3. Clear file\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void handleUserChoice(int choice) {
    char filename[MAX_LINE_LENGTH];
    char data[MAX_LINE_LENGTH];

    switch (choice) {
        case 1:
            printf("Enter the filename to write to: ");
            scanf("%s", filename);
            printf("Enter the data to write: ");
            getchar(); // Clear newline left by scanf
            fgets(data, MAX_LINE_LENGTH, stdin);
            data[strcspn(data, "\n")] = 0; // Remove newline
            writeToFile(filename, data);
            break;
        case 2:
            printf("Enter the filename to read from: ");
            scanf("%s", filename);
            readFromFile(filename);
            break;
        case 3:
            printf("Enter the filename to clear: ");
            scanf("%s", filename);
            clearFile(filename);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            handleError("Invalid choice! Please select between 1 and 4.");
            break;
    }
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void writeToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a"); // Open file in append mode
    if (file == NULL) {
        handleError("Unable to open file for writing.");
    }
    fprintf(file, "%s\n", data);
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Unable to open file for reading.");
    }

    char line[MAX_LINE_LENGTH];
    printf("Contents of %s:\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open file in write mode (clear contents)
    if (file == NULL) {
        handleError("Unable to open file to clear.");
    }
    fclose(file); // Simply close the file to clear it
    printf("File %s cleared successfully.\n", filename);
}