//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define FILENAME "data.txt"

void writeToFile();
void readFromFile();
void displayFileContents();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== File Handling Menu ===\n");
        printf("1. Write to File\n");
        printf("2. Read from File\n");
        printf("3. Display File Contents\n");
        printf("4. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear any extra characters from input buffer

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                displayFileContents();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void writeToFile() {
    FILE *file = fopen(FILENAME, "a");  // Open file in append mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("Enter text to write to file (type 'exit' to stop):\n");
    while (1) {
        fgets(buffer, MAX_LENGTH, stdin);
        if (strcmp(buffer, "exit\n") == 0) break;  // Exit condition
        fputs(buffer, file);
    }

    fclose(file);
    printf("Text written to file successfully.\n");
}

void readFromFile() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("Reading from file:\n");
    while (fgets(buffer, MAX_LENGTH, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void displayFileContents() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("File Contents:\n");
    while (fgets(buffer, MAX_LENGTH, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
}