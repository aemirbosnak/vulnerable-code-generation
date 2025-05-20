//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME 100

void writeToFile(const char *fileName) {
    FILE *filePtr = fopen(fileName, "w");
    if (!filePtr) {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter text to write to the file (type 'END' to finish):\n");
    char line[MAX_LINE_LENGTH];

    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);
        
        // Remove newline character from fgets
        line[strcspn(line, "\n")] = 0;
        
        if (strcmp(line, "END") == 0) {
            break;
        }

        fprintf(filePtr, "%s\n", line);
    }

    fclose(filePtr);
    printf("Data written to %s successfully!\n", fileName);
}

void readFromFile(const char *fileName) {
    FILE *filePtr = fopen(fileName, "r");
    if (!filePtr) {
        perror("Error opening file for reading");
        return;
    }

    printf("Contents of %s:\n", fileName);
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), filePtr)) {
        printf("%s", line);
    }

    fclose(filePtr);
}

void appendToFile(const char *fileName) {
    FILE *filePtr = fopen(fileName, "a");
    if (!filePtr) {
        perror("Error opening file for appending");
        return;
    }

    printf("Enter text to append to the file (type 'END' to finish):\n");
    char line[MAX_LINE_LENGTH];
    
    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);
        
        // Remove newline character from fgets
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "END") == 0) {
            break;
        }

        fprintf(filePtr, "%s\n", line);
    }

    fclose(filePtr);
    printf("Data appended to %s successfully!\n", fileName);
}

int main() {
    char fileName[MAX_FILE_NAME];
    int choice;

    printf("Welcome to the File Handling Program in Ada Lovelace style!\n");
    printf("Please enter the name of the file to work with: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0; // Remove newline from file name

    do {
        printf("\nChoose an action:\n");
        printf("1 - Write to file\n");
        printf("2 - Read from file\n");
        printf("3 - Append to file\n");
        printf("4 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf

        switch (choice) {
            case 1:
                writeToFile(fileName);
                break;
            case 2:
                readFromFile(fileName);
                break;
            case 3:
                appendToFile(fileName);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}